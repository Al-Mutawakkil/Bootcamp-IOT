#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h> //File untuk model wifi
#include <BlynkSimpleEsp8266.h> //File untuk modul blynk


void setup() { // fungsi utama, sekali dijalankan
  Serial.begin(9600); // untuk monitor di serial print
  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token, wifi, dan paswordnya
}
void loop() { // fungsi utama, berulang kali dijalankan
  Blynk.run(); // perintah untuk menjalankan blynk
}
