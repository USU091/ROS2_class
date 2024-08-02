#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>
#include <chrono>


using namespace std;
using namespace std::chrono_literals;



class SimpleServiceServer : public rclcpp::Node
{
public :
    SimpleServiceServer()
        : Node("addTwoInt_server"), _i(0)
    {

        _service = this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", std::bind(&SimpleServiceServer::callback, this, std::placeholders::_1, std::placeholders::_2));
        RCLCPP_INFO(get_logger(), "Service Server Ready to add two int");
    }

private:
    int _i;
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr _service;
    void callback(const example_interfaces::srv::AddTwoInts::Request::SharedPtr req, example_interfaces::srv::AddTwoInts::Response::SharedPtr res)
    {
        RCLCPP_INFO(get_logger(), "Incomming Message: %ld, %ld", req->a, req->b);
        res->sum = req->a + req->b;
    }
};


int main()
{
    rclcpp::init(0, nullptr);

    auto node = std::make_shared<SimpleServiceServer>();


    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

