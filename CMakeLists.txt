cmake_minimum_required(VERSION 2.8.3)
project(joy_arduino)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
)

include_directories(
 include
  ${joy_arduino_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

# ---------------------------------------------------------------------------------------
add_executable(single_led_toggler
	src/single_led_toggler.cpp
  src/joy_listener.cpp
)

target_link_libraries(single_led_toggler
    ${catkin_LIBRARIES}
)
