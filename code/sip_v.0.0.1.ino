#include <DHT.h>
#define DHTTYPE DHT11
#define humt 2
DHT dht(humt, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  humisens();
}
float humisens()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C\n "));
 
}