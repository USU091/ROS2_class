
#include "movetsim/rotateTurtlesim.hpp"

void print_help()
{
    std::cout << "For argument node:" << std::endl;
    std::cout << "rotate_turtle [-h]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h  : Print this help function" << std::endl;
    std::cout << "  -g [number:0~360 degree]  : send turtlesim theta " << std::endl;
}
int main(int argc, char *argv[])
{
    if (rcutils_cli_option_exist(argv, argv + argc, "-h"))
    {
        print_help();
        return 0;
    }
    rclcpp::init(argc, argv);
    int goal_theta = 0;
    char *cli_option = rcutils_cli_get_option(argv, argv + argc, "-g");
    if (cli_option != nullptr)
    {
        goal_theta = atoi(cli_option);
    }
    rclcpp::NodeOptions options;
    rclcpp::spin(std::make_shared<RotateTurtle>(goal_theta, options));
    rclcpp::shutdown();
    return 0;
}