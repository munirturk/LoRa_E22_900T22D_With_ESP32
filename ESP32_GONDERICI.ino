// SENDER

#include <Arduino.h>
#include <Wire.h>
#include <LoRa_E22.h>

LoRa_E22 e22ttl(&Serial2, 18, 26, 19);
struct veri
{
  float mesaj[6];
} datas;

void setup()
{
  Serial.begin(9600);
  e22ttl.begin();
}

void loop() 
{
  // Temperature
  *(float*)(datas.mesaj) = 5.3;
 
  ResponseStatus rs = e22ttl.sendFixedMessage(0, 43, 23, &datas, sizeof(veri)); // Adress: 43 - Channel: 23
  
  Serial.print("Mesaj gonderildi: ");
  Serial.print(*(float*)(datas.mesaj));
  delay(3000);
}
