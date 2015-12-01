/*
  TLC5615_DAC.h - Library for the TLC5615 Digital to Analog Converter
  Frank Milburn     November 2015
  Released into the public domain
*/
#ifndef TLC5615_DAC_h
#define TLC5615_DAC_h

#include <Energia.h>
#include <SPI.h>

class TLC5615
{
  public:
    TLC5615(int DAC_pin);
    void setValue(int DAC_value);
    void lowPower(void);
  private:
    int _DAC_pin;
    int _DAC_value;
    int _lowPower;
};
#endif
