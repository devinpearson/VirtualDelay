#include <Arduino.h>
#include <avdweb_VirtualDelay.h>

VirtualDelay delay1, delay2, delay3, delay4, delay5, delay6;

void setup() { 
    Serial.begin(9600); 
}

void loop()
{
    DO_ONCE(
      Serial.println("DO_ONCE 1");
      delay1.start(200); // start sequence delay1 delay2 delay3
      delay4.start(550); // start one-shot delay4
      delay5.start(1250); // start one-shot delay5
    )
    
    if (delay4.elapsed()) {
        Serial.print("ONE-SHOT 550ms          ");
        Serial.println(millis());
    }
        
    if (delay5.elapsed()) {
        Serial.print("ONE-SHOT 1250ms         ");
        Serial.println(millis());
    }

    if (millis() > 2250) {
        DO_ONCE(
          Serial.print("DO_ONCE 2 2250ms        ");
          Serial.println(millis()); // test a second DO_ONCE
        );
    }
        
    delay6.start(750);
    
    if (delay6.elapsed()) {
        Serial.print("  Repeat delay6 750ms   ");
        Serial.println(millis());
    } 

    if (delay1.elapsed()) { // sequence with deadlock
        Serial.print("sequence delay1 200ms   ");
        Serial.println(millis());
        delay2.start(100);
    }
    
    if (delay2.elapsed()) {
        Serial.print("sequence delay2 100ms   ");
        Serial.println(millis());
        delay3.start(400);
    }
    
    if (delay3.elapsed()) {
        Serial.print("sequence delay3 400ms   ");
        Serial.println(millis());
        delay1.start(200);
    }
}