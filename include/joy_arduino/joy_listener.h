/*******************************************************************
 *
 * Header file for the JoyListener class that receives input from a gamepad.
 *
 * Author: Rouven Reichert (rouven.reichert@stud.uni-hannover.de)
 * Created: 2020/01/02
 *
 ******************************************************************/

#ifndef JOY_LISTENER_H
#define JOY_LISTENER_H

#include <ros/ros.h>
#include <vector>
#include <sensor_msgs/Joy.h>

class JoyListener
{
public:
    // ### Constructor and Destructor ###
    JoyListener();
    ~JoyListener();

    // Callback
    void callback(const sensor_msgs::Joy::ConstPtr& msg);

    // ### Methods ###
    int getPushedButton();      // Returns the button that was pushed; returns 0 if no button was pushed
    void clearPushedButton();   // resets m_pushed_button

private:
    std::vector<int> m_buttons;     // stores pushed buttons from callback function
    int m_pushed_button = 0;        // number of the pushed button on the gamepad (return value of method getPushedButton)
};

#endif // JOY_LISTENER_H
