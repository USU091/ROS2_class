#include "practice/msg_pub.hpp"

MsgPublishClass::MsgPublishClass()
    : Node("MsgPub"), _i(0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    _pub1 = this->create_publisher<std_msgs::msg::String>("sub1", qos_profile);
    _pub2 = this->create_publisher<std_msgs::msg::String>("sub2", qos_profile);
    _pub3 = this->create_publisher<std_msgs::msg::String>("sub3", qos_profile);
    _timer = this->create_wall_timer(1s, std::bind(&MsgPublishClass::pub_msg, this));
}

void MsgPublishClass::pub_msg()
{
    auto msg = std_msgs::msg::String();
    auto msg2 = std_msgs::msg::String();
    auto msg3 = std_msgs::msg::String();

    msg.data = "sending msg pub1:::::" + to_string(_i);
    msg2.data = "sending msg pub2:::::" + to_string(_i);
    msg3.data = "sending msg pub3:::::" + to_string(_i);
    _pub1->publish(msg);
    _pub2->publish(msg2);
    _pub3->publish(msg3);
    _i++;
}