
#ifndef MSGPUBLISHCLASS_HPP  
#define MSGPUBLISHCLASS_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>


using namespace std;
using namespace std::chrono_literals;



class MsgPublishClass : public rclcpp::Node
{
public:
    MsgPublishClass();


private:
    int _i;
  
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _pub1;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _pub2;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _pub3;
    rclcpp::TimerBase::SharedPtr _timer;
    void pub_msg();

};




#endif