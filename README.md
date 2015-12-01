# TLC5615_DAC

Library for the Texas Instruments TLC5615 Digital to Analog Converter (DAC)
       
        TLC5615CP
                 +----+  
           DIN  1|o   |8  VDD
          SCLK  2|    |7  OUT
            CS  3|    |6  REFIN
          DOUT  4|    |5  AGND
                 +----+     
   
              Notes:
              1) REFIN determines the DAC full-scale output (~2 to 5V OK
              2) Setting the DAC register to all 0s minimizes power consumption
              3) VDD needs to be 5V
              4) Continuous current at any terminal not to exceed 20mA
              5) The TLC5615 is 10 bit but values between 0 and 2047 are accepted to maintain compatibility with other DACs.  Voltage varies linearly.
   
              Connections:
              TLC5615        LaunchPad
              Pin  Name      Pin
              ---  -------   ---------------------
              1    DIN       15  MOSI
              2    SCLK      7  SCK
              3    CS        8  CS
              4    DOUT      Not used here - used to chain DACs
              5    AGND      GND
              6    REFIN     3.3V (if 3.3V full scale desired)
              7    OUT       Output voltage
              8    VDD       5V          
  
  Tested on:
              MSP430FR6989 and Energia V16
              MSP432P401R and Energia V16
              MSP430F5529 and Energia V16
              MSP430G2553 and Energia V16   

              
  Frank Milburn    November 2015
  Released into the public domain

