#define BLYNK_PRINT Serial

#include <DHT.h>
#include <ESP8266WiFi.h> //File untuk model wifi
#include <BlynkSimpleEsp8266.h> //File untuk modul blynk

char auth[] = "ApqCBosME-KwDqX8JGzAwNsBWWC7JeY4";
char ssid[] = "TOS";
char pass[] = "12345678";

#define DHTPIN 14
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read temp and Humidity");
    return;
  }
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000, sendSensor);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}
