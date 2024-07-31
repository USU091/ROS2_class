#ifndef TIMESUBSCRIBER_HPP
#define TIMESUBSCRIBER_HPP


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/header.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

class TimeSubscriber : public rclcpp::Node
{
public:

    TimeSubscriber();


private:
    
    rclcpp::Subscription<std_msgs::msg::Header>::SharedPtr _timesub;

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _msgsub;
    

    void subscribe_time_msg(const std_msgs::msg::Header::SharedPtr msg);

    void subscribe_msg_msg(const std_msgs::msg::String::SharedPtr msg);
};


#endif