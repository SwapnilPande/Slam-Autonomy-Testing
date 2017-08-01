#ifndef VEXMOTOR_H
#define VEXMOTOR_H

#include <Servo.h>

class VexMotor {
private:
	Servo motor; //Servo object used to control the motor
	int direction; //Stores the direction (CW or CCW) that is considered forward
	const int offset = 90; //PWM offset required to properly write the power to the motor
public:
	//Default constructor. Creates a motor with no pin and default direction
	VexMotor();

	//Alt ctor. Set the pin the motor is connected to and the direction of the motor
	VexMotor(int pin, bool reversed);

	//getPower()
	//Returns: Power last written to motor on a scale of -90 to 90
	//Behavior
	// 1. Returns power value is motor is properly initialized
	// 2. Returns null is motor is not properly initialized
	int getPower();

	//setPower(int power)
	//Paramters: int power - Power value to write to the motors on a scale of -90 to 90
	//Behavior
	// 1. Writes the motor power to the pin if the motor was properly initialized
	// 2. Does nothing if motor is not properly initialized
	void setPower(int power);
};


#endif