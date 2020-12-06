#include "Button.h"

Button::Button(byte pin) {
  this->pin = pin;
  lastReading = HIGH;
  init();
}

void Button::init() {
  pinMode(pin, INPUT_PULLUP);
  update();
}

void Button::update() {
    byte newReading = digitalRead(pin);

    if (newReading != lastReading) {
      lastDebounceTime = millis();
    }

    if (millis() - lastDebounceTime > debounceDelay) {
      // Update the 'state' attribute only if debounce is checked
      state = newReading;
    }

    lastReading = newReading;
}

byte Button::getState() {
  update();
  return state;
}

bool Button::isPressed() {
  return (getState() == LOW);
}
