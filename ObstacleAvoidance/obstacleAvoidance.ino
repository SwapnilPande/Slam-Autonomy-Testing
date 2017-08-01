#include "VexMotor.h"

#include <NewPing.h>


//#include <Servo.h>

VexMotor ultraHead(4,false);
//vexMotor ultraHead;
//Servo leftDrive;
//Servo rightDrive;



const int trigPin = 22;
const int echoPin = 24;
NewPing ultrasonic(trigPin, echoPin);


int ultraPot = 0;



const double zeroOffset = 70.0; //Offset of 0 degrees. This is the center of the robot
const double degPerCount = 250.0/1023.0;

const double motorPowerScale = -180.0/200.0;
const double motorPowerShift = -90;

double readUltraPot()
{
  return degPerCount*(double)analogRead(ultraPot)-zeroOffset;
}

double setMotorPower(VexMotor &motor, int power)
{
  motor.setPower(power);//motorPowerScale*power - motorPowerShift);
}

void setup() {
  //ultraHead.attach(4);
  Serial.begin(9600);
}

int scanDirection = -1;

void loop() {
  if(readUltraPot() <= -45) scanDirection = 1;
  if(readUltraPot() >= 45) scanDirection = -1;
  if(scanDirection == 1)
  {
      //setMotorPower(ultraHead, 81);
      ultraHead.setPower(70);
  }
  else
  {
          //setMotorPower(ultraHead, 90);
    ultraHead.setPower(-70);
  }
  
  Serial.println(readUltraPot());

}
