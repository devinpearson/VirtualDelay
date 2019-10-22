#include <Arduino.h>
#include <avdweb_VirtualDelay.h>

#define ledPin 13 // built in led pin
#define interval 1000 // length of time between the led switching on and off

bool b = false; // led state

VirtualDelay singleDelay; // default = millis

void setup()
{
   pinMode(ledPin, OUTPUT); 
}

void loop()
{
    singleDelay.start(interval); // calls while running are ignored
    if (singleDelay.elapsed()) {
        digitalWrite(ledPin, b = !b); // blink the onboard LED 400ms, 400ms off
    }
}