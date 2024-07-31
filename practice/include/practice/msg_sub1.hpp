#ifndef MSGSUBSCRIBER1_HPP
#define MSGSUBSCRIBER1_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>


using namespace std;
using namespace std::chrono_literals;



class MsgSubscriber1 : public rclcpp::Node
{
public:
    MsgSubscriber1();


private:

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _sub;

    void sub1_msg(const std_msgs::msg::String::SharedPtr msg);

};




#endif