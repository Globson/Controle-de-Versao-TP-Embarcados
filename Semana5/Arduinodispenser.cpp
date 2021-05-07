#include <Servo.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
struct Configuracao
{
    long long unsigned int Intervalo_Tempo = 0;
    int DelayFechamento = 0;
    int AbertoSempre = 0;
};
struct Configuracao Conf_Recebida;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo servo_9;

void setup()
{
    lcd.begin(16, 2);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    servo_9.attach(9);
    servo_9.write(0);
    Serial.begin(9600);
    lcd.clear();
    lcd.print("Configure no ");
    lcd.setCursor(0, 1);
    lcd.print("mundo externo!");
    delay(3000);
    while (!(Serial.available() > 0))
    {
        delay(100);
    }
    if (Serial.available() > 0)
    {
        lcd.clear();
        lcd.print("Arduino");
        lcd.setCursor(0, 1);
        lcd.print("RECEBEU!!");
        Serial.readBytes((char *)&Conf_Recebida, sizeof(struct Configuracao));
        //Conf_Recebida = Serial.read();
        Serial.flush();
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
        lcd.print("Razoavel!");
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

    //Serial.write(AbertoSempre);
    if (Conf_Recebida.AbertoSempre)
    {
        lcd.clear();
        lcd.print("Aberto sempre..");
        servo_9.write(180);
        delay(2000);
    }
    else
    {
        lcd.clear();
        lcd.print("Running...");
        Abre_Fecha_Racao(Conf_Recebida.DelayFechamento);
        Verifica_Nivel_Racao();
        for (unsigned int i = 0; i < 36000; i++)
        {
            delay(Conf_Recebida.Intervalo_Tempo);
            if (digitalRead(2) && analogRead(A1) <= 600)
            { //Caso usuario informe que mais racao foi adicionada.
                lcd.clear();
                lcd.print("Racao adicionada");
                lcd.setCursor(0, 1);
                lcd.print("!");
                delay(2000);
                lcd.clear();
                lcd.print("Running...");
            }
        }
    }
    //Serial.println(analogRead(A0));
    //Serial.println(analogRead(A1));
    //Serial.println(servo_9.read());
}