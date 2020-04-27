#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper motor(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
}

void loop() {
  // read the sensor value:
  int joyStick = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(joyStick, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    motor.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    motor.step(stepsPerRevolution / 100);
  }
}

