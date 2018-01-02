# Science-Olympiad-Projects

This repo contains the code and mechanical design files for the science olympiad projects I worked on in high school.

Electric Vehicle 2016
  - Transmitter
    - This is a simple transmitter test using the NRF24L01+ to send live potentiometer data
  - Receiver
    - This is a simple receiver test using the NRF24L01+ to receive that data and write it to a servo
  - Controller for testing
    - This was a more advanced transmitter which sent multiple live input values
  - Car for testing
    - This was the complementary receiver which controlled multiple motors based on the live data it received from the controller
  - Car 2
    - This was the actual code used on the car for competition
    - The wireless version was just for testing purposes because we were not allowed to be in contact with the car for the event
    - This is a pretty simple program that takes in a delaytime and waits that long before cutting off power to the motor
  
Robot Arm 2016
 - Versions
  - Stepper motor testing
    - This was to test out the Adafruit Motor Shield on a small NEMA 17 stepper
  - Small stepper v2
    - These was to make a similar program but without the use of a motor shield
  - Claw
    - This program maps a potentiometer to a servo
  - Claw with 1 pivot
    - This adds on another potentiometer with a stepper
  - Claw with 1 pivot v2
  - Claw with 2 pivots
    - Adds another potentiometer with a stepper
  - Claw with 2 pivots v2
  - Claw with 3 pivots
    - Adds another
  - Robot arm final 2
    - Replaces potentiometers with pushbuttons to turn motors left and right
    - Adds in LEDs for debugging
    - Variable labels are clear

Electric Vehicle 2017
- This was a similar program to that of 2016 and was not anything new from a learning standpoint
  
Robot Arm 2017
- Versions
  - Sparkfun EasyDriver test
    - This was to learn how to control a stepper motor using the EasyDriver
  - Base test
    - This was to test the Adafruit Motor Shield with a stepper
  - Vertical and Collector
    - This was to test a synced pair of motors: one stepper and one continuous rotation servos in order to pull up part of the robot arm
  - StepperCode
    - This adds another joint of motion to the arm 
  - Overall code v1
    - This set of code controls the main motors of the arm
  - Overall code v2
  - Overall code v3
  - Overall code v4
  - Overall code v5
  - Overall code v6
  - 2nd Arduino v1
    - This set of code controls the secondary motors of the arm
  - 2nd Arduino v2
  - 2nd Arduino v3
