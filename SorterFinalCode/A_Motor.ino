/*--------------------------------------------
      MOTOR AND ENCODER PINS & INCLUDES
  ----------------------------------------------*/
#include <Encoder.h>
#include <RunningMedian.h>

// MOTOR PINS
const int MDIR1 = 9;
const int MDIR2 = 10;

// ENCODER PINS
const int ENC1 = 2;
const int ENC2 = 3;

/*-------------------------------------
      MOTOR AND ENCODER VARIABLES
  ---------------------------------------*/

// ENCODER VARIABLES
Encoder myEnc(ENC1, ENC2);

//FILTER OBJECT
RunningMedian velFilter = RunningMedian(5);
RunningMedian derrorFilter = RunningMedian(5);

// MOTOR PHYSICAL VARIABLES
double motorGearRatio = 250;  // the gear ratio
int countsPerRev_motor = 20;  // the counts per revolution of the motor shaft
long counts = 0;              // Globally initialize encoder counts

// Motor Speed Control Variables
int mSpdCmd = 0;

// KINEMATIC VARIABLES
double motorPos = 0;          // current pos
double motorVel = 0;          // current velocity
double motorVel_meas = 0;     // unfiltered velocity
double motorPos_old = 0;      // previous pos

// PID CONTROL VARIABLES
double Kp = 18;
double Ki = 0.2;
double Kd = 0.2;
double StepTime = 2;

double motorPos_des = 0;
double V; // motor voltage command


/*-------------------------------------
      MOTOR AND ENCODER FUNCTIONS
  ---------------------------------------*/

void motorSetup(void) {
  pinMode(MDIR1, OUTPUT);
  pinMode(MDIR2, OUTPUT);

  motor_setup = 1;
}

void drive(int motorSpeed) {
  if (motorSpeed == 0) {
    analogWrite(MDIR1, 0);
    analogWrite(MDIR2, 0);

  }
  if (motorSpeed < 1) {
    analogWrite(MDIR1, abs(motorSpeed));
    analogWrite(MDIR2, 0);
  }
  if (motorSpeed > 1) {
    analogWrite(MDIR1, 0);
    analogWrite(MDIR2, abs(motorSpeed));
  }
}

void updateEncoder(void) {
  // Update Counts
  counts = myEnc.read();

  // Calculate Position (rad)
  motorPos = counts / countsPerRev_motor / motorGearRatio * 2 * PI; // Rotation in radians

  // Calculate Angular Velocity (rad/s)
  motorVel_meas = (motorPos - motorPos_old) / (t - t_old_enc);
  velFilter.add(motorVel_meas);
  motorVel = velFilter.getMedian();

  t_old_enc = t;
  motorPos_old = motorPos;
}

void pidMotor(void) {
  double dt = t - t_old_mot;
  error = motorPos_des - motorPos;
  ierror += error * dt;
  derror_raw = (error - error_old) / dt;
  derrorFilter.add(derror_raw);
  derror = derrorFilter.getMedian();
  V = Kp * error + Kd * derror + Ki * ierror;
  V = constrain(V, -11., 11.);
  V = V / 12 * 255;
  mSpdCmd = int(round(V));


  if (abs(mSpdCmd) < 50) {

    if (mSpdCmd > 0) {
      mSpdCmd = 50;
    }
    else {
      mSpdCmd = -50;
    }
  }



  drive(mSpdCmd);

  derror_old = derror;
  error_old = error;

  t_old_mot = t;
}

void updateNextPosition(void) {
  drive(0);
  motorPos_des += (PI / 3);

  ierror = 0;
  derror_raw = 0;
  derror = 0;
}
