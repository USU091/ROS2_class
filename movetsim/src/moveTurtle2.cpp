#include "movetsim/moveTurtle2.hpp"

MoveTurtlesim2::MoveTurtlesim2()
    : Node("moveTurtleNode"), _i(0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    _pub = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", qos_profile);



    _sub = this->create_subscription<turtlesim::msg::Pose>("turtle1/pose", qos_profile,
    std::bind(&MoveTurtlesim2::sub_turtlesim_pose, this, std::placeholders::_1));
    _timer = this->create_wall_timer(30ms, std::bind(&MoveTurtlesim2::publish_turtlesim_msg, this));
}

void MoveTurtlesim2::sub_turtlesim_pose(const turtlesim::msg::Pose::SharedPtr msg)
{
    _pose_msg = *msg;

}


void MoveTurtlesim2::publish_turtlesim_msg()
{
    auto msg = geometry_msgs::msg::Twist();

    switch(_i)
    {
        case 0:
        {
            if(_pose_msg.x < 6.5)
            {
                msg.linear.x = 0.1;
                msg.angular.z = 0.0;
            }
            else if(_pose_msg.theta < 1.57)
            {
                msg.linear.x = 0.0;
                msg.angular.z = 1.8;
            }
            else
                _i++;

        }
            break;
        case 1:
        {
            if(_pose_msg.y < 6.5)
            {
                msg.linear.x = 0.1;
                msg.angular.z = 0.0;
            }
            else if(_pose_msg.theta < 3.14 && _pose_msg.theta > 0)
            {
                msg.linear.x = 0.0;
                msg.angular.z = 1.8;
            }
            else
                _i++;
        }
            break;
        case 2:
        {
            if(_pose_msg.x > 5.5)
            {
                msg.linear.x = 0.1;
                msg.angular.z = 0.0;
            }
            else if(_pose_msg.theta < -1.57)
            {
                msg.linear.x = 0.0;
                msg.angular.z = 1.8;
            }
            else
                _i++;
        }
            break;
        case 3:
        {
            if(_pose_msg.y > 5.5)
            {
                msg.linear.x = 0.1;
                msg.angular.z = 0.0;
            }
            else if(_pose_msg.theta < 0)
            {
                msg.linear.x = 0.0;
                msg.angular.z = 1.8;
            }
            else
                _i = 0;
        }
        break;

    }

    _pub->publish(msg);


}