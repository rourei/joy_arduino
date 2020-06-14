# joy_arduino

This package deals with remote controlling an Arduino UNO using a generic gamepad and ROS. It has been developed under Ubuntu 18.04.4 LTS using [ROS Melodic](http://wiki.ros.org/melodic).
It uses the [rosserial_arduino](http://wiki.ros.org/rosserial_arduino) library to bring ROS functionality into the world of Arduino.

Its current main purpose is to provide a personal playground to learn about mobile robotics using ROS and an Arduino with various shields, sensors and 3D printed components.
If you like, you can follow along my journey of exploring electronics and mobile robotics on my maker blog on [Instagram](https://www.instagram.com/diy_engineered/).

Feel free to fork and use this repository as a starting point for your own projects! If you just want to get started quickly you can use the provided launch files to test some of the functionality.

---

## Launch files
- **toggle_led.launch**
  - launches all required nodes to toggle an external LED connected to the Arduino UNO with a generic gamepad using ROS topics as an interface

---

## Nodes / Classes / Sketches
- Class **JoyListener**:
  - can be used to listen to gamepad commands and provides the method `getPushedButton()` which returns the number of the button that has been pushed on the gamepad
- Node **single_led_toggler**
  - uses an instance of the **JoyListener** class to send a `std_msgs/Empty` on the `toggle_led` topic whenever a button on the gamepad is pressed
- Sketch **Toggle_LED_Joy**
  - switches the LED connected to pin 5 of the Arduino on or off (depending on its previous state) whenever it receives a `std_msgs/Empty` on the `toggle_led` topic via the serial interface

---

## Roadmap

The following features are planned to be implemented over time:

- remote controlling motors on an Arduino Uno using the Adafruit Motor Shield V1
- passing sensor data (e.g. ultra sonic) from the Arduino back to the computer for processing
