/**
 * @file   single_led_toggler.cpp
 * @author Rouven Reichert (rouven.reichert@stud.uni-hannover.de)
 * @date   January 2nd, 2020
 *
 * @brief  This node receives button commands from a gamepad to toggle a single, external LED connected to an Arduino Uno.
 */

// The corresponding Arduino sketch that receives the messages is called Toggle_LED_Joy.

#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include "joy_arduino/joy_listener.h"


// ########## MAIN ##########

int main(int argc, char** argv)
{
    // Initialize ROS
    ros::init(argc, argv, "single_led_toggler");
    // Create node handle object
    ros::NodeHandle nh("single_led_toggler");

    // Subscriber class and object for receiving gamepad commands
    JoyListener joy_listener;
    ros::Subscriber joy_sub = nh.subscribe("/joy", 1000, &JoyListener::callback, &joy_listener);

    // Publisher and message for toggling the LED
    ros::Publisher  led_publisher = nh.advertise<std_msgs::Empty>("/toggle_led", 1);
    std_msgs::Empty led_msg;

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
            ROS_INFO("Button %d has been pressed.", joy_listener.getPushedButton());
            // Publish message to toggle LED
            led_publisher.publish(led_msg);
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
