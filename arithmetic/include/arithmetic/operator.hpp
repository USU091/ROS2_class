#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include "rclcpp/rclcpp.hpp"
#include "interface_exmpl/srv/arithmetic_operator.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"
#include "rcutils/cmdline_parser.h"
#include <chrono>
#include <random>

using namespace std::chrono_literals;


class Operator : public rclcpp::Node
{
public:
    using ArithmeticOperator = interface_exmpl::srv::ArithmeticOperator;
    Operator(const rclcpp::NodeOptions &options = rclcpp::NodeOptions());
    
private:
    bool rnd_state;
    int8_t arithmeticOperator;
    rclcpp::Subscription<rcl_interfaces::msg::ParameterEvent>::SharedPtr _parameter_event_sub;
    rclcpp::Client<interface_exmpl::srv::ArithmeticOperator>::SharedPtr _service;
    void response_callback(rclcpp::Client<interface_exmpl::srv::ArithmeticOperator>::SharedFuture future);
    void timer_callback();
    rclcpp::TimerBase::SharedPtr  _timer;
    void random_operator();
    void param_event_callback(const rcl_interfaces::msg::ParameterEvent::SharedPtr event);


};

#endif