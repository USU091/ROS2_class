cmake_minimum_required(VERSION 3.8)
project(practice)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)

#include dir
include_directories(include)


add_executable(msgPublisher src/msgPublisherClass.cpp src/msg_pub.cpp)
ament_target_dependencies(msgPublisher rclcpp std_msgs)

add_executable(msgSubscriber1 src/msgSubscriber1.cpp src/msg_sub1.cpp)
ament_target_dependencies(msgSubscriber1 rclcpp std_msgs)

add_executable(msgSubscriber2 src/msgSubscriber2.cpp src/msg_sub2.cpp)
ament_target_dependencies(msgSubscriber2 rclcpp std_msgs)

add_executable(timePublisher src/timePublisherClass.cpp src/time_pub.cpp)
ament_target_dependencies(timePublisher rclcpp std_msgs)

add_executable(timeSubscriber src/timeSubscriber.cpp src/time_sub.cpp)
ament_target_dependencies(timeSubscriber rclcpp std_msgs)

#install
install(TARGETS
  msgPublisher
  msgSubscriber1
  msgSubscriber2
  timePublisher
  timeSubscriber
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  param
  DESTINATION share/${PROJECT_NAME}
)



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)

  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
