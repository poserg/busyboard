#include "TumblerLed.h"

void TumblerLed::on() {
	// Если тумблер включён, то светодиод мигать не будет.
	// Вынужденная мера из-за особенностей тумблера и способа подключения к Arduino.
	// Иначе тумблер считался бы включенным только когда светодиод горит.
	if (this->isPressed()) {
		return;
	}
	// Led::on();
	// digitalWrite(this->ledPin, HIGH);
}
