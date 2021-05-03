#include <Servo.h>
#include <LiquidCrystal.h>

int Var1 = 0;
int Intervalo_Tempo=0;
Int Tempo_dalay = 0;
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo servo_9;

void setup()
{
    lcd.begin(16, 2);
    pinMode(3, INPUT);
    pinMode(2, INPUT);
    pinMode(A1, INPUT);
    servo_9.attach(9);
    servo_9.write(0);
    pinMode(A0, INPUT);
    Serial.begin(9600);
    while (digitalRead(2) != 1)
    {
        lcd.clear();
        if (digitalRead(3) == 1)
        {
            if (Var1 == 7)
            {
                Var1 = 0;
            }
            else
            {
                Var1++;
            }
        }
        if (Var1 == 6)
        {
            lcd.print("LIBERADO");
            Intervalo_Tempo = 99;
            delay(1000);
        }
        else if (Var1 == 5)
        {
            lcd.print("A cada 3 horas");
            Intervalo_Tempo = 3;
            delay(1000);
        }
        else if (Var1 == 4)
        {
            lcd.print("A cada 6 horas");
            Intervalo_Tempo = 6;
            delay(1000);
        }
        else if (Var1 == 3)
        {
            lcd.print("A cada 9 horas");
            Intervalo_Tempo = 9;
            delay(1000);
        }
        else if (Var1 == 2)
        {
            lcd.print("A cada 12 horas");
            Intervalo_Tempo = 12;
            delay(1000);
        }
        else if (Var1 == 1)
        {
            lcd.print("A cada 18 horas");
            Intervalo_Tempo = 18;
            delay(1000);
        }
        else if (Var1 == 0)
        {
            lcd.print("A cada 24 horas");
            Intervalo_Tempo = 24;
            delay(1000);
        }
    }
    Intervalo_Tempo = Intervalo_Tempo *3600000;
}

void Abre_Fecha_Racao(int tempo)
{
    int posicaoInicial = servo_9.read();
    servo_9.write(180);
    delay(tempo);
    servo_9.write(posicaoInicial);
}

void loop()
{
    Abre_Fecha_Racao(2000);
    delay(Intervalo_Tempo);
    Serial.println(analogRead(A0));
    //Serial.println(analogRead(A1));
    Serial.println(Var1);
    //Serial.println(servo_9.read());
}