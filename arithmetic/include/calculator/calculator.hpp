#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "interface_exmpl/action/arithmetic_checker.hpp"
#include "interface_exmpl/msg/arithmetic_argument.hpp"
#include "interface_exmpl/srv/arithmetic_operator.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rcutils/cmdline_parser.h"
#include <chrono>
#include <string>
#include <thread>

using namespace std::chrono_literals;
using namespace std::placeholders;

class Calculator : public rclcpp::Node
{
public:
    using ArithmeticArgument = interface_exmpl::msg::ArithmeticArgument;
    using ArithmeticOperator = interface_exmpl::srv::ArithmeticOperator;
    using ArithmeticChecker = interface_exmpl::action::ArithmeticChecker;
    using GoalHandleArithmeticChecker = rclcpp_action::ServerGoalHandle<ArithmeticChecker>;

    Calculator();
    void service_callback(const std::shared_ptr<ArithmeticOperator::Request> request, std::shared_ptr<ArithmeticOperator::Response> response);

private:
    std::string _operator_str;
    std::string _formula_str;
    float _sub_a;
    float _sub_b;
    int8_t _argument_operator;
    float _argument_result;
    std::string _argument_formula;
    std::vector<std::string> _partial_formula;

    rclcpp::Subscription<ArithmeticArgument>::SharedPtr _subscription;
    rclcpp::Service<ArithmeticOperator>::SharedPtr _service;
    rclcpp_action::Server<ArithmeticChecker>::SharedPtr _action_server;

    void handle_accepted(const std::shared_ptr<GoalHandleArithmeticChecker> goal_handle);
    void sub_callback(const interface_exmpl::msg::ArithmeticArgument::SharedPtr msg);

    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const ArithmeticChecker::Goal> goal_handle);
    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleArithmeticChecker> goal_handle);
    void execute_checker(const std::shared_ptr<GoalHandleArithmeticChecker> goal_handle);
};

#endif // CALCULATOR_HPP