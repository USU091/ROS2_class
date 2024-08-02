#ifndef MOVETURTLEBOT2_HPP
#define MOVETURTLEBOT2_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <chrono>
#include <iostream>
#include "tf2/LinearMath/Quaternion.h"
#include "tf2/LinearMath/Matrix3x3.h"

using namespace std;
using namespace std::chrono_literals;


class MoveTurtleBot2 : public rclcpp::Node
{
public:
    MoveTurtleBot2();


private:
    int _i;
    float execelaration;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _twist_pub;
    
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr _odom_sub;


    rclcpp::TimerBase::SharedPtr _timer;
    void sub_odom_msg(const nav_msgs::msg::Odometry::SharedPtr msg);
    void publish_turtlebot_msg();

    nav_msgs::msg::Odometry _odom_msg;
    float _theta;




};




#endif