#!/usr/bin/python3

from gpiozero import LED
from time import sleep

led = LED(17)

while True:
    led.on()
    led.off()

    
