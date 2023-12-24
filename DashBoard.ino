#include "led.h"
#define out_pin D1

LED led(D4, D3, D2);

void setup()
{
    Serial.begin(115200);
    pinMode(out_pin, OUTPUT);
    while (!Serial.available())
    {
        delay(100);
    }
    Serial.println("Serial connect!");
}

void loop()
{
    long val = 0;
    while (Serial.available())
    {
        val = Serial.parseInt();
        if (val != 0)
        {
            analogWrite(out_pin, val);
            led.set_val(val);
        }
    }
}