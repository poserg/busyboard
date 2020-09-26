#include <Arduino.h>

// Задаём номера выводов:
const int leftButtonPin = 36;
const int rightButtonPin = 35;
const int upButtonPin = 37;
const int downButtonPin = 34;

const int yellowLedPin =  40;
const int greenLedPin =  41;
const int blueLedPin =  38;
const int redLedPin =  39;

void setup() {
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  pinMode(leftButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  pinMode(upButtonPin, INPUT);
  pinMode(downButtonPin, INPUT);
}

void loop() {
  if (digitalRead(leftButtonPin) == HIGH) {
    digitalWrite(yellowLedPin, HIGH);
  } else {
    digitalWrite(yellowLedPin, LOW);
  }
  if (digitalRead(rightButtonPin) == HIGH) {
    digitalWrite(redLedPin, HIGH);
  } else {
    digitalWrite(redLedPin, LOW);
  }
  if (digitalRead(upButtonPin) == HIGH) {
    digitalWrite(greenLedPin, HIGH);
  } else {
    digitalWrite(greenLedPin, LOW);
  }
  if (digitalRead(downButtonPin) == HIGH) {
    digitalWrite(blueLedPin, HIGH);
  } else {
    digitalWrite(blueLedPin, LOW);
  }
}
