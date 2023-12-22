#include <Arduino.h>
#define out_pin D1

void setup()
{
    Serial.begin(9600);
    pinMode(out_pin, OUTPUT);
    while (!Serial.available())
    {
        delay(100);
    }
    Serial.println("Serial connect!");
}

void loop()
{
    while (Serial.available())
    {
        Serial.println("hello world");
        int val = Serial.parseInt();
        analogWrite(out_pin, val);
    }
}