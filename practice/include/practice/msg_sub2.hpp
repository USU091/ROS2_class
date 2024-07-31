#ifndef MSGSUBSCRIBER2_HPP
#define MSGSUBSCRIBER2_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>


using namespace std;
using namespace std::chrono_literals;



class MsgSubscriber2 : public rclcpp::Node
{
public:
    MsgSubscriber2();


private:

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _sub;

    void sub2_msg(const std_msgs::msg::String::SharedPtr msg);

};




#endif