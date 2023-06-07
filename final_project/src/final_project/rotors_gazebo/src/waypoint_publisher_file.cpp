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
#include <cmath>

#include <Eigen/Geometry>
#include <mav_msgs/conversions.h>
#include <mav_msgs/default_topics.h>
#include <mav_msgs/eigen_mav_msgs.h>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <trajectory_msgs/MultiDOFJointTrajectory.h>

#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <vector>
#include <tf/transform_datatypes.h>

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

class QPWaypointPath {
public:
    QPWaypointPath(){
        imu_sub = nh.subscribe("imu", 10, &QPWaypointPath::callback, this);
        path_sub = nh.subscribe("/qp_path", 10, &QPWaypointPath::pathcallback, this);
        wp_pub =
            nh.advertise<trajectory_msgs::MultiDOFJointTrajectory>(
            mav_msgs::default_topics::COMMAND_TRAJECTORY, 10);

        ROS_INFO("Wait for simulation to become ready...");
        while (!sim_running && ros::ok()) {
            ros::spinOnce();
            ros::Duration(0.1).sleep();
        }

        ROS_INFO("...ok");

        // Wait for 30s such that everything can settle and the mav flies to the initial position.
        ros::Duration(10).sleep();

        ROS_INFO("Start publishing waypoints.");

    };

    void callback(const sensor_msgs::ImuPtr& msg) {
        tf::Quaternion q(msg->orientation.x,
                         msg->orientation.y,
                         msg->orientation.z,
                         msg->orientation.w);
        tf::Matrix3x3 m(q);
        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw);
        //ROS_INFO("roll = %f , pitch = %f, yaw = %f", roll, pitch, yaw);
        init_yaw = yaw;
        sim_running = true;
    };

    /* Publish QP trajectoy */
    void traj_pub(std::vector<WaypointWithTime>& waypoints){
        trajectory_msgs::MultiDOFJointTrajectoryPtr msg_traj(new trajectory_msgs::MultiDOFJointTrajectory);
        msg_traj->header.stamp = ros::Time::now();
        msg_traj->points.resize(waypoints.size());
        msg_traj->joint_names.push_back("base_link");
        int64_t time_from_start_ns = 0;
        for (size_t i = 0; i < waypoints.size(); ++i) {
            WaypointWithTime& wp = waypoints[i];

            mav_msgs::EigenTrajectoryPoint trajectory_point;
            trajectory_point.position_W = wp.position;
            trajectory_point.setFromYaw(wp.yaw);
            trajectory_point.time_from_start_ns = time_from_start_ns;

            time_from_start_ns += static_cast<int64_t>(wp.waiting_time * kNanoSecondsInSecond);

            mav_msgs::msgMultiDofJointTrajectoryPointFromEigen(trajectory_point, &msg_traj->points[i]);
        }
        wp_pub.publish(msg_traj);
        ROS_INFO("Successful poblish to node!");
    };


    void pathcallback(const nav_msgs::Path::ConstPtr& msg){
        std::vector<geometry_msgs::PoseStamped> data = msg->poses;
        std::vector<geometry_msgs::PoseStamped>::const_iterator it = data.begin();
        std::vector<WaypointWithTime> waypoints;
        geometry_msgs::PoseStamped temp;
        //const float DEG_2_RAD = M_PI / 180.0;
        /* store waypoint vector*/
        for(it; it != data.end(); it++){
           if(it == data.begin()){
                waypoints.push_back(WaypointWithTime(                  0.03,   // Time 
                                                        it->pose.position.x,   // x
                                                        it->pose.position.y,   // y
                                                        it->pose.position.z,   // z
                                                                 init_yaw));   // 0
                temp.pose.position = it->pose.position;
            } else {
                double dx = it->pose.position.x - temp.pose.position.x;
                double dy = it->pose.position.y - temp.pose.position.y;               
                double theta = std::atan2(dy, dx);
                   
                // ROS_INFO("heading %f", theta);
                waypoints.push_back(WaypointWithTime(                  0.03,   // Time 
                                                        it->pose.position.x,   // x
                                                        it->pose.position.y,   // y
                                                        it->pose.position.z,   // z
                                                                     theta));  // 
                temp.pose.position = it->pose.position;
            }
        
        }
        // Publish traj
        traj_pub(waypoints);
    };
private:
    ros::NodeHandle nh;
    ros::Subscriber imu_sub;
    ros::Subscriber path_sub;
    ros::Publisher wp_pub;
    bool sim_running = false;
    bool path_generate = false;
    const int64_t kNanoSecondsInSecond = 1000000000;
    double init_yaw;
};



int main(int argc, char** argv) {
  ros::init(argc, argv, "waypoint_publisher");
  ROS_INFO("Started waypoint_publisher.");
  QPWaypointPath QPObject;
  ros::spin();
  return 0;
}
