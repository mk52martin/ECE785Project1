#!/usr/bin/python3

from gpiozero import LED, Button
from time import sleep

out = LED(17)
button = Button(27)


def on_press():
    out.on()
    out.off()

while True:
    button.when_pressed(on_press())
    sleep(1000)

    
