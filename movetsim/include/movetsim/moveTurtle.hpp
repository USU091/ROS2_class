#ifndef MOVETURTLE_HPP
#define MOVETURTLE_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include <iostream>


using namespace std;
using namespace std::chrono_literals;


class MoveTurtlesim : public rclcpp::Node
{
public:
    MoveTurtlesim();


private:
    int _i;
    float execelaration;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _pub;
    
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _pub2;
    rclcpp::TimerBase::SharedPtr _timer;
    void publish_turtlesim_msg();

};




#endif