/*
  TLC5615_DAC.cpp - Library for the TLC5615 Digital to Analog Converter
  Frank Milburn     November 2015
  Released into the public domain
*/

#include <Energia.h>
#include "TLC5615_DAC.h"

/**********************************************************************************
* TLC5615           Instantiates the DAC
*   Arguments       Chip select pin for DAC
*   Returns         Nothing
**********************************************************************************/
TLC5615::TLC5615(int DAC_pin)
{
  _DAC_pin = DAC_pin;
  pinMode(_DAC_pin, OUTPUT);            // Make the chip select pin an output
}

/**********************************************************************************
* setValue          Writes set point to DAC
*   Arguments       Value to be written to DAC
*   Returns         Nothing
**********************************************************************************/
void TLC5615::setValue(int DAC_value)
{
  _DAC_value = DAC_value;
  
  digitalWrite(_DAC_pin,LOW);           // Take CS low to select chip
  
  SPI.transfer(_DAC_value >> 8);        // Shift 8 most significant bits over and
                                        // send them first
                                       
  SPI.transfer(_DAC_value & 0xFF);      // Clear out the MSB and send the LSB
  
  digitalWrite(_DAC_pin,HIGH);          // Place CS high to de-select the chip
}
/**********************************************************************************
* lowPower          Puts the DAC in low power state
*   Arguments       None
*   Returns         Nothing
**********************************************************************************/
void TLC5615::lowPower(void)
{
  int _lowPower = 0x00;                 // send all zeros for low power state
  
  digitalWrite(_DAC_pin,LOW);           // Take CS low to select chip
  
  SPI.transfer(_lowPower);              // Send MSB
                                       
  SPI.transfer(_lowPower);              // Send LSB
   
  digitalWrite(_DAC_pin,HIGH);          // Place CS high to de-select the chip
}
