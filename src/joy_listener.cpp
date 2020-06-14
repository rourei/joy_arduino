/*******************************************************************
 *
 * Implementation of the JoyListener class that receives input from a
 * gamepad and returns only the pressed buttons.
 *
 * Author: Rouven Reichert (rouven.reichert@stud.uni-hannover.de)
 * Created: 2020/01/02
 *
 ******************************************************************/

#include "joy_arduino/joy_listener.h"

// ###### CONSTRUCTOR ##################################################################################################
JoyListener::JoyListener()
{
    ROS_INFO("JoyListener is set up.");
}

// ###### DESTRUCTOR ###################################################################################################
JoyListener::~JoyListener()
{
}

// ###### SUBSCRIBER CALLBACK ##########################################################################################
void JoyListener::callback(const sensor_msgs::Joy::ConstPtr& msg)
{
    // Write recieved message data to member variable
    m_buttons = msg->buttons;
}

// ###### GET PUSHED BUTTON ############################################################################################
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

// ###### CLEAR PUSHED BUTTON ##########################################################################################
void JoyListener::clearPushedButton()
{
    // Reset to zero
    m_pushed_button = 0;
}
