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

   bool on;
   bool last = false;

   while (1) {
    on = (inGPIO.getValue() == HIGH);
    
    if(on && !last) {
      outGPIO.setValue(HIGH);
      last = true;
    } else if(last) {
       outGPIO.setValue(LOW);
    }
    if(!on){
       outGPIO.setValue(LOW);
       last = false;
    }
    
    //outGPIO.setValue(inGPIO.getValue());

   }
   
   return 0;
}
