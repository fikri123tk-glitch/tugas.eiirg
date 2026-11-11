#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define pinPot A0
#define pinButton 7

bool modeKedip = false;
bool lastButtonState = HIGH;
int nilaiPotSebelumnya = -1;

int hitungKecepatan(){
  int nilai = analogRead(pinPot);
  return map(nilai, 0, 1023, 100, 1000);
}

void kedipBareng() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(led1, HIGH); digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH); digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    delay(300);
    digitalWrite(led1, LOW); digitalWrite(led2, LOW);
    digitalWrite(led3, LOW); digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(300);
  }
}

void setup() {
  pinMode(led1, OUTPUT); pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT); pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int pot = analogRead(pinPot);
  if (pot != nilaiPotSebelumnya) {
    Serial.print("Pot: "); Serial.print(pot);
    Serial.print(" | Delay: "); Serial.println(hitungKecepatan());
    nilaiPotSebelumnya = pot;
  }

  bool currentButton = digitalRead(pinButton);
  if (currentButton == LOW && lastButtonState == HIGH) {
    modeKedip = !modeKedip;
    if (modeKedip) Serial.println("Mode Kedip");
    else Serial.println("Mode Berjalan");
    delay(200);
  }
  lastButtonState = currentButton;

  if (modeKedip) {
    kedipBareng();
  } else {
    digitalWrite(led1, HIGH); delay(hitungKecepatan()); digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH); delay(hitungKecepatan()); digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH); delay(hitungKecepatan()); digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH); delay(hitungKecepatan()); digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH); delay(hitungKecepatan()); digitalWrite(led5, LOW);
  }
}