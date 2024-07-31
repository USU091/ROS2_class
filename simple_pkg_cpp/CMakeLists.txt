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



#include dir
include_directories(include)

# excutable
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
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()