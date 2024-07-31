#include "practice/msg_sub2.hpp"

MsgSubscriber2::MsgSubscriber2()
    : Node("sub2")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    _sub = this->create_subscription<std_msgs::msg::String>("sub2", qos_profile, 
            std::bind(&MsgSubscriber2::sub2_msg, this, std::placeholders::_1));

}

void MsgSubscriber2::sub2_msg(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(get_logger(), "SUB2:: '%s'",msg->data.c_str());

}