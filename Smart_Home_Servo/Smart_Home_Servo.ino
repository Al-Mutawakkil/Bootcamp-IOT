
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h> //File untuk model wifi
#include <BlynkSimpleEsp8266.h> //File untuk modul blynk
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "IEb1vX3ifCEjrpyARkpuyR7h1L02RGZz";
char ssid[] = "Bangganteng";
char pass[] = "faruqiii";

Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write(param.asInt());
} // Fungsi Blynk untuk mengatur nilai servo dengan pin virtual V1 yang ada pada aplikasi blynk

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  gerak_servo.attach(2); // Setting pin gpio 2 ke servo, D4 = 2,
}

void loop()
{
  Blynk.run();
}
