#include <Arduino.h>
#line 1 "D:\\FromGit\\DashBoard\\DashBoard.ino"
#include "led.h"
#define out_pin D1

LED led(D4, D3, D2);

#line 6 "D:\\FromGit\\DashBoard\\DashBoard.ino"
void setup();
#line 17 "D:\\FromGit\\DashBoard\\DashBoard.ino"
void loop();
#line 6 "D:\\FromGit\\DashBoard\\DashBoard.ino"
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
