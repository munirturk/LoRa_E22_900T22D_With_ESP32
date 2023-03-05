#include "Arduino.h"
#include "LoRa_E22.h"

LoRa_E22 e22ttl(&Serial2, 18, 26, 19); //  RX AUX M0 M1

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
  while (e22ttl.available()  > 1) 
  {
    ResponseStructContainer rsc = e22ttl.receiveMessage(sizeof(veri));
    struct veri datas = *(veri*) rsc.data;
    Serial.print("Alinan mesaj: ");
    Serial.println(*(float*)(datas.mesaj));
  
    Serial.println("-------------------------------");
    rsc.close();
  }
}
