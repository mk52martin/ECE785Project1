#!/usr/bin/python3

from gpiozero import LED, Button
from time import sleep

out = LED(17)
button = Button(27)

last = True

while True:
    if button.is_pressed and not last:
        out.off()
        last = True
        out.on()
    if not button.is_pressed:
        # out.on()
        last = False

    
