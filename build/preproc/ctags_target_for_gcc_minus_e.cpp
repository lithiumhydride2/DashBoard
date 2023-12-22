# 1 "/home/lih/from_git/DashBoard/DashBoard.ino"
# 2 "/home/lih/from_git/DashBoard/DashBoard.ino" 2


void setup()
{
    Serial.begin(9600);
    pinMode(
# 7 "/home/lih/from_git/DashBoard/DashBoard.ino" 3
           2
# 7 "/home/lih/from_git/DashBoard/DashBoard.ino"
                  , 0x1);
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
        analogWrite(
# 21 "/home/lih/from_git/DashBoard/DashBoard.ino" 3
                   2
# 21 "/home/lih/from_git/DashBoard/DashBoard.ino"
                          , val);
    }
}
