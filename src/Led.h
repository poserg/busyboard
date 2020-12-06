#ifndef MY_LED_H
#define MY_LED_H
#include <Arduino.h>
class Led {

  private:
    byte pin;

  public:
    Led(byte pin);
    void init();
    virtual void on();
    void off();
    virtual ~Led() {};
};
#endif
