#include "rosInterface.h"
#include "stanley.h"
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>


void rosInterface::getVelocityCallback(const std_msgs::Float32::ConstPtr& velocity)
{   
    vel = velocity->data;
    ROS_INFO("I heard: [%f]", velocity->data);
}

void rosInterface::getErrorCallback(const std_msgs::Float32MultiArray::ConstPtr& error)
{
    arr[0] = error->data.at(0);
    arr[1] = error->data.at(1);
    ROS_INFO("I heard: [%f], [%f]", error->data.at(0),error->data.at(1));
}


void rosInterface::init_ros()
{
    sub_1 = n.subscribe("vehicle_status", 1000, &rosInterface::getVelocityCallback, this);
    sub_2 = n.subscribe("desired_set_points", 1000, &rosInterface::getErrorCallback, this);
    pub_1 = n.advertise<std_msgs::Float32>("desired_control", 1000);
}


rosInterface::rosInterface(ros::NodeHandle &n): n(n)
{
    
}

void rosInterface::execute_ros()
{

    ros::Rate loop_rate(20);

    while(ros::ok())
    {

        std_msgs::Float32 steering;

        stanley.setInputError(arr[0], arr[1]);
        stanley.setInputVelocity(vel);
        stanley.execute();

        steering.data = stanley.getOutput();
        ROS_INFO("%f", steering.data);
        pub_1.publish(steering);


        ros::spinOnce();
        loop_rate.sleep();
    }
}