#include<iostream>
#include"GPIO.h"
using namespace exploringRPi;
using namespace std;

int main(){
  GPIO outGPIO(17), inGPIO(27);

  inGPIO.setDirection(INPUT);    //button is an input
  outGPIO.setDirection(OUTPUT);  //LED is an output
  inGPIO.setEdgeType(BOTH);    //wait for either edge
  outGPIO.streamOpen();          //fast write, ready file
  outGPIO.streamWrite(LOW);      //turn the LED off
  bool high;
  while (1) {
    inGPIO.waitForEdge();          //will wait forever
    high = (inGPIO.getValue() == HIGH);
    if(high){
      outGPIO.streamWrite(HIGH); //write new value
      outGPIO.streamWrite(LOW); //write new value
    } //else {
    //   outGPIO.streamWrite(LOW); //write new value
    // }
  }
  outGPIO.streamClose();         //close the output stream
  return 0;
}
