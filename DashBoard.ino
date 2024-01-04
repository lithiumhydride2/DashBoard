#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiUdp.h>

#include "led.h"

#define out_pin D1
#define USE_UART false
LED led(D4, D3, D2);

// wifi multi
ESP8266WiFiMulti wifimulti;
const char *ssid_1 = "Com_wifi_backup";
const char *passwd_1 = "comb888comb";

// udp
WiFiUDP udp;
uint16 udp_port = 8266;
// func
int _get_val();

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
    else
    {
        // Wifi
        wifimulti.addAP(ssid_1, passwd_1);
        while (wifimulti.run() != WL_CONNECTED)
        {
            delay(500);
            Serial.print(".");
        }
        Serial.print("WiFi connect to:");
        Serial.println(WiFi.SSID());
        Serial.print("IP address is: ");
        Serial.println(WiFi.localIP());
        // UDP
        if (udp.begin(udp_port))
        {
            Serial.print("UDP connect to port: ");
            Serial.println(udp_port);
        }
    }

    pinMode(out_pin, OUTPUT);
}

void loop()
{
    int val = 0;
    while (Serial.available())
    {
        val = _get_val();
        if (val != 0)
        {
            analogWrite(out_pin, val);
            led.set_val(val);
        }
    }
}

int _get_val()
{
    if (USE_UART)
    {
        return Serial.parseInt();
    }
    else
    {
        return udp.parseInt();
    }

    // udp
}