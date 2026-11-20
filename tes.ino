// C++ code
//
const int PWM2 = 9;
const int in1 = 10;
const int in2 = 8;
#define btn1 4
#define btn2 5

int btn1State = 0;
int btn2State = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(PWM2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void maju(){      
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 analogWrite(PWM2, 255);
 delay(25);
}
void mundur(){
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 analogWrite(PWM2, 255);
 delay(25);
}
void berhenti(){
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 analogWrite(PWM2, 0);
 delay(25);
}

void loop()
{
   btn1State = digitalRead(btn1);
   btn2State = digitalRead(btn2);
  if( btn1State == LOW){
    maju();
  }else if ( btn2State == LOW){ 
    mundur();
  }else{
    berhenti();
  }
 	Serial.println(btn1State);
  	delay(500);
  	Serial.println(btn2State);
  	delay(500);
  
}