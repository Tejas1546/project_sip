#include <DHT.h>
#define DHTTYPE DHT11
#define humt 2    //air humidity and temperature
#define pump 5    //relay control
#define soilp 4   //soil moisture sensor power control
#define soild 3   //soil moisture digital pin
#define soila A0  //soil moisture analog pin
DHT dht(humt, DHTTYPE);
float t;  //temperature
float h;  //humidity
int m;    //soil moisture
int state;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.begin(38400);
  pinMode(pump,OUTPUT);
  digitalWrite(pump,LOW);   //on boot set pump off
  pinMode(soilp,OUTPUT);
  digitalWrite(soilp,LOW);  //on boot set soil moisture sensor off
  pinMode(soild,INPUT);
  dht.begin();

}

void loop() 
{
  if(Serial.available() > 0)
  {
    state = Serial.read();
  }
  if (state == '0') 
  {
  relay();
  Serial.println("Pump: OFF");
  state=0; 
  }
  else 
  if (state == '1') 
  {
  relay();
  Serial.println("pump: ON");
  state=1;
  }
  //delay(2000);
  //t=humitemp();
  //h=humi();
}
float humitemp()
{
  delay(20);
  float temp = dht.readTemperature();
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C"));
  return temp;
}
float humi()
{
  delay(20);
  float hum = dht.readHumidity();
  Serial.print(F("  Humidity: "));
  Serial.print(h);
  Serial.print(F("°%\n "));
  return hum;
}

void relay()    //turns pump on or off
{
  if(digitalRead(pump)==LOW)
  digitalWrite(pump,HIGH);
  else
  digitalWrite(pump,LOW);
}

int soilsens()    //reads soil moisture and has backup
{
  digitalWrite(soilp,HIGH);
  delay(10);
  m=analogRead(soila);
  digitalWrite(soilp,LOW);
  return m;
}
