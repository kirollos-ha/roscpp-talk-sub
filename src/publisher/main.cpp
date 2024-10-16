#include<iostream>

#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char** argv) {
    std::cout<<"Madonna1"<<std::endl;
    ros::init(argc, argv, "publisher");
    std::cout<<"Madonna2"<<std::endl;
    ros::NodeHandle nh;
    std::cout<<"Madonna3"<<std::endl;

    std::cout<<"Madonna"<<std::endl;
    std::string topic;
    nh.getParam("/publisher/topic", topic);
    std::cout<<"Madonna"<<std::endl;

    int queue_size = 10;
    ros::Publisher pub = nh.advertise<std_msgs::String>(topic, 10);
    std::cout<<"Madonna"<<std::endl;

    ros::Rate rate(10); // 10 hertz
    std::cout<<"Madonna"<<std::endl;

    while(ros::ok()) {
        std_msgs::String messaggio;
        messaggio.data = "<roba inviata>";
        std::cout<<"Signore"<<std::endl;

        ROS_INFO("%s", messaggio.data.c_str());
        pub.publish(messaggio);
        std::cout<<"Maddalena"<<std::endl;

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
	

				     
