// C++ code
//
#define pot A0
#include <Servo.h>
#define servo 9
#define Button 5
#define Buzzer 6
#define ledRed 4
#define ledYellow 3
#define ledGreen 2


Servo servoku;
int Sudutservo = 90;
int lastButton = HIGH;
bool modeTengah = false;
int nilaipotTersimpan = 0;

void setup()
{
  Serial.begin(9600);
  servoku.attach(servo);
  servoku.write(90);
  
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  
  pinMode(Button, INPUT_PULLUP);
}

void loop() {
  int analog1 = analogRead(pot);
  int currentButton = digitalRead(Button);
  
  
  if(currentButton == LOW && lastButton == HIGH){
    modeTengah = true;
    nilaipotTersimpan = analog1;
    Serial.println("BUTTON DITEKAN");
    Serial.println(nilaipotTersimpan);
    delay(300);
  }
  lastButton = currentButton;
  

  if (modeTengah == true) {
    Sudutservo = 90;
    
    if (abs(analog1 - nilaipotTersimpan) > 50) {
      modeTengah = false;
      Serial.println(">>> Kontrol dikembalikan ke Potensiometer.");
    }
    
  } else {
   
    Sudutservo = map(analog1, 0, 1023, 15, 165); 
    Sudutservo = constrain(Sudutservo, 15, 165);
  }
  

  servoku.write(Sudutservo);
  
  digitalWrite(ledGreen, LOW); 
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  
  if(Sudutservo >= 15 && Sudutservo <= 60){
    digitalWrite(ledGreen, HIGH);
  } else if(Sudutservo >= 61 && Sudutservo <= 120){
    digitalWrite(ledYellow, HIGH);
  } else if(Sudutservo >= 121 && Sudutservo <= 165){
    digitalWrite(ledRed, HIGH);
  }
  
  
  if(Sudutservo == 15 || Sudutservo == 165){
    tone(Buzzer, 1500);
  } else {
    noTone(Buzzer);
  }
  
  delay(50);
}