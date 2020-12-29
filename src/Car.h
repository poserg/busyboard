#ifndef SRC_CAR_H_
#define SRC_CAR_H_

#include <RGBmatrixPanel.h>
#define HIGH_PROGMEM __attribute__((section(".fini7")))

class Car {
private:
	RGBmatrixPanel* matrix;
	long previousMillis = 0;
	const long delay = 300;
	bool isFlasherOn = false;
	bool isFlasherTurnedOn = false;
protected:
	virtual void draw();
	virtual void drawWithFlasher();
public:
	Car(RGBmatrixPanel* matrix);
	virtual ~Car() {};
	void processNextIteration();
	void setIsFlasherOn(bool isOn);
};

#endif /* SRC_CAR_H_ */
