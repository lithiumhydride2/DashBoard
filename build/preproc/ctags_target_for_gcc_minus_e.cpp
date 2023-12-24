# 1 "/home/lih/from_git/DashBoard/DashBoard.ino"
# 2 "/home/lih/from_git/DashBoard/DashBoard.ino" 2


LED led(D4, D3, D2);

void setup()
{
    Serial.begin(115200);
    pinMode(D1, 0x01);
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
            analogWrite(D1, val);
            led.set_val(val);
        }
    }
}
