#define Button1 4
#define Button2 3
#define pot A0

//Motor 1(atas)
const int PWM1 = 5;
const int in4 = 6;
const int in3 = 7;

int powerOn = 0;
int isMaju = 1;

void setup()
{
  pinMode(PWM1, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  Serial.begin(9600);
  
  
  berhenti();
 
}

void maju(int kecepatan){

 digitalWrite(in4, LOW);
 digitalWrite(in3, HIGH);
 analogWrite(PWM1, kecepatan);
 delay(25);
        
}
void mundur(int kecepatan){
 digitalWrite(in4, HIGH);
 digitalWrite(in3, LOW);
 analogWrite(PWM1, kecepatan);
 delay(25);
        
}
void berhenti(){
  
 digitalWrite(in4, LOW);
 digitalWrite(in3, LOW);
 analogWrite(PWM1, 0);
 delay(25);
        

}
void loop(){
  Serial.println("btn1");Serial.println(digitalRead(Button1));
  Serial.println("btn2");Serial.println(digitalRead(Button2));
  if(digitalRead(Button1)== LOW){
    powerOn = !powerOn;
    delay(250);
  }
  
  if(powerOn && digitalRead(Button2)== LOW){
    isMaju = !isMaju;
    delay(250);
  }
   int speed = map(analogRead(pot), 0, 1023, 0, 255);
  
  if(!powerOn){
    berhenti();
  }else if(isMaju == 1){
    maju(speed);
  }else{
    mundur(speed);
  }
}