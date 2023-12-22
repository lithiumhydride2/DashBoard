#include <Arduino.h>
#line 1 "D:\\FromGit\\DashBoard\\DashBoard.ino"
#line 1 "D:\\FromGit\\DashBoard\\DashBoard.ino"
void setup();
#line 6 "D:\\FromGit\\DashBoard\\DashBoard.ino"
void loop();
#line 1 "D:\\FromGit\\DashBoard\\DashBoard.ino"
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("hello esp8266");
    delay(1000);
}
