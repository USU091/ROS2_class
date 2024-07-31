#ifndef SUBSCRIBER_HPP
#define SUBSCRIBER_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>


using namespace std;
using namespace std::chrono_literals;



class HelloSubscriberClass : public rclcpp::Node
{
public:
    HelloSubscriberClass();


private:

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _sub;

    void sub_helloworld_msg(const std_msgs::msg::String::SharedPtr msg);

};




#endif