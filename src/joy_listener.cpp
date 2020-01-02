/**
 * @file   joy_listener.cpp
 * @author Rouven Reichert (rouven.reichert@stud.uni-hannover.de)
 * @date   January 2nd, 2020
 *
 * @brief  Implementation of the JoyListener class that receives input from a gamepad and returns only the pressed buttons.
 */

#include "joy_arduino/joy_listener.h"

// ###### Constructor and Destructor ######
JoyListener::JoyListener()
{
    ROS_INFO("JoyListener is set up.");
}
JoyListener::~JoyListener()
{

}

// ###### Subscriber callback ######
void JoyListener::callback(const sensor_msgs::Joy::ConstPtr& msg)
{
    // Write recieved message data to member variable
    m_buttons = msg->buttons;
}

// ###### Methods ######
int JoyListener::getPushedButton()
{
    // Iterate over vector
    for (int i = 0; i < m_buttons.size(); i++)
    {
        // Check, which button is pushed
        if (m_buttons.at(i))
        {
            m_pushed_button = i + 1;    // button numbering starts at 1, vector index at 0 -> add 1
        }
    }

    // Return currently pressed button
    return m_pushed_button;
}

void JoyListener::clearPushedButton()
{
    // Reset to zero
    m_pushed_button = 0;
}
