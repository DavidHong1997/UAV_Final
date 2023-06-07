#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <qptrajectory.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <vector>

class QPPathGenerate
{
public:
    QPPathGenerate()
    {
        qp_pub = nh.advertise<nav_msgs::Path>("/qp_path", 1);
        warpoint_sub = nh.subscribe("/waypoints", 
                                    5000, 
                                    &QPPathGenerate::waypointCallback,
                                    this);
    };

    void waypoint_pub(std::vector<trajectory_profile>& qp_path){
        nav_msgs::Path data_pub;
        data_pub.header.frame_id = "world";
        data_pub.header.stamp = ros::Time::now();
        for(int i = 0; i < qp_path.size(); i++){
            geometry_msgs::PoseStamped qp_point;
            qp_point.pose.position.x = qp_path[i].pos[0];
            qp_point.pose.position.y = qp_path[i].pos[1];
            qp_point.pose.position.z = 1; // set default hight
            data_pub.poses.push_back(qp_point);
        }
        qp_pub.publish(data_pub);
    };

    void waypointCallback(const nav_msgs::Path::ConstPtr& msg){
        std::vector<geometry_msgs::PoseStamped> data = msg->poses;   
        std::vector<geometry_msgs::PoseStamped>::const_iterator it = data.begin();
        /* QP trajectory data */ 
        qptrajectory plan;
        path_def path;
        std::vector<trajectory_profile> path_data;
        std::vector<trajectory_profile> path_new;
        /* pop out raw path data */
        for(it; it != data.end(); it++){
            geometry_msgs::Point pos;
            pos.x = it->pose.position.x;
            pos.y = it->pose.position.y;
            pos.z = it->pose.position.z;
            //ROS_INFO("x = %f, y = %f z = %f", pos.x , pos.y, pos.z);
            /* push in path data*/
            trajectory_profile tmp;
            tmp.pos.x() = pos.x;
            tmp.pos.y() = pos.y;
            tmp.pos.z() = pos.z; // Modify to const
            tmp.vel << 0,0,0;
            tmp.acc << 0,0,0;
            path_data.push_back(tmp);
        }
        ROS_INFO("Take waypoint data!");
        /* QP path generate */
        int setpoint = path_data.size();
        const int t = 1; /* set const interval time */
        double sample = 0.01;
        double max;
        ROS_INFO("Totoal setpoint : %d", setpoint);
        /* push to new generat path */
        for(int i = 0; i < setpoint - 1; i++){
            path.push_back(segments(path_data[i], path_data[i+1], t));
        }
        path_new = plan.get_profile(path, path.size(), sample);
        max = path_new.size();
        ROS_INFO("New path point total : %f", max);
        
        /* pub waypoint */
        waypoint_pub(path_new);
    };

private:
    ros::NodeHandle nh;
    ros::Publisher qp_pub;
    ros::Subscriber warpoint_sub;
};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "qptest"); 
    std::cout << "Trajectory generator"<<std::endl;
    QPPathGenerate QPObject;
    ros::spin();

};
