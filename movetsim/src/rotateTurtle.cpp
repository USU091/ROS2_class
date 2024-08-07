#include "movetsim/rotateTurtlesim.hpp"

RotateTurtle::RotateTurtle(int theta, const rclcpp::NodeOptions &options) : Node("rotate_turtle", options), _goal(theta)
{
    using namespace std::placeholders;
    _action_client = rclcpp_action::create_client<RotateAbsolute>(this, "turtle1/rotate_absolute");
    _timer = create_wall_timer(500ms, std::bind(&RotateTurtle::send_goal, this));
}
void RotateTurtle::send_goal()
{
    using namespace std::placeholders;
    _timer->cancel();
    if (!_action_client->wait_for_action_server(10s))
    {
        RCLCPP_ERROR(get_logger(), "Action server not available after waiting");
        rclcpp::shutdown();
    }
    auto goal_msg = RotateAbsolute::Goal();
    // degree to radian

    goal_msg.theta = (float)_goal * M_PI / 180;
    RCLCPP_INFO(get_logger(), "Sending goal request");

    auto send_goal_options = rclcpp_action::Client<RotateAbsolute>::SendGoalOptions();
    send_goal_options.goal_response_callback = std::bind(&RotateTurtle::goal_response_callback, this, _1);
    send_goal_options.feedback_callback = std::bind(&RotateTurtle::feedback_callback, this, _1, _2);
    send_goal_options.result_callback = std::bind(&RotateTurtle::result_callback, this, _1);
    _action_client->async_send_goal(goal_msg, send_goal_options);
}
void RotateTurtle::goal_response_callback(const GoalHandleRotateAbsolute::SharedPtr &goal_handle)
{
    if (!goal_handle)
    {
        RCLCPP_INFO(get_logger(), "Goal was rejected by server");
    }
    else
    {
        RCLCPP_INFO(get_logger(), "Goal accepted by server, waiting for result");
    }
}

void RotateTurtle::feedback_callback(
    GoalHandleRotateAbsolute::SharedPtr,
    const std::shared_ptr<const RotateAbsolute::Feedback> feedback)
{
    RCLCPP_INFO(get_logger(), "Remaining : %f", feedback->remaining);
}

void RotateTurtle::result_callback(const GoalHandleRotateAbsolute::WrappedResult &result)
{
    switch (result.code)
    {
    case rclcpp_action::ResultCode::SUCCEEDED:
        break;
    case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_INFO(get_logger(), "Goal was aborted");
        return;
    case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_INFO(get_logger(), "Goal was canceled");
        return;
    case rclcpp_action::ResultCode::UNKNOWN:
        RCLCPP_INFO(get_logger(), "Goal result is unknown");
        return;
    }

    RCLCPP_INFO(get_logger(), "Delta: %f", result.result->delta);
    rclcpp::shutdown();
}