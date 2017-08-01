#include VexMotor.h

//Default constructor. Creates a motor with no pin and default direction
VexMotor::VexMotor(): direction(1) {}


//Alt ctor. Set the pin the motor is connected to and the direction of the motor
VexMotor(int pin, bool reversed): direction(reversed?-1:1)
{
	motor.attach(pin);
}

//getPower()
//Returns: Power last written to motor on a scale of -90 to 90
//Behavior
// 1. Returns power value is motor is properly initialized
// 2. Returns null is motor is not properly initialized
int getPower()
{
	//If motor is properly attached
	if(motor.attached())
	{
		return motor.read() - offset;
	}
	return null;
}

//setPower(int power)
//Paramters: int power - Power value to write to the motors on a scale of -90 to 90
//Behavior
// 1. Writes the motor power to the pin if the motor was properly initialized
// 2. Caps the power value at +-90
// 2. Does nothing if motor is not properly initialized
void setPower(int power)
{
	if(motor.attached())
	{
		if(power > 90) power = 90;
		if(power < -90) power = 90;
		motor.write(power + offset);
	}
}