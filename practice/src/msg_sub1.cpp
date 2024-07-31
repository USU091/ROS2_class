#include "practice/msg_sub1.hpp"

MsgSubscriber1::MsgSubscriber1()
    : Node("sub1")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    _sub = this->create_subscription<std_msgs::msg::String>("sub1", qos_profile, 
            std::bind(&MsgSubscriber1::sub1_msg, this, std::placeholders::_1));

}

void MsgSubscriber1::sub1_msg(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(get_logger(), "SUB1:: '%s'",msg->data.c_str());

}