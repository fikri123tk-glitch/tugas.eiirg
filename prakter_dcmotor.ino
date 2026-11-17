// Motor 1 (Kanan)   
#define M1_IN_A   25
#define M1_IN_B   33
#define M1_PWM    32

// Motor 2 (Kiri)
#define M2_IN_A   14
#define M2_IN_B   27
#define M2_PWM    26

void maju(int kecepatan)
{
digitalWrite(M1_IN_B, LOW);
digitalWrite(M1_IN_A, HIGH);
analogWrite(M1_PWM, kecepatan);
delay(25);

digitalWrite(M2_IN_B, LOW);
digitalWrite(M2_IN_A, HIGH);
analogWrite(M2_PWM, kecepatan);
 delay(25);
}

void mundur(int kecepatan) 
{
  digitalWrite(M1_IN_B, HIGH);
  digitalWrite(M1_IN_A, LOW);
  analogWrite(M1_PWM, kecepatan);
  delay(25);

  digitalWrite(M2_IN_B, HIGH);
  digitalWrite(M2_IN_A, LOW);
  analogWrite(M2_PWM, kecepatan);
  delay(25);
}

void belokKiri(int kecepatan) 
{
 digitalWrite(M1_IN_B, LOW);
 digitalWrite(M1_IN_A, HIGH);
 analogWrite(M1_PWM, kecepatan);
 delay(25);

digitalWrite(M2_IN_B, LOW);
digitalWrite(M2_IN_A, LOW);
analogWrite(M2_PWM, kecepatan);
delay(25);
}

void belokKanan(int kecepatan) 
{
  digitalWrite(M1_IN_B, LOW);
 digitalWrite(M1_IN_A, LOW);
 analogWrite(M1_PWM, kecepatan);
 delay(25);

digitalWrite(M2_IN_B, LOW);
digitalWrite(M2_IN_A, HIGH);
analogWrite(M2_PWM, kecepatan);
delay(25);
}

void berhenti() 
{
  digitalWrite(M1_IN_B, LOW);
  digitalWrite(M1_IN_A, LOW);
  analogWrite(M1_PWM, 0);
  delay(25);

  digitalWrite(M2_IN_B, LOW);
  digitalWrite(M2_IN_A, LOW);
  analogWrite(M2_PWM, 0);
  delay(25);
}

void setup()
{
  // Inisialisasi pin Motor 1 (Kanan)
  pinMode(M1_IN_A, OUTPUT);
  pinMode(M1_IN_B, OUTPUT);
  pinMode(M1_PWM, OUTPUT);
  
  // Inisialisasi pin Motor 2 (Kiri)
  pinMode(M2_IN_A, OUTPUT);
  pinMode(M2_IN_B, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
}

void loop() 
{
 int kecepatan = 200;

    maju(kecepatan);
    delay(2000);
    
    mundur(kecepatan);
    delay(2000);
    
    belokKiri(kecepatan);
    delay(2000);
    
    belokKanan(kecepatan);
    delay(2000);
    
    berhenti();
    delay(2000);
}