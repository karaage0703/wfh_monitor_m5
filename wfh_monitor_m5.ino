#include <M5Stack.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include "time.h"
#include <BlynkSimpleEsp32.h>

#define BLYNK_PRINT Serial
const char* auth   = "********";
const char* ssid     = "********";
const char* password = "********";

int brightness = 200;

void setup(){
  M5.begin();
  // Serial.begin(115200);
  delay(10);

  // Blink起動
  Blynk.begin(auth, ssid, password);

  M5.Speaker.begin();
  M5.Power.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.setBrightness(brightness);

  M5.Lcd.fillScreen(BLUE);
  M5.Lcd.setTextSize(5);
  M5.Lcd.setCursor(50, 100);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.print("OFF AIR\n"); 
}

void loop(){
    // Blynk Setting
    Blynk.run();

    M5.update();
}

BLYNK_WRITE(V0){
  int val = param[0].asInt();
  M5.Lcd.setBrightness(brightness);
  if(val == 0){
    M5.Lcd.fillScreen(BLUE);
    M5.Lcd.setTextSize(5);
    M5.Lcd.setCursor(50, 100);
    M5.Lcd.setTextColor(BLACK);
    M5.Lcd.print("OFF AIR\n"); 
    delay(1000);    
  }
  if(val == 1){
    M5.Lcd.fillScreen(RED);
    M5.Lcd.setTextSize(5);
    M5.Lcd.setCursor(70, 100);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.print("ON AIR\n"); 
    delay(1000);
  }
}

BLYNK_WRITE(V1){
  int val = param[0].asInt();
  if(val == 1){
    M5.Lcd.setBrightness(0);
    M5.Lcd.fillScreen(BLACK);
    delay(1000);
  }
}
