#include "rosInterface.h"
#include "stanley.h"
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>

ros_interface myRos;
stanleyController stanley;

void getVelocityCallback(const std_msgs::Float32::ConstPtr& velocity)
{   
    myRos.vel = velocity->data;
    ROS_INFO("I heard: [%f]", velocity->data);
}

void getErrorCallback(const std_msgs::Float32MultiArray::ConstPtr& error)
{
    myRos.arr[0] = error->data.at(0);
    myRos.arr[1] = error->data.at(1);
    ROS_INFO("I heard: [%f], [%f]", error->data.at(0),error->data.at(1));
}


void ros_interface::execute_ros()
{
ros::NodeHandle n;
ros::Subscriber sub1 = n.subscribe("vehicle_status", 1000, getVelocityCallback);
ros::Subscriber sub2 = n.subscribe("desired_set_points", 1000, getErrorCallback);
ros::Publisher pub1 = n.advertise<std_msgs::Float32>("desired_control", 1000);
ros::Rate loop_rate(20);

    while(ros::ok())
    {

        std_msgs::Float32 steering;
        ros::Rate loop_rate(20);

        stanley.setInputError(myRos.arr[0], myRos.arr[1]);
        stanley.setInputVelocity(myRos.vel);
        stanley.execute();

        steering.data = stanley.getOutput();
        ROS_INFO("%f", steering.data);
        pub1.publish(steering);


        ros::spinOnce();
        loop_rate.sleep();
    }
}