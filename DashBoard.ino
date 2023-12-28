#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include "led.h"
#define out_pin D1
#define USE_UART false
LED led(D4, D3, D2);

// wifi multi
ESP8266WiFiMulti wifimulti;
const char *ssid_1 = "Com_wifi_backup";
const char *passwd_1 = "comb888comb";
const char *ssid_2 = "comb_wifi";
const char *passwd_2 = "comb888comb";

// func
int _get_val(int);
void setup()
{
    // serial
    Serial.begin(9600);
    if (USE_UART)
    {
        while (!Serial.available())
        {
            delay(500);
            Serial.print(".");
        }
        Serial.println("Serial connect!");
    }
    // Wifi
    wifimulti.addAP(ssid_1, passwd_1);
    wifimulti.addAP(ssid_2, passwd_2);

    while (wifimulti.run() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.print("WiFi connect to:");
    Serial.println(WiFi.SSID());
    Serial.print("IP address is: ");
    Serial.println(WiFi.localIP());

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

int _get_val(int index = 0)
{
    if (USE_UART)
    {
        return Serial.parseInt();
    }

    // udp
}