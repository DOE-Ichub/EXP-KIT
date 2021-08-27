#include <BH1750.h>
#include <api.h>

Connec b;
mqt s;
BH1750 lightMeter;
String ssid = "";
String password = "";
String AccessKey = "xxxxxx"; 
unsigned long val = 0;
String Light()
{
   uint16_t lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  return String(lux); 
}
void setup()
{
  Serial.begin(115200);
  lightMeter.begin(); 
  b.beginwifi(ssid, password, AccessKey);
   
}
void loop()
{
  b.timeoutmqtt();
 if(((unsigned long)(millis()-val))>500)  { 
  s.sensorsent(68418,Light());  
 val = millis(); 
 }
}
