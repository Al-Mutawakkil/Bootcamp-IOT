#include <DHT.h>
#include <UbidotsMicroESP8266.h>

#define DHTPIN 4 // mendefinisikan pin di nodemcu adalah 4, D2= 4
#define DHTTYPE DHT11 // mendefinisikan tipe dht yang kita gunakan

char auth[] = "Auth";
char ssid[] = "TOS";
char pass[] = "12345678";

DHT dht(DHTPIN, DHTTYPE);
Ubidots client(auth);
unsigned long last = 0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 dht.begin();
 delay(20); // delay 0.02 detik
 client.wifiConnection(ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-last>10000) {
    float hum = dht.readHumidity();
    float temp = dht.readTemperature();

    last = millis();
    client.add("Kelembapan", hum);
    client.add("Temperatur", temp);
    client.sendAll(true);
  }
}
