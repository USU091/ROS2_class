#include "practice/time_sub.hpp"

TimeSubscriber::TimeSubscriber()
    : Node("hello_world")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    _timesub = this->create_subscription<std_msgs::msg::Header>("time_topic", qos_profile, std::bind(&TimeSubscriber::subscribe_time_msg, this, std::placeholders::_1));

    _msgsub = this->create_subscription<std_msgs::msg::String>("msg_topic", qos_profile, 
            std::bind(&TimeSubscriber::subscribe_msg_msg, this, std::placeholders::_1));
}

void TimeSubscriber::subscribe_time_msg(const std_msgs::msg::Header::SharedPtr msg)
{
    RCLCPP_INFO(get_logger(), "frame id: %s", msg->frame_id.c_str());
    RCLCPP_INFO(get_logger(), "stamp: %d.%d", msg->stamp.sec, msg->stamp.nanosec);

}

void TimeSubscriber::subscribe_msg_msg(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(get_logger(), "SUB3:: '%s'",msg->data.c_str());

}