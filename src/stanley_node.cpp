#include "stanley.h"
#include "rosInterface.h"
//#include "ros/ros.h"



/*
float vel;
float arr[2];

void getVelocityCallback(const std_msgs::Float32::ConstPtr& velocity)
{   
    vel = velocity->data;
    ROS_INFO("I heard: [%f]", velocity->data);
}

void getErrorCallback(const std_msgs::Float32MultiArray::ConstPtr& error)
{
    arr[0] = error->data.at(0);
    arr[1] = error->data.at(1);
    ROS_INFO("I heard: [%f], [%f]", error->data.at(0),error->data.at(1));
}
*/

int main(int argc, char **argv) 
{
   
    stanleyController stanley;
    ros_interface myRos;

    ros::init(argc, argv, "Stanley_Controller_Node");
    //myRos.init_ros();
    myRos.execute_ros();

    /*
    ros::init(argc, argv, "Stanley_Contoller_Node");  
    ros::NodeHandle n;
    ros::Subscriber sub1 = n.subscribe("vehicle_status", 1000, getVelocityCallback);
    ros::Subscriber sub2 = n.subscribe("desired_set_points", 1000, getErrorCallback);
    ros::Publisher pub1 = n.advertise<std_msgs::Float32>("desired_control", 1000);
    ros::Rate loop_rate(20); 
    */
    

    /*
    while (ros::ok())
    {
        std_msgs::Float32 steering;
        
        stanley.setInputError(arr[0], arr[1]);
        stanley.setInputVelocity(vel);
        stanley.execute();


        steering.data = stanley.getOutput();
        ROS_INFO("%f", steering.data);
        pub1.publish(steering);


        ros::spinOnce();
        loop_rate.sleep();


    }
    */



    return 0;
}

