#include <Servo.h>
#include <LiquidCrystal.h>

int DelayFechamento = 0,AbertoSempre=0;
long long unsigned int Intervalo_Tempo = 0;
int Tempo_dalay = 0, Delay_Abertura;
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo servo_9;

void setup()
{
    lcd.begin(16, 2);
    pinMode(2, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    servo_9.attach(9);
    servo_9.write(0);
    pinMode(A0, INPUT);
    Serial.begin(9600);
    lcd.clear();
    lcd.print("Primeiro defina");
    lcd.setCursor(0, 1);
    lcd.print("o tempo:");
    delay(3000);
    while (digitalRead(2) != 1)
    {
        lcd.clear();
        if (analogRead(A0) < 110)
        {
            lcd.print("Aberto sempre.");
            AbertoSempre = 1;
            delay(500);
        }
        else if (analogRead(A0) < 292)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("3 horas.");
            AbertoSempre = 0;
            Intervalo_Tempo = 3;
            delay(500);
        }
        else if (analogRead(A0) < 438)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("6 horas.");
            AbertoSempre = 0;
            Intervalo_Tempo = 6;
            delay(500);
        }
        else if (analogRead(A0) < 584)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("9 horas.");
            AbertoSempre = 0;
            Intervalo_Tempo = 9;
            delay(500);
        }
        else if (analogRead(A0) < 730)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("12 horas.");
            AbertoSempre = 0;
            Intervalo_Tempo = 12;
            delay(500);
        }
        else if (analogRead(A0) < 876)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("18 horas.");
            AbertoSempre = 0;
            Intervalo_Tempo = 18;
            delay(500);
        }
        else if (analogRead(A0) < 1024)
        {
            lcd.print("Abrir a cada");
            lcd.setCursor(0, 1);
            lcd.print("24 horas.");
            AbertoSempre = 0;
            Intervalo_Tempo = 24;
            delay(500);
        }
    }
    Intervalo_Tempo = Intervalo_Tempo * 100;
    if(!AbertoSempre){
        lcd.clear();
        lcd.print("Agora defina");
        lcd.setCursor(0, 1);
        lcd.print("o despejo:");
        delay(3000);
        while (digitalRead(2) != 1)
        {
            lcd.clear();
            if (analogRead(A0) < 120)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 3 segundos.");
                DelayFechamento = 3000;
                delay(500);
            }
            else if (analogRead(A0) < 240)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 5 segundos.");
                DelayFechamento = 5000;
                delay(500);
            }
            else if (analogRead(A0) < 360)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 8 segundos.");
                DelayFechamento = 8000;
                delay(500);
            }
            else if (analogRead(A0) < 480)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 10 segundos.");
                DelayFechamento = 10000;
                delay(500);
            }
            else if (analogRead(A0) < 600)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 12 segundos.");
                DelayFechamento = 12000;
                delay(500);
            }
            else if (analogRead(A0) < 720)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 15 segundos.");
                DelayFechamento = 15000;
                delay(500);
            }
            else if (analogRead(A0) < 840)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 18 segundos.");
                DelayFechamento = 18000;
                delay(500);
            }
            else if (analogRead(A0) < 1024)
            {
                lcd.print("Racao despejada");
                lcd.setCursor(0, 1);
                lcd.print("por 20 segundos.");
                DelayFechamento = 20000;
                delay(500);
            }
        }
    }
}
void Abre_Fecha_Racao(int tempo)
{
    lcd.clear();
    int posicaoInicial = servo_9.read();
    lcd.print("Abrindo...");
    servo_9.write(180);
    delay(tempo);
    lcd.clear();
    lcd.print("Fechando...");
    servo_9.write(posicaoInicial);
    delay(2000);
    lcd.clear();
    lcd.print("Running...");
}
void Verifica_Nivel_Racao()
{
    if (analogRead(A3) > 600)
    {
        lcd.clear();
        lcd.print("Nivel de racao");
        lcd.setCursor(0, 1);
        lcd.print("Rasoavel!");
        delay(3000);
    }
    else if (analogRead(A2) > 600)
    {
        lcd.clear();
        lcd.print("Nivel de racao");
        lcd.setCursor(0, 1);
        lcd.print("Medio!");
        delay(3000);
    }
    else if (analogRead(A1) > 600)
    {
        lcd.clear();
        lcd.print("Nivel de racao");
        lcd.setCursor(0, 1);
        lcd.print("baixo!");
        delay(3000);
    }

    lcd.clear();
    lcd.print("Running...");
}
void loop()
{   
  	Serial.write(AbertoSempre);
    if(AbertoSempre){
        lcd.clear();
        lcd.print("Aberto sempre..");
        servo_9.write(180);
        delay(2000);
    }
    else{
        lcd.clear();
        lcd.print("Running...");
        Abre_Fecha_Racao(DelayFechamento);
        Verifica_Nivel_Racao();
        for (unsigned int i = 0; i < 36000; i++)
        {
            delay(Intervalo_Tempo);
            if (digitalRead(2) && analogRead(A1)<=600){ //Caso usuario informe que mais racao foi adicionada.
                lcd.clear();
                lcd.print("Racao adicionada");
                lcd.setCursor(0,1);
                lcd.print("!");
                delay(2000);
                lcd.clear();
                lcd.print("Running...");
            }
        }
    }
    Serial.println(analogRead(A0));
    //Serial.println(analogRead(A1));
    //Serial.println(servo_9.read());
}