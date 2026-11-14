// C++ code
//
const int PWM1 = 3;
const int in4 = 4;
const int in3 = 5;

const int PWM2 = 9;
const int in1 = 10;
const int in2 = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(PWM1, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  
  pinMode(PWM2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
}

void maju(){

 digitalWrite(in4, LOW);
 digitalWrite(in3, HIGH);
 analogWrite(PWM1, 255);
 delay(25);
        
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 analogWrite(PWM2, 255);
 delay(25);
}
void mundur(){
 digitalWrite(in4, HIGH);
 digitalWrite(in3, LOW);
 analogWrite(PWM1, 255);
 delay(25);
        
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 analogWrite(PWM2, 255);
 delay(25);
}
void berhenti(){
  
 digitalWrite(in4, LOW);
 digitalWrite(in3, LOW);
 analogWrite(PWM1, 0);
 delay(25);
        
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 analogWrite(PWM2, 0);
 delay(25);
}

void loop()
{
  while(Serial.available()){
    char data = Serial.read();
    Serial.println(data);
    if(data == 'A')
    {
      mundur();
    }else if (data == 'S')
    {
      maju();
    }else{
      berhenti();
    }
  }
}