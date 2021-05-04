#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
    lcd.clear();
}

void loop()
{
    delay(1000);
    if (Serial.available() > 0)
    {
        lcd.clear();
        lcd.print("Arduino 2");
        lcd.setCursor(0, 1);
        lcd.print("RECEBEU!!");
        lcd.print(Serial.read(), DEC);
        Serial.flush();
    }
}