#line 1 "/home/lih/from_git/DashBoard/DashBoard.ino"
#include <Arduino.h>
#define out_pin PIN2

#line 4 "/home/lih/from_git/DashBoard/DashBoard.ino"
void setup();
#line 15 "/home/lih/from_git/DashBoard/DashBoard.ino"
void loop();
#line 4 "/home/lih/from_git/DashBoard/DashBoard.ino"
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
