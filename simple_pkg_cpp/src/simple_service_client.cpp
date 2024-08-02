#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>
#include <chrono>


using namespace std;
using namespace std::chrono_literals;



class SimpleServiceClient : public rclcpp::Node
{
public :
    SimpleServiceClient()
        : Node("addTwoInt_client"), _a(40), _b(74)
    {
        //auto qos_profile = rclcpp:Qos(rclcpp::KeepLast(10));
        _client = create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
        while(! _client->wait_for_service(1s))
        {
            if(!rclcpp::ok())
            {
                RCLCPP_ERROR(get_logger(), "Over Time");
            }
            RCLCPP_INFO(get_logger(), "service not available, waiting again...");
        }
        RCLCPP_INFO(get_logger(), "Service is ready...");
    }
    void send_request()
    {
        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = _a;
        request->b = _b;



        auto result = _client->async_send_request(request);

        if(rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) ==rclcpp::FutureReturnCode::SUCCESS)
        {
            RCLCPP_INFO(get_logger(), "Result of %d + %d = %ld", _a, _b, result.get()->sum);
        }
        else
        {
            RCLCPP_INFO(get_logger(), "Service call failed!");
        }
        
    }

private:
    int _a;
    int _b;
    
    rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr _client;


};


int main()
{
    rclcpp::init(0, nullptr);

    auto node = std::make_shared<SimpleServiceClient>();
    node->send_request();

    rclcpp::shutdown();

    return 0;
}

