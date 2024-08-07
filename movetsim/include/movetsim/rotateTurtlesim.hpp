#ifndef ROTATETURTLE_HPP
#define ROTATETURTLE_HPP

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rcutils/cmdline_parser.h"
#include "turtlesim/action/rotate_absolute.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <sstream>
#include <thread>

using namespace std::chrono_literals;

class RotateTurtle : public rclcpp::Node
{
public:
    using RotateAbsolute = turtlesim::action::RotateAbsolute;
    using GoalHandleRotateAbsolute = rclcpp_action::ClientGoalHandle<RotateAbsolute>;

    RotateTurtle(int theta, const rclcpp::NodeOptions &options);
    void send_goal();

private:
    int _goal;
    rclcpp_action::Client<RotateAbsolute>::SharedPtr _action_client;
    rclcpp::TimerBase::SharedPtr _timer;
    void goal_response_callback(const GoalHandleRotateAbsolute::SharedPtr &goal_handle);

    void feedback_callback(
        GoalHandleRotateAbsolute::SharedPtr,
        const std::shared_ptr<const RotateAbsolute::Feedback> feedback);

    void result_callback(const GoalHandleRotateAbsolute::WrappedResult &result);
};


#endif