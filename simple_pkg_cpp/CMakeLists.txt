cmake_minimum_required(VERSION 3.8)
project(simple_pkg_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(rcl_interfaces REQUIRED)
find_package(rclcpp_action REQUIRED)

#include dir
include_directories(include)

add_executable(helloWorld src/helloWorld.cpp)


add_executable(helloOpenCV src/helloOpenCV.cpp)
target_link_libraries(helloOpenCV ${OpenCV_LIBS})

add_executable(helloPublisher src/helloPublisher.cpp)
ament_target_dependencies(helloPublisher rclcpp std_msgs)

add_executable(helloPublisher2 src/helloPublisher2.cpp)
ament_target_dependencies(helloPublisher2 rclcpp std_msgs)

add_executable(helloPublisherClass src/helloPublisherClass.cpp)
ament_target_dependencies(helloPublisherClass rclcpp std_msgs)

add_executable(helloPublisherClass2 src/helloPublisherClass2.cpp src/publisher.cpp)
ament_target_dependencies(helloPublisherClass2 rclcpp std_msgs)

add_executable(helloSubscriberClass src/helloSubscriberClass.cpp src/subscriber.cpp)
ament_target_dependencies(helloSubscriberClass rclcpp std_msgs)

add_executable(timePublisher src/timePublisher.cpp src/time_pub.cpp)
ament_target_dependencies(timePublisher rclcpp std_msgs)

add_executable(timeSubscriber src/timeSubscriber.cpp src/time_sub.cpp)
ament_target_dependencies(timeSubscriber rclcpp std_msgs)


add_executable(simple_service_server src/simple_service_server.cpp)
ament_target_dependencies(simple_service_server rclcpp std_msgs example_interfaces)

add_executable(simple_service_client src/simple_service_client.cpp)
ament_target_dependencies(simple_service_client rclcpp std_msgs example_interfaces)

add_executable(simple_service_client2 src/simple_service_client2.cpp)
ament_target_dependencies(simple_service_client2 rclcpp std_msgs example_interfaces rcl_interfaces)

add_executable(simple_action_server src/simple_action_server.cpp)
ament_target_dependencies(simple_action_server rclcpp std_msgs example_interfaces rclcpp_action)

add_executable(simple_action_client src/simple_action_client.cpp)
ament_target_dependencies(simple_action_client rclcpp std_msgs example_interfaces rclcpp_action)


#install
install(TARGETS
  helloWorld
  helloOpenCV
  helloPublisher
  helloPublisher2
  helloPublisherClass
  helloPublisherClass2
  helloSubscriberClass
  timePublisher
  timeSubscriber
  simple_service_server
  simple_service_client
  simple_service_client2
  simple_action_server
  simple_action_client
  DESTINATION lib/${PROJECT_NAME}
)


install(DIRECTORY
  launch
  param
  DESTINATION share/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()