#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ros/ros.h>
#include <Load_Balancer/Load_Balancer.h>
#include "Load_Balancer/LD_data.h"
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
  ros::Publisher LD_pub = nh.advertise<Load_Balancer::LD_data>("LD_data_msg",100);
  Load_Balancer::LD_data msg;
  int count=0;

  while(ros::ok())
  {
    msg.id=count%4+1;
    msg.stamp=ros::Time::now();
    msg.data=count;

    ROS_INFO("%d :: send msg = %d (%d.%d)",msg.id, msg.data, msg.stamp.sec, msg.stamp.nsec);
    LD_pub.publish(msg);
    +count;
  }
  
  return EXIT_SUCCESS;
}
