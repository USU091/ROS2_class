cmake_minimum_required(VERSION 3.8)
project(movetsim)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(tf2 REQUIRED)
find_package(rclcpp_action REQUIRED)


include_directories(include)


#add executable
add_executable(moveTurtleSim src/moveTurtleSim.cpp src/moveTurtle.cpp)
ament_target_dependencies(moveTurtleSim rclcpp geometry_msgs)

add_executable(moveTurtleBot src/moveTurtleBot.cpp src/moveTurtleBotCpp.cpp)
ament_target_dependencies(moveTurtleBot rclcpp geometry_msgs nav_msgs)

add_executable(moveTurtleSim2 src/moveTurtleSim2.cpp src/moveTurtle2.cpp)
ament_target_dependencies(moveTurtleSim2 rclcpp geometry_msgs turtlesim)

add_executable(moveTurtleBot2 src/moveTurtleBot2.cpp src/moveTurtleBotCpp2.cpp)
ament_target_dependencies(moveTurtleBot2 rclcpp geometry_msgs nav_msgs tf2)


add_executable(rotateTurtlesim src/rotateTurtlesim.cpp src/rotateTurtle.cpp)
ament_target_dependencies(rotateTurtlesim rclcpp turtlesim rclcpp_action)



#install
install(TARGETS
  moveTurtleSim
  moveTurtleBot
  moveTurtleSim2
  moveTurtleBot2
  rotateTurtlesim
  DESTINATION lib/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  set(ament_cmake_copyright_FOUND TRUE)

  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
