//Pin motor, urutan: FL, FR, BL, BR
int ENA[4] = {32, 4, 23, 14}; //pin PWM
int INA[4] = {25, 16, 18, 27}; //IN maju
int INB[4] = {33, 17, 19, 26}; //pin mundur

//fungsi untuk menggerakkan motor dengan pwm
void motor(int i, int pwm) {
  pwm = constrain(pwm, -255, 255); // batas pwm agar tidak over
  digitalWrite(INA[i], pwm > 0); //maju
  digitalWrite(INB[i], pwm < 0); //mundur
  analogWrite(ENA[i], abs(pwm)); //nilai absolut agar tidak float(desimal)
}

//kinematika mecanum
//maju : + maju, -mundur
//geser ; + kanan, - kiri
//putar : + kanan, - kiri
void gerak(int y, int x, int z) {
  motor(0, y + x + z); // FL (Depan Kiri)
  motor(1, y - x - z); // FR (Depan Kanan)
  motor(2, y - x + z); // BL (Belakang Kiri)
  motor(3, y + x - z); // BR (Belakang Kanan)
}

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ENA[i], OUTPUT);
    pinMode(INA[i], OUTPUT);
    pinMode(INB[i], OUTPUT);
  }
  delay(3000);
}

void loop() {
  gerak(0, 200, 200); //maju
  delay(5000);
}