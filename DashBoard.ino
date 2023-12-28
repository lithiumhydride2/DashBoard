#include <ESP8266WiFi.h>
#include "led.h"
#define out_pin D1
#define USE_UART false
LED led(D4, D3, D2);
const char *ssid = "Com_wifi_backup";
const char *password = "comb888comb";
void setup()
{
    // serial
    if (USE_UART)
    {
        Serial.begin(115200);
        while (!Serial.available())
        {
            delay(500);
            Serial.print(".");
        }
        Serial.println("Serial connect!");
    }
    else
    {
        // Wifi
        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            Serial.print(".");
        }
        // Serial.p
    }
    pinMode(out_pin, OUTPUT);
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