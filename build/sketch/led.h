#line 1 "D:\\FromGit\\DashBoard\\led.h"
#include <Arduino.h>

class LED
{
private:
    uint8_t led_r = 0;
    uint8_t led_g = 0;
    uint8_t led_b = 0;

public:
    LED(uint8_t r, uint8_t g, uint8_t b);
    ~LED();
    void set_val(int);
};

LED::LED(uint8_t r, uint8_t g, uint8_t b) : led_r(r), led_g(g), led_b(b)
{
    pinMode(led_r, OUTPUT);
    pinMode(led_g, OUTPUT);
    pinMode(led_b, OUTPUT);

    analogWrite(led_r, 0);
    analogWrite(led_g, 0);
    analogWrite(led_b, 0);
}

LED::~LED()
{
}

void LED::set_val(int input)
{
    if (input > 255)
        input = 255;
    // from green to red
    int red = input;
    int green = 255 - red;
    analogWrite(led_r, red);
    analogWrite(led_g, green);
    analogWrite(led_b, 0);
}
