#include "practice/msg_pub.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MsgPublishClass>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}