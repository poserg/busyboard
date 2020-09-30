#include <Arduino.h>

// Задаём номера выводов:
const int leftButtonPin = 39;
const int rightButtonPin = 38;
const int upButtonPin = 40;
const int downButtonPin = 41;

const int yellowButtonPin = 37;
const int greenButtonPin = 35;
const int blueButtonPin = 34;
const int redButtonPin = 36;

const int yellowLedPin =  33;
const int greenLedPin =  32;
const int blueLedPin =  31;
const int redLedPin =  30;

void setup() {
	Serial.begin(115200);

  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  pinMode(yellowButtonPin, INPUT_PULLUP);
  pinMode(greenButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);
  pinMode(redButtonPin, INPUT_PULLUP);

  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);
  pinMode(upButtonPin, INPUT_PULLUP);
  pinMode(downButtonPin, INPUT_PULLUP);

  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(blueLedPin, LOW);
}

void loop() {
  if (digitalRead(leftButtonPin) == LOW or digitalRead(yellowButtonPin) == LOW) {
    digitalWrite(yellowLedPin, LOW);
  } else {
    digitalWrite(yellowLedPin, HIGH);
  }
  if (digitalRead(rightButtonPin) == LOW || digitalRead(redButtonPin) == LOW) {
    digitalWrite(redLedPin, LOW);
  } else {
    digitalWrite(redLedPin, HIGH);
  }
  if (digitalRead(upButtonPin) == LOW || digitalRead(greenButtonPin) == LOW) {
	  if (digitalRead(upButtonPin) == LOW)
		  Serial.println("upButton is HIG");
	  if (digitalRead(greenButtonPin) == LOW)
		  Serial.println("greenButton is HIG");
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(greenLedPin, HIGH);
  }
  if (digitalRead(downButtonPin) == LOW || digitalRead(blueButtonPin) == LOW) {
    digitalWrite(blueLedPin, LOW);
  } else {
    digitalWrite(blueLedPin, HIGH);
  }
}
