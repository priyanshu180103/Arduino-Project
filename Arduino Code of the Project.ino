#define BLYNK_TEMPLATE_ID "TMPLlw16kirx" 
#define BLYNK_DEVICE_NAME "priyanshu"
#define BLYNK_AUTH_TOKEN "ZVB78goF70eK00F-NRK-4PMigm6mto5"
#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SSID OF WIFI";
char pass[] = "PASSWORD OF WIFI";
const int BUZ = 5; 
int mq135 = A0; 
int data = 0;
BlynkTimer timer;
void sensorData()
{
data = analogRead(mq135); 
Blynk.virtualWrite(V0, data);
19 | P a g e
if (data > 200)
{
tone(BUZ,1000);
delay(1000);
}
else
{
digitalWrite(BUZ,LOW);
}
}
void setup()
{
Serial.begin(9600); 
Blynk.begin(auth, ssid, pass); 
timer.setInterval(1000L, sensorData);
pinMode(mq135, INPUT); // Set BUZ 
pinMode(BUZ, OUTPUT); // Set BUZ
}
void loop()
{
Blynk.run();
timer.run();
}
