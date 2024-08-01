#ifndef MOVETURTLE2_HPP
#define MOVETURTLE2_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include <iostream>
#include "turtlesim/msg/pose.hpp"




using namespace std;
using namespace std::chrono_literals;


class MoveTurtlesim2 : public rclcpp::Node
{
public:
    MoveTurtlesim2();


private:
    int _i;
    float execelaration;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _pub;
    
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr _sub;
    rclcpp::TimerBase::SharedPtr _timer;
    void publish_turtlesim_msg();
    void sub_turtlesim_pose(const turtlesim::msg::Pose::SharedPtr msg);
    turtlesim::msg::Pose _pose_msg;

    

};




#endif