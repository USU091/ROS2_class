#include "practice/msg_sub1.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MsgSubscriber1>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}