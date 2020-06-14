/* 
 * Sketch to toggle an external  LED with a gamepad via ROS.
 * Based on the rosserial example 'Blink'.
 * 
 * Author:  Rouven Reichert
 * Created: 2019/12/31
 */

#include <ros.h>
#include <std_msgs/Empty.h>

// Define variables
int pinLED = 5;

ros::NodeHandle  nh;


// ################ CALLBACK ################
void messageCallback( const std_msgs::Empty& toggle_msg)
{
  // Toggle LED on received message
  digitalWrite(pinLED, HIGH-digitalRead(pinLED));
}

// Subscriber
ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCallback );


// ################ SETUP ################
void setup()
{ 
  // Define pin mode
  pinMode(pinLED, OUTPUT);

  // ROS setup
  nh.initNode();
  nh.subscribe(sub);
}


// ################ LOOP ################
void loop()
{  
  nh.spinOnce();
  delay(1);
}
