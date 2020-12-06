#ifndef SRC_TUMBLERLED_H_
#define SRC_TUMBLERLED_H_

#include "Button.h"
#include "Led.h"

class TumblerLed: public Led, public Button {
private:
	byte ledPin;
public:
	TumblerLed(byte ledPin, byte buttonPin) : Led(ledPin), Button(buttonPin), ledPin(ledPin) { }
	virtual void on();
};

#endif /* SRC_TUMBLERLED_H_ */
