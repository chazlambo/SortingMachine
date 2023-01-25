/*-------------------------------
      SERVO PINS & INCLUDES
---------------------------------*/
#include <PWMServo.h>

//Servo Pins
const int TOPSERVO = 11;
const int BOTSERVO = 12;

/*-------------------------
      SERVO VARIABLES
---------------------------*/
// Servo Objects
PWMServo topServo;
PWMServo botServo;

//Position Variables
int upPos = 90;
int downPosTop = 50;
int downPosBot = 135;

/*-------------------------
      SERVO FUNCTIONS
---------------------------*/
void servoSetup(void) {
  topServo.attach(TOPSERVO);
  botServo.attach(BOTSERVO);
  servo_setup = 1;
}

void servoContam(void) {
  topServo.write(downPosTop);
  botServo.write(upPos);
}

void servoSort(void) {
  topServo.write(upPos);
  botServo.write(downPosBot);
}

void servoPass(void) {
  topServo.write(upPos);
  botServo.write(upPos);
}
