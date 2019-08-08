#include "Wire.h"
#include <LiquidCrystal_I2C.h> //Biblioteca do visor
LCD i2C
#define DS1307_ADDRESS 0x68 // Modulo RTC no endereco
0x68
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
// Modulo I2C display no endereco 0x27
byte zero = 0x00;
void setup(){
begin();
backlight(); //Inicia o visor LCD com a luz ligada
begin (16,2);
begin(9600); //Inicia a porta serial
//A linha de comando abaixo serve para que você possa
confirar a hora e data do seu modulo RTC
// SelecionaDataeHora();
}
void loop()
{
// Le os valores (data e hora) do modulo DS1307
beginTransmission(DS1307_ADDRESS);
write(zero);
endTransmission();
requestFrom(DS1307_ADDRESS, 7);
int segundos = ConverteparaDecimal(Wire.read());
int minutos = ConverteparaDecimal(Wire.read());
int horas = ConverteparaDecimal(Wire.read() &
0b111111);
int diadasemana = ConverteparaDecimal(Wire.read());
int diadomes = ConverteparaDecimal(Wire.read());
int mes = ConverteparaDecimal(Wire.read());
int ano = ConverteparaDecimal(Wire.read());
// Mostra os dados no display
setCursor(0,0);
print(" ");
// Acrescenta o 0 (zero) se a hora for menor do que 10
if (horas <10)
print("0");
print(horas);
print(":");
// Acrescenta o 0 (zero) se minutos for menor do que
10
if (minutos < 10)
print("0");
print(minutos);
print(":");
// Acrescenta o 0 (zero) se minutos for menor do que
10
if (segundos < 10)
print("0");
print(segundos);
setCursor(2,1);
// Mostra o dia da semana
switch(diadasemana)
{
case 0:lcd.print("Dom");
break;
case 1:lcd.print("Seg");
break;
case 2:lcd.print("Ter");
break;
case 3:lcd.print("Qua");
break;
case 4:lcd.print("Qui");
break;
case 5:lcd.print("Sex");
break;
case 6:lcd.print("Sab");
}
setCursor(6,1);
// Acrescenta o 0 (zero) se dia do mes for menor do que
10
if (diadomes < 10)
print("0");
print(diadomes);
print("/");
// Acrescenta o 0 (zero) se mes for menor do que 10
if (mes < 10)
print("0");
print(mes);
print("/");
print(ano);
}
void SelecionaDataeHora() //Seta a data e a hora do
DS1307
{
byte segundos = 10; // Valores de 0 a 59
byte minutos = 05; //Valores de 0 a 59
byte horas = 22; //Valores de 0 a 23
byte diadasemana = 2; //Valores de 0 a 6 - 0=Domingo,
1 = Segunda, etc.
byte diadomes = 25; //Valores de 1 a 31
byte mes = 10; //Valores de 1 a 12
byte ano = 16; //Valores de 0 a 99
beginTransmission(DS1307_ADDRESS);
write(zero); //Stop no CI para que o mesmo possa
receber os dados
//As linhas abaixo escrevem no CI os valores de
//data e hora que foram colocados nas variaveis acima
write(ConverteParaBCD(segundos));
write(ConverteParaBCD(minutos));
write(ConverteParaBCD(horas));
write(ConverteParaBCD(diadasemana));
write(ConverteParaBCD(diadomes));
write(ConverteParaBCD(mes));
write(ConverteParaBCD(ano));
write(zero);
endTransmission();
}
byte ConverteParaBCD(byte val)
{
//Converte o número de decimal para BCD
return ( (val/10*16) + (val%10) );
}
byte ConverteparaDecimal(byte val)
{
//Converte de BCD para decimal
return ( (val/16*10) + (val%16) );
}
