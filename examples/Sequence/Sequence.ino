#include <Arduino.h>
#include <avdweb_VirtualDelay.h>

VirtualDelay delay1, delay2, delay3;

void setup()
{
    Serial.begin(9600);
    Serial.println("testSequence");
}

void loop()
{
    if (delay1.elapsed()) // this sequence has a deadlock
    {
        Serial.print("delay1 200ms ");
        Serial.println(millis());
        delay2.start(100);
    }
    if (delay2.elapsed()) {
        Serial.print("delay2 100ms ");
        Serial.println(millis());
        delay3.start(400);
    }
    if (delay3.elapsed()) {
        Serial.print("delay3 400ms ");
        Serial.println(millis());
        delay1.start(200);
    }
    DO_ONCE(delay1.start(200)); // breaks the deadlock, you can start with any
        // delay object you want e.g. delay2.start(0);
}
