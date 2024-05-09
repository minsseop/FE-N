#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
using namespace std;

int main(int argc, int i, char**argv)
{   i = 0;
    ros::init(argc, argv, "my_node");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate loop_rate(1);

    
     geometry_msgs::Twist msg1;

     msg1.linear.x = 2.0;
     msg1.linear.y = 0.0;
     msg1.linear.z = 0.0;
     msg1.angular.x = 0.0;
     msg1.angular.y = 0.0;
     msg1.angular.z = 1.575;

     geometry_msgs::Twist msg2;

     msg2.linear.x = 2.0;
     msg2.linear.y = 0.0;
     msg2.linear.z = 0.0;
     msg2.angular.x = 0.0;
     msg2.angular.y = 0.0;
     msg2.angular.z = -1.575;
     

     while(ros::ok()){
        while(i<5){
            pub.publish(msg1);
            ros::spinOnce();
            loop_rate.sleep();
            sleep(1);
            i = i + 1;

        }
        while( 4 < i && i < 9){
            pub.publish(msg2);
            ros::spinOnce();
            loop_rate.sleep();
            sleep(1);
            i = i + 1;

         }

        
        }

        return 0;
}
