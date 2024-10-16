#include "ros/ros.h"
#include "std_msgs/String.h"

void callback(const std_msgs::String::ConstPtr& msg) {
    std::string str = msg->data;
    std::cout<<"faccio qualcosa con "<<str<<std::endl;
}

int main(int argc, char** argv) {
    std::cout<<"Maddalena1"<<std::endl;
    ros::init(argc, argv, "subscriber");
    std::cout<<"Maddalena2"<<std::endl;
    ros::NodeHandle nh;
    std::cout<<"Maddalena3"<<std::endl;

    std::string topic;
    nh.getParam("/subscriber/topic", topic);

    int queue_size = 10;
    ros::Subscriber sub = nh.subscribe(topic, queue_size, callback);

    ros::spin();

    return 0;
}
