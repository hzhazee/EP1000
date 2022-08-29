// C++ code
//
#include <Servo.h>

int Distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_3;

void setup()
{
  servo_3.attach(3, 500, 2500);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  Distance = 0.01723 * readUltrasonicDistance(2, 7);
  if (Distance < 50 && Distance > 0) {
    servo_3.write(90);
    analogWrite(5, 255);
    analogWrite(6, 255);
    analogWrite(9, 0);
  } else {
    servo_3.write(0);
    analogWrite(5, 51);
    analogWrite(6, 255);
    analogWrite(9, 51);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
