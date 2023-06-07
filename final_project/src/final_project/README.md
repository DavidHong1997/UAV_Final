# Final Project

Implementation Issue:
https://hackmd.io/@ncrl-10/SkwUc5QH9

The packages for 2022-AerialRobotics Final Project.

1. Rotor_simulator : UAV simulation using Geometric Controller

2. Husky : Ground Vehicle for assisting UAV challenge
    - Navigation
    - Localization
    - SLAM

3. Apriltag : For localization



# Requirements
* Ubuntu 20.04 ros-melodic
* gazebo greater than 9.0

```
sudo apt-get install ros-noetic-joy ros-noetic-octomap-ros ros-noetic-mavlink  python3-wstool python3-catkin-tools protobuf-compiler libgoogle-glog-dev ros-noetic-control-toolbox
sudo apt-get install python3-cvxopt
```
# Additional package

## Rotor_simulator
This is a Gazebo simulation package for ros 20.04. The package is migrated from the [rotorS](https://github.com/ethz-asl/rotors_simulator).
```
sudo apt-get install ros-noetic-ompl
sudo apt-get install ros-noetic-mavros
sudo apt-get install ros-noetic-mavros-extras 
sudo apt-get install ros-noetic-mavros-msgs
sudo apt-get install ros-noetic-rm-msgs
sudo apt-get install libompl-dev
sudo apt install libgoogle-glog-dev 

cd /opt/ros/noetic/lib/mavros
sudo ./install_geographiclib_datasets.sh
```

# Running

## Setup

if you don't have one, try to review ros architecture  and create one
```
cd
mkdir -p final_project/src
cd ~/final_project_ws/src
git clone https://github.com/ethz-asl/mav_comm.git
git clone https://github.com/2022-Robotics-Aerial-Robots/final_project.git
cd ~/final_project
```

it will take about 2-5 minutes for first time
```
catkin_make
```
Remember if you cannot find launch file or node file, execute this command! 
```
source ~/catkin_ws/devel/setup.bash
```

Run the following command to make sure the gazebo simulation is installed correctly
```
roslaunch rotors_gazebo mav_hovering_example.launch
```
