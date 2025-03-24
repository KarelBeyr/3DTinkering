#include <Servo.h>

Servo servos[6];

void setup() {
  for (int i = 0; i < 6; i++) {
    servos[i].attach(4 + i); // servos will be attached to pin 4, 5, 6, 7, 8 and 9

    // TODO implement servo position feedback, so that the arm makes "slow" movements during setup in case the potentiometers have been changed while the arduino was powered off
  }
}

void moveServo(int idx) {
  int analogValue = analogRead(idx + A0);  // Potentiometers are attached on pins A0 - A5. (A0 = D14, A1 = D15, ...)
  int val = map(analogValue, 0, 1023, 0, 180);

  // TODO implement slow movements so that the arm doesn't move too fast. (probably not needed now, as it is impossible to turn the potentiometer that fast by hand)
  servos[idx].write(val);
}

void loop() {
  for (int i = 0; i < 6; i++) {
    moveServo(i);
  }
}
