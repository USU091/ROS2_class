
#include "movetsim/moveTurtle2.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MoveTurtlesim2>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}