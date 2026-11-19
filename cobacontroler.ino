#include <PS4Controller.h>
#include <ps4.h>
#include <ps4_int.h>

int deadzone = 15;
const char* macAddress = "1c:c3:ab:bb:db:4a";

int applyDeadzone(int val) {

  if (abs(val) < deadzone) {
    return 0;
  }

  if (val >= deadzone) {
    return map(val, deadzone, 127, 1, 127);
  } else {
    return map(val, -127, -deadzone, -127, -1);
  }
}

void debugController() 
{
  if (PS4.event.button_down.cross)    Serial.println("X");
  if (PS4.event.button_down.square)   Serial.println("Square");
  if (PS4.event.button_down.triangle) Serial.println("Triangle");
  if (PS4.event.button_down.circle)   Serial.println("O");

  if (PS4.event.button_down.up)       Serial.println("D-Pad: UP");
  if (PS4.event.button_down.down)     Serial.println("D-Pad: Down");
  if (PS4.event.button_down.left)     Serial.println("D-Pad: Left");
  if (PS4.event.button_down.right)    Serial.println("D-Pad: Right");

  if (PS4.event.button_down.l1)       Serial.println("L1");
  if (PS4.event.button_down.r1)       Serial.println("R1");
  if (PS4.event.button_down.share)    Serial.println("Share");
  if (PS4.event.button_down.options)  Serial.println("Options");
  if (PS4.event.button_down.ps)       Serial.println("PS");

  if (PS4.event.button_down.r3) Serial.println("R3");
  if (PS4.event.button_up.l3) Serial.println("L3");
  
  int lx = applyDeadzone(PS4.LStickX());
  int ly = applyDeadzone(PS4.LStickY());
  int rx = applyDeadzone(PS4.RStickX());
  int ry = applyDeadzone(PS4.RStickY());

  if (lx != 0 || ly != 0) {
    Serial.printf("L-Stick -> X: %d | Y: %d\n", lx, ly);
  }

  if (rx != 0 || ry != 0) {
    Serial.printf("R-Stick -> X: %d | Y: %d\n", rx, ry);
  }

  int L2 = PS4.L2Value();
  int R2 = PS4.R2Value();

  if (L2 != 0) {
    Serial.printf("L2 Trigger -> %d\n", L2);
  }
  if (R2 != 0) {
    Serial.printf("R2 Trigger -> %d\n", R2);
  }
}

void notify() 
{
  debugController();
}

void onConnect() 
{
  Serial.println("Controller PS4 Berhasil Terhubung!");
}


void onDisconnect()
{
  Serial.println("Controller PS4 Terputus!");
}

void setup() 
{
  Serial.begin(115200);
  
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisconnect);

  PS4.begin(macAddress); 
  
  Serial.println("Menunggu koneksi dari PS4 Controller...");
}

void loop()
{
  delay(10); 
}