#include <WiFi.h>

#define thumb 32
#define index 33
#define middle_finger 26


void setup() {
  Serial.begin(115200);
  SetupVibration();

  SetupWifi();
}

void loop() {
  WifiLoop();
}
