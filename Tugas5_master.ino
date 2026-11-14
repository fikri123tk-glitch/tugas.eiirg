// C++ code
//
#define trig 9
#define echo 8
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  Wire.begin();
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  delay(1000);
  lcd.clear();
  
}

void loop()
{
  
  long jarak = bacaUltra();
  
  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(jarak);
  lcd.print(" cm   ");
  delay(1000);
  
  lcd.setCursor(0, 1);
  
  if(jarak <30)
  {
    lcd.print("Motor: MUNDUR ");
    Serial.write('A');
  }
  else
  {
    lcd.print("Motor: MAJU   ");
    Serial.write('S');
  }
  delay(200);   
}

long bacaUltra()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long durasi = pulseIn(echo, HIGH, 30000);
  return durasi / 29/ 2;
}
