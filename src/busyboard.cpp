#include "Led.h"
#include "Button.h"

#define LEFT_BUTTON_PIN 39
#define RIGHT_BUTTON_PIN 38
#define UP_BUTTON_PIN 40
#define DOWN_BUTTON_PIN 41

#define YELLOW_BUTTON_PIN 37
#define GREEN_BUTTON_PIN 35
#define BLUE_BUTTON_PIN 34
#define RED_BUTTON_PIN 36

#define YELLOW_LED_PIN 33
#define GREEN_LED_PIN 32
#define BLUE_LED_PIN 31
#define RED_LED_PIN 30

Button leftButton(LEFT_BUTTON_PIN);

void setup() {
	Serial.begin(115200);

	pinMode(YELLOW_LED_PIN, OUTPUT);
	pinMode(GREEN_LED_PIN, OUTPUT);
	pinMode(BLUE_LED_PIN, OUTPUT);
	pinMode(RED_LED_PIN, OUTPUT);

	pinMode(YELLOW_BUTTON_PIN, INPUT_PULLUP);
	pinMode(GREEN_BUTTON_PIN, INPUT_PULLUP);
	pinMode(BLUE_BUTTON_PIN, INPUT_PULLUP);
	pinMode(RED_BUTTON_PIN, INPUT_PULLUP);

	pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
	pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
	pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
	pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);

	digitalWrite(YELLOW_LED_PIN, LOW);
	digitalWrite(RED_LED_PIN, LOW);
	digitalWrite(GREEN_LED_PIN, LOW);
	digitalWrite(BLUE_LED_PIN, LOW);
}

void loop() {
	if (digitalRead(LEFT_BUTTON_PIN) == LOW or digitalRead(YELLOW_BUTTON_PIN) == LOW) {
	  digitalWrite(YELLOW_LED_PIN, LOW);
	} else {
	  digitalWrite(YELLOW_LED_PIN, HIGH);
	}
	if (digitalRead(RIGHT_BUTTON_PIN) == LOW || digitalRead(RED_BUTTON_PIN) == LOW) {
	  digitalWrite(RED_LED_PIN, LOW);
	} else {
	  digitalWrite(RED_LED_PIN, HIGH);
	}
	if (digitalRead(UP_BUTTON_PIN) == LOW || digitalRead(GREEN_BUTTON_PIN) == LOW) {
		  if (digitalRead(UP_BUTTON_PIN) == LOW)
			  Serial.println("UP_BUTTON is HIG");
		  if (digitalRead(GREEN_BUTTON_PIN) == LOW)
			  Serial.println("GREEN_BUTTON is HIG");
	  digitalWrite(GREEN_LED_PIN, LOW);
	} else {
	  digitalWrite(GREEN_LED_PIN, HIGH);
	}
	if (digitalRead(DOWN_BUTTON_PIN) == LOW || digitalRead(BLUE_BUTTON_PIN) == LOW) {
	  digitalWrite(BLUE_LED_PIN, LOW);
	} else {
	  digitalWrite(BLUE_LED_PIN, HIGH);
	}
}
