#include <Stepper.h>

const int stepsPerRevolution = 150055;  // change this to fit the number of steps per revolution
int cont = 0;

// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  // set the speed at 5 rpm
  myStepper.setSpeed(2);
  // initialize the serial port
  Serial.begin(115200);
}

void loop() {
  // step one revolution in one direction:
  Serial.println("clockwisssse");
  myStepper.step(stepsPerRevolution);
  delay(1000);

cont = cont + 1;
Serial.println("Pulsación #:");
Serial.print(cont);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
