#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ros/ros.h>
#include <load_balancer/load_balancer.h>
#include "msgs/LD_data.h"
/*namespace Load_Balancer {

class LoadControlNode
{
  public:
    ros::NodeHandle nh_;
};

}*/

int main(int argc, char **argv)
{
  ros::init(argc,argv,"Load_Balancer");
  ROS_INFO("Load_Balancer Start");
  ros::NodeHandle nh;
  ros::Publisher LD_pub = nh.advertise<msg>("LD_data_msg",100);

  return EXIT_SUCCESS;
}
