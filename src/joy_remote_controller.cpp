/**
 * @file   joy_remote_controller.cpp
 * @author Rouven Reichert (rouven.reichert@stud.uni-hannover.de)
 * @date   2020/01/24
 *
 * @brief  This node receives gamepad commands for remote controlling an Arduino Uno.
 */


#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include "joy_arduino/joy_listener.h"


// ########## MAIN ##########

int main(int argc, char** argv)
{
    // Initialize ROS
    ros::init(argc, argv, "joy_remote_controller");
    // Create node handle object
    ros::NodeHandle nh("joy_remote_controller");

    // Subscriber class and object for receiving gamepad commands
    JoyListener joy_listener;
    ros::Subscriber joy_sub = nh.subscribe("/joy", 1000, &JoyListener::callback, &joy_listener);

    // Publisher
    // ### TO DO ###

    // Dead time to avoid publishing multiple messages on one press of a button
    ros::Time last_published;

    // Loop rate in Hz
    ros::Rate loop_rate(10);


    // ######################## Loop ########################
    while (ros::ok())
    {
        // Only toggle LED if a button was pushed and the last message was sent more than 0.5s ago
        if (joy_listener.getPushedButton() != 0 && ros::Time::now() - last_published > ros::Duration(0.5))
        {
            // Publish message
            // Update dead time
            last_published = ros::Time::now();
        }

        // Clear button data for next run
        joy_listener.clearPushedButton();

        // Spin the loop
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
