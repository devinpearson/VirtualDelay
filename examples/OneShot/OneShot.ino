#include <Arduino.h>
#include <avdweb_VirtualDelay.h>

#define interval 2000

VirtualDelay delay1;

void setup()
{
    Serial.begin(9600);
    Serial.println("testOneShot 2s");
    delay1.start(interval);
}

void loop()
{
    if (delay1.elapsed()) {
      Serial.print(millis());
      Serial.println("ms");
    }    
}