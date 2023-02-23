#include<iostream>
#include<unistd.h>
#include"GPIO.h"
using namespace exploringRPi;
using namespace std;

GPIO *outGPIO, *inGPIO;           // global pointers
bool high;

int echoValue(int var){
   // high = (inGPIO->getValue() == HIGH)
   // if(high){
   //    outGPIO->streamWrite(HIGH); //write new value
   // }
   outGPIO->streamWrite(inGPIO->getValue());
   outGPIO->streamWrite(LOW)
   return 0;
}

int main(){
   inGPIO = new GPIO(27);         // the button
   outGPIO = new GPIO(17);        // the LED
   inGPIO->setDirection(INPUT);   // the button is an input
   outGPIO->setDirection(OUTPUT); // the LED is an output
   outGPIO->streamOpen();         // use fast write to LED
   outGPIO->streamWrite(LOW);     // turn the LED off
   inGPIO->setEdgeType(BOTH);   // wait for either edge
   while(1) {
      // cout << "You have 1000 seconds to press the button:" << endl;
      inGPIO->waitForEdge(&echoValue); // pass the callback function
      // cout << "Listening, but also doing something else..." << endl;
      for(int i=0; i<1000; i++){
         usleep(1000000);            // sleep for 1 second
         // cout << "[sec]" << flush;   // display a message
      }
   }
   outGPIO->streamWrite(LOW);     // turn off the LED after 10 seconds
   outGPIO->streamClose();        // shutdown the stream
   return 0;
}
