#include "ros/ros.h"
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>

class ros_interface
{

private:
    ros::Publisher pub_;
    ros::Subscriber sub_1, sub_2;



public:
    //void getVelocityCallback(const std_msgs::Float32::ConstPtr& velocity);
    //void getErrorCallback(const std_msgs::Float32MultiArray::ConstPtr& error);
    void execute_ros();
    void init_ros();
    void deinit_ros();
    float vel;
    float arr[2];

};