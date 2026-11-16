#include <Wire.h>
#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  // [BEDA DARI UNO]: Baud rate standar ESP32 115200 (Uno umumnya 9600).
  Serial.begin(115200);

  // [BEDA DARI UNO]: Inisialisasi pin I2C ESP32 pada GPIO 21 (SDA) dan GPIO 22 (SCL).
  // Di Arduino Uno pin I2C selalu tetap di A4 (SDA) dan A5 (SCL).
  Wire.begin(21, 22);

  if (!lox.begin()) {
    Serial.println("VL53L0X gagal inisialisasi! Cek kabel VCC (3.3V), GND, SDA (21), & SCL (22).");
    while (1) {
      // [BEDA DARI UNO]: Menjaga scheduler RTOS ESP32 tetap bernapas saat program berhenti di loop error.
      delay(10);
    }
  }
  Serial.println("VL53L0X Siap!");
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) { // Status 4 berarti objek di luar jangkauan sensor
    Serial.print("Jarak Laser: ");
    Serial.print(measure.RangeMilliMeter);
    Serial.println(" mm");
  } else {
    Serial.println("Di luar jangkauan");
  }

  delay(200);
}