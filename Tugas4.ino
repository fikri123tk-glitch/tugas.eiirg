#define Button1 3
#define ledMerah 4    
#define ledKuning 2   
#define pot A0

const int PWM1 = 5;
const int in4 = 6;
const int in3 = 7;

volatile bool motorStop = false;
unsigned long waktuSebelumnya = 0;
const long interval = 1000;     
int stateLedKuning = LOW;

void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT); 
  pinMode(Button1, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(Button1), fungsiIsr, FALLING);
}

void fungsiIsr() {
  motorStop = !motorStop; 
}

void maju(int kecepatan) {
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  analogWrite(PWM1, kecepatan);
}

void mundur(int kecepatan) {
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  analogWrite(PWM1, kecepatan);
}

void berhenti() {
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);
  analogWrite(PWM1, 0);
}

void loop() {
 
  int nilaiPot = analogRead(pot);
  int kecepatan = map(nilaiPot, 0, 1023, 0, 255);

  
  if (motorStop == false) {
    maju(kecepatan); 
    digitalWrite(ledMerah, LOW);
  } else {
    berhenti();
    digitalWrite(ledMerah, HIGH);
  }
  unsigned long waktuSekarang = millis();
  
  if (waktuSekarang - waktuSebelumnya >= interval) {
    waktuSebelumnya = waktuSekarang; 
    stateLedKuning =!stateLedKuning;
    digitalWrite(ledKuning, stateLedKuning);
  }
}