#include "ros/ros.h"
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>
#include "stanley.h"

class rosInterface
{

private:

    ros::NodeHandle &n;
    ros::Publisher pub_1;
    ros::Subscriber sub_1, sub_2;
    stanleyController stanley;
    float vel;
    float arr[2];
    void getVelocityCallback(const std_msgs::Float32::ConstPtr& velocity);
    void getErrorCallback(const std_msgs::Float32MultiArray::ConstPtr& error);
  



public:

    void execute_ros();
    void init_ros();
 

    rosInterface(ros::NodeHandle &n); 
    
    

};