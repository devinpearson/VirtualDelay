#include <Arduino.h>
#include <avdweb_VirtualDelay.h>

VirtualDelay delay_us(micros);

void setup() 
{ 
	Serial.begin(9600); 
	delay_us.start(1000000);
}

void loop()
{
    if (delay_us.elapsed()) {
        Serial.print(micros());
    }
}
