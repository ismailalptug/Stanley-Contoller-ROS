#include "stanley.h"
#include "rosInterface.h"



int main(int argc, char **argv) 
{
    ros::init(argc, argv, "Stanley_Controller_Node");

    
    ros::NodeHandle n;
    rosInterface myRos(n);

    myRos.init_ros();
    myRos.execute_ros();




    return 0;
}

