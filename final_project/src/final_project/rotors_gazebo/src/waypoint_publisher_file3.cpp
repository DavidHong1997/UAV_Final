/*
 * Copyright 2015 Fadri Furrer, ASL, ETH Zurich, Switzerland
 * Copyright 2015 Michael Burri, ASL, ETH Zurich, Switzerland
 * Copyright 2015 Mina Kamel, ASL, ETH Zurich, Switzerland
 * Copyright 2015 Janosch Nikolic, ASL, ETH Zurich, Switzerland
 * Copyright 2015 Markus Achtelik, ASL, ETH Zurich, Switzerland
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fstream>
#include <iostream>

#include <Eigen/Geometry>
#include <mav_msgs/conversions.h>
#include <mav_msgs/default_topics.h>
#include <mav_msgs/eigen_mav_msgs.h>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <trajectory_msgs/MultiDOFJointTrajectory.h>
#include <tf/transform_datatypes.h>
#include <geometry_msgs/PointStamped.h>
#include <eigen3/Eigen/Dense>

class WaypointWithTime {
 public:
  WaypointWithTime()
      : waiting_time(0), yaw(0.0) {
  }

  WaypointWithTime(double t, float x, float y, float z, float _yaw)
      : position(x, y, z), yaw(_yaw), waiting_time(t) {
  }

  Eigen::Vector3d position;
  double yaw;
  double waiting_time;
};

class MultiFirefly {
public:
  MultiFirefly(){
    sub_imu = nh.subscribe("/firefly/imu", 1000, &MultiFirefly::imu_callback, this); // subscribe host firefly imu data
    sub_odom = nh.subscribe("/firefly/odometry_sensor1/position", 100, &MultiFirefly::odom_callback, this); // subscribe host firefly odom data
    wp_pub = nh.advertise<trajectory_msgs::MultiDOFJointTrajectory>(mav_msgs::default_topics::COMMAND_TRAJECTORY, 1000);
    follower_goal.x = -1;
    follower_goal.y =  1;

    while (!sim_running && ros::ok()) {
      ros::spinOnce();
      ros::Duration(0.1).sleep();
    }
    ROS_INFO("...ok");
    // Wait for 30s such that everything can settle and the mav flies to the initial position.
    ros::Duration(10).sleep();
  }

  geometry_msgs::Point LeadertoFollower(geometry_msgs::Point &follower_goal, geometry_msgs::Point &leader_point, double &leader_theta){
    float temp_x = follower_goal.x;
    float temp_y = follower_goal.y;
    geometry_msgs::Point follower_res;
    Eigen::Quaterniond q(cos(leader_theta/2), 0, 0, sin(leader_theta/2));
    Eigen::Quaterniond q_normalized(q.w()/q.norm(), q.x()/q.norm(), q.y()/q.norm(), q.z()/q.norm());
    Eigen::Quaterniond v(0, temp_x, temp_y, 0);
    Eigen::Quaterniond v_new = q_normalized * v * q_normalized.inverse();
    follower_res.x = leader_point.x + v_new.x();
    follower_res.y = leader_point.y + v_new.y();
    return follower_res;
  }

  void follower_path(std::vector<WaypointWithTime> &waypoints){
    trajectory_msgs::MultiDOFJointTrajectoryPtr msg(new trajectory_msgs::MultiDOFJointTrajectory);
    msg->header.stamp = ros::Time::now();
    msg->points.resize(waypoints.size());
    msg->joint_names.push_back("base_link");
    for (size_t i = 0; i < waypoints.size(); ++i) {
      WaypointWithTime& wp = waypoints[i];

      mav_msgs::EigenTrajectoryPoint trajectory_point;
      trajectory_point.position_W = wp.position;
      trajectory_point.setFromYaw(wp.yaw);
      trajectory_point.time_from_start_ns = time_from_start_ns;

      time_from_start_ns += static_cast<int64_t>(wp.waiting_time * kNanoSecondsInSecond);

      mav_msgs::msgMultiDofJointTrajectoryPointFromEigen(trajectory_point, &msg->points[i]);
    }
    wp_pub.publish(msg);
  }

  void imu_callback(const sensor_msgs::ImuPtr& msg) {
    tf::Quaternion q(msg->orientation.x,
                     msg->orientation.y,
                     msg->orientation.z,
                     msg->orientation.w);
    tf::Matrix3x3 m(q);
    double roll,pitch,yaw;
    m.getRPY(roll,pitch,yaw);
    host_yaw = yaw;
    sim_running = true;
    //ROS_INFO("yaw : %f", yaw);
  }

  void odom_callback(const geometry_msgs::PointStamped::ConstPtr &msg) {
    //ROS_INFO("x = %f y = %f z = %f", msg->point.x, msg->point.y, msg->point.z);
    //publsih follower path
    leader_point.x = msg->point.x;
    leader_point.y = msg->point.y;
    leader_point.z = msg->point.z;
    if(sim_running){
      geometry_msgs::Point goal;
      goal = LeadertoFollower(follower_goal, leader_point, host_yaw);
      waypoints.push_back(WaypointWithTime(0.0, goal.x, goal.y, msg->point.z, host_yaw));
    }
    //ROS_INFO("waypoints size: %ld", waypoints.size());
    if(cnt > 10){
      follower_path(waypoints);
      waypoints.clear();
      cnt = 1;
    }
    cnt++;
  }

private:
  bool sim_running = false;
  int64_t time_from_start_ns = 0;
  static const int64_t kNanoSecondsInSecond = 1000000000;
  ros::NodeHandle nh;
  ros::Subscriber sub_imu;
  ros::Subscriber sub_odom;
  ros::Publisher wp_pub;
  std::vector<WaypointWithTime> waypoints;
  int cnt = 1;
  double host_yaw;
  geometry_msgs::Point leader_point;
  geometry_msgs::Point follower_goal;
  geometry_msgs::Twist follower_twist;
};

int main(int argc, char** argv) {
  ros::init(argc, argv, "waypoint_publisher");
  ROS_INFO("Follower_path to host");
  MultiFirefly Follower;
  ros::spin();
  return 0;
}
