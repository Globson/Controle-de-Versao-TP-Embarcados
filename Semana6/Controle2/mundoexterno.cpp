#include <LiquidCrystal.h>
#include <Keypad.h>

const byte NumLinhas = 4;  //number of rows on the keypad
const byte NumColunas = 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[NumLinhas][NumColunas] =
    {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};

//Code that shows the the keypad connections to the arduino terminals
byte PinosLinhas[NumLinhas] = {9, 8, 7, 6};   //Rows 0 to 3
byte PinosColunas[NumColunas] = {5, 4, 3, 2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), PinosLinhas, PinosColunas, NumLinhas, NumColunas);

const int d4 = 13, d5 = 12, d6 = 11, d7 = 10;
struct Configuracao
{
    long long unsigned int Intervalo_Tempo = 0;
    int DelayFechamento = 0;
    int AbertoSempre = 0;
};
struct Configuracao Conf;
bool Reset = false;
LiquidCrystal lcd(A1, A2, d4, d5, d6, d7);
void setup()
{
    char keypressed = myKeypad.getKey();
    lcd.begin(16, 2);
    Serial.begin(9600);
    lcd.clear();
    pinMode(A0, OUTPUT);
    pinMode(A5, INPUT);
    lcd.clear();
    lcd.print("Primeiro defina");
    lcd.setCursor(0, 1);
    lcd.print("o tempo:");
    delay(1500);
    bool primeirodigito = true;
    bool doisdigitos = false;
    lcd.clear();
    lcd.print("Intervalo em");
    lcd.setCursor(0, 1);
    lcd.print("horas: ");
    while (keypressed != 'C')
    {
        keypressed = myKeypad.getKey();
        if (keypressed == '0' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 0;
                primeirodigito = false;
                lcd.print("0");
            }
            else
            {
                lcd.print("0 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == '1' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 10;
                primeirodigito = false;
                lcd.print("1");
            }
            else
            {
                Conf.Intervalo_Tempo += 1;
                lcd.print("1 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == '2' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 20;
                primeirodigito = false;
                lcd.print("2");
            }
            else
            {
                Conf.Intervalo_Tempo += 2;
                lcd.print("2 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == '3' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 30;
                primeirodigito = false;
                lcd.print("3");
            }
            else
            {
                Conf.Intervalo_Tempo += 3;
                lcd.print("3 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == '4' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 40;
                primeirodigito = false;
                lcd.print("4");
            }
            else
            {
                Conf.Intervalo_Tempo += 4;
                lcd.print("4 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == '5' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 50;
                primeirodigito = false;
                lcd.print("5");
            }
            else
            {
                Conf.Intervalo_Tempo += 5;
                lcd.print("5 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == '6' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 60;
                primeirodigito = false;
                lcd.print("6");
            }
            else
            {
                Conf.Intervalo_Tempo += 6;
                lcd.print("6 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == '7' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 70;
                primeirodigito = false;
                lcd.print("7");
            }
            else
            {
                Conf.Intervalo_Tempo += 7;
                lcd.print("7 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == '8' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 80;
                primeirodigito = false;
                lcd.print("8");
            }
            else
            {
                Conf.Intervalo_Tempo += 8;
                lcd.print("8 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == '9' && !doisdigitos)
        {
            if (primeirodigito)
            {
                Conf.Intervalo_Tempo = 90;
                primeirodigito = false;
                lcd.print("9");
            }
            else
            {
                Conf.Intervalo_Tempo += 9;
                lcd.print("9 horas");
                doisdigitos = true;
            }
        }
        else if (keypressed == 'A')
        {
            primeirodigito = true;
            doisdigitos = false;
            lcd.clear();
            lcd.print("Intervalo em");
            lcd.setCursor(0, 1);
            lcd.print("horas: ");
        }
    }
    lcd.clear();
    lcd.print("Confirmando: ");
    lcd.setCursor(0, 1);
    lcd.print((int)Conf.Intervalo_Tempo);
    lcd.print(" horas");
    delay(1500);
    if (Conf.Intervalo_Tempo == 0)
    {
        Conf.AbertoSempre = 1;
    }
    else
    {
        Conf.Intervalo_Tempo = Conf.Intervalo_Tempo * 100;
    }

    if (!Conf.AbertoSempre)
    {
        lcd.clear();
        lcd.print("Agora defina");
        lcd.setCursor(0, 1);
        lcd.print("o despejo:");
        delay(1500);
        primeirodigito = true;
        doisdigitos = false;
        lcd.clear();
        lcd.print("Intervalo em");
        lcd.setCursor(0, 1);
        lcd.print("segundos: ");
        keypressed = myKeypad.getKey();
        while (keypressed != 'C')
        {
            keypressed = myKeypad.getKey();
            if (keypressed == '0' && !doisdigitos)
            {
                if (primeirodigito)
                {
                    Conf.DelayFechamento = 0;
                    primeirodigito = false;
                    lcd.print("0");
                }
                else
                {
                    lcd.print("0 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == '1' && !doisdigitos)
            {
                if (primeirodigito)
                {
                    Conf.DelayFechamento = 10;
                    primeirodigito = false;
                    lcd.print("1");
                }
                else
                {
                    Conf.DelayFechamento += 1;
                    lcd.print("1 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == '2' && !doisdigitos)
            {
                if (primeirodigito)
                {
                    Conf.DelayFechamento = 20;
                    primeirodigito = false;
                    lcd.print("2");
                }
                else
                {
                    Conf.DelayFechamento += 2;
                    lcd.print("2 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == '3' && !doisdigitos)
            {
                if (primeirodigito)
                {
                    Conf.DelayFechamento = 30;
                    primeirodigito = false;
                    lcd.print("3");
                }
                else
                {
                    Conf.DelayFechamento += 3;
                    lcd.print("3 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == '4' && !doisdigitos)
            {
                if (primeirodigito)
                {
                    Conf.DelayFechamento = 40;
                    primeirodigito = false;
                    lcd.print("4");
                }
                else
                {
                    Conf.DelayFechamento += 4;
                    lcd.print("4 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == '5' && !doisdigitos)
            {
                if (primeirodigito)
                {
                    Conf.DelayFechamento = 50;
                    primeirodigito = false;
                    lcd.print("5");
                }
                else
                {
                    Conf.DelayFechamento += 5;
                    lcd.print("5 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == '6' && !doisdigitos)
            {
                if (primeirodigito)
                {
                    Conf.DelayFechamento = 60;
                    primeirodigito = false;
                    lcd.print("6");
                }
                else
                {
                    Conf.DelayFechamento += 6;
                    lcd.print("6 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == '7' && !doisdigitos)
            {
                if (!primeirodigito)
                {
                    Conf.DelayFechamento += 7;
                    lcd.print("7 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == '8' && !doisdigitos)
            {
                if (!primeirodigito)
                {
                    Conf.DelayFechamento += 8;
                    lcd.print("8 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == '9' && !doisdigitos)
            {
                if (!primeirodigito)
                {
                    Conf.DelayFechamento += 9;
                    lcd.print("9 s");
                    doisdigitos = true;
                }
            }
            else if (keypressed == 'A')
            {
                primeirodigito = true;
                doisdigitos = false;
                lcd.clear();
                lcd.print("Intervalo em");
                lcd.setCursor(0, 1);
                lcd.print("segundos: ");
            }
        }
        lcd.clear();
        lcd.print("Confirmando: ");
        lcd.setCursor(0, 1);
        lcd.print(Conf.DelayFechamento);
        lcd.print(" segundos");
        delay(1500);
        Conf.DelayFechamento *= 1000;
    }
    lcd.clear();
    lcd.print("Enviando para");
    lcd.setCursor(0, 1);
    lcd.print("Arduino...");
    Serial.write((char *)&Conf, sizeof(struct Configuracao));
    delay(1000);
}

void loop()
{
    /*char keypressed = myKeypad.getKey();
    if (keypressed != NO_KEY)
    {
        Serial.println(keypressed);
    }*/
    lcd.clear();
    lcd.print("Running...");
    delay(300);
    if (analogRead(A5) != 0)
    {
        Reset = true;
        //todo enviar e realizar reset.
    }
    if (Serial.available() > 0)
    {
        int nivel_racao;
        Serial.readBytes((char *)&nivel_racao, sizeof(int));
        Serial.flush();
        if (nivel_racao == 3)
        {
            lcd.clear();
            lcd.print("Nivel de");
            lcd.setCursor(0, 1);
            lcd.print("racao razoavel!");
        }
        else if (nivel_racao == 2)
        {
            lcd.clear();
            lcd.print("ATENCAO! Nivel");
            lcd.setCursor(0, 1);
            lcd.print("de racao medio!");
        }
        else if (nivel_racao == 1)
        {
            lcd.clear();
            lcd.print("ATENCAO! Nivel");
            lcd.setCursor(0, 1);
            lcd.print("de racao baixo!");
        }
        delay(2000);
    }
    if(analogRead(A5)==0){
        Reset = True;
        Serial.write((byte*)&Reset,sizeof(Reset));
        delay(300);
        analogWrite(A0,255);
    }
}