#!/usr/bin/python3

from gpiozero import LED, Button
from time import sleep

out = LED(17)
button = Button(27)

while True:
    if button.is_pressed():
        out.on()
    else:
        out.off()

    
