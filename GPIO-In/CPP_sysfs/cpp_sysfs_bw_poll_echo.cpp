/* A Simple GPIO application
*  Written by Derek Molloy for the book "Exploring Raspberry Pi" */

#include<iostream>
#include<unistd.h>  // for the usleep() function
#include"GPIO.h"
using namespace exploringRPi;
using namespace std;

int main(){
   GPIO outGPIO(17), inGPIO(27);    // pin 11 and pin 13

   outGPIO.setDirection(OUTPUT);    // basic output example
   inGPIO.setDirection(INPUT);      // basic input example

   bool on = false;
   bool last = false;

   while (1) {
    on = inGPIO.getValue();
    if(on && !last) {
      outGPIO.setValue(HIGH);
      last = true;
    }
    if(last) {
      outGPIO.setValue(LOW);
    } else if(!on) {
      last = false;
    }

   }
   
   return 0;
}
