#include <LiquidCrystal.h>
#include <Keypad.h>

const byte numRows = 4; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols] =
    {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {13, 12, 11, 10}; //Rows 0 to 3
byte colPins[numCols] = {9, 8, 7, 6}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

const int d4 = 5, d5 = 4, d6 = 3, d7 = 2;
struct Configuracao
{
    long long unsigned int Intervalo_Tempo = 0;
    int DelayFechamento = 0;
    int AbertoSempre = 0;
};
struct Configuracao Conf;

LiquidCrystal lcd(A1, A2, d4, d5, d6, d7);
void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
    lcd.clear();
    pinMode(A0, INPUT);
    pinMode(A5, INPUT);
    lcd.clear();
    lcd.print("Primeiro defina");
    lcd.setCursor(0, 1);
    lcd.print("o tempo:");
    delay(3000);
    char keypressed = myKeypad.getKey();
    while (keypressed != 'C')
    {
        lcd.clear();
        if (analogRead(A0) < 110)
        {
            lcd.print("Aberto sempre.");
            lcd.setCursor(0, 1);
            lcd.print(keypressed);
            Conf.AbertoSempre = 1;
            delay(500);
        }
        else if (analogRead(A0) < 292)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("3 horas.");
            Conf.AbertoSempre = 0;
            Conf.Intervalo_Tempo = 3;
            delay(500);
        }
        else if (analogRead(A0) < 438)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("6 horas.");
            Conf.AbertoSempre = 0;
            Conf.Intervalo_Tempo = 6;
            delay(500);
        }
        else if (analogRead(A0) < 584)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("9 horas.");
            Conf.AbertoSempre = 0;
            Conf.Intervalo_Tempo = 9;
            delay(500);
        }
        else if (analogRead(A0) < 730)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("12 horas.");
            Conf.AbertoSempre = 0;
            Conf.Intervalo_Tempo = 12;
            delay(500);
        }
        else if (analogRead(A0) < 876)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("18 horas.");
            Conf.AbertoSempre = 0;
            Conf.Intervalo_Tempo = 18;
            delay(500);
        }
        else if (analogRead(A0) < 1024)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("24 horas.");
            Conf.AbertoSempre = 0;
            Conf.Intervalo_Tempo = 24;
            delay(500);
        }
        keypressed = myKeypad.getKey();
    }
    Conf.Intervalo_Tempo = Conf.Intervalo_Tempo * 100;
    if (!Conf.AbertoSempre)
    {
        lcd.clear();
        lcd.print("Agora defina");
        lcd.setCursor(0, 1);
        lcd.print("o despejo:");
        delay(3000);
        keypressed = myKeypad.getKey();
        while (keypressed != 'C')
        {
            lcd.clear();
            if (analogRead(A0) < 120)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 3 segundos.");
                Conf.DelayFechamento = 3000;
                delay(500);
            }
            else if (analogRead(A0) < 240)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 5 segundos.");
                Conf.DelayFechamento = 5000;
                delay(500);
            }
            else if (analogRead(A0) < 360)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 8 segundos.");
                Conf.DelayFechamento = 8000;
                delay(500);
            }
            else if (analogRead(A0) < 480)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 10 segundos.");
                Conf.DelayFechamento = 10000;
                delay(500);
            }
            else if (analogRead(A0) < 600)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 12 segundos.");
                Conf.DelayFechamento = 12000;
                delay(500);
            }
            else if (analogRead(A0) < 720)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 15 segundos.");
                Conf.DelayFechamento = 15000;
                delay(500);
            }
            else if (analogRead(A0) < 840)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 18 segundos.");
                Conf.DelayFechamento = 18000;
                delay(500);
            }
            else if (analogRead(A0) < 1024)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 20 segundos.");
                Conf.DelayFechamento = 20000;
                delay(500);
            }
            keypressed = myKeypad.getKey();
        }
    }
    lcd.clear();
    lcd.print("Enviando para");
    lcd.setCursor(0, 1);
    lcd.print("Arduino...");
    Serial.write((char *)&Conf, sizeof(struct Configuracao));
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
        //lcd.print(Serial.read(), DEC);
        Serial.flush();
    }
}