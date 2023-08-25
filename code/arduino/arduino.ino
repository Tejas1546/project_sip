//Sending Data from Arduino to NodeMCU Via Serial Communication
//Arduino code

//DHT11 Lib
#include <DHT.h>
#define humt 3    //air humidity and temperature
#define soilp 2   //soil moisture sensor power control
#define soild 4   //soil moisture digital pin
#define soila A0  //soil moisture analog pin
#define DHTTYPE DHT11 // DHT 11
DHT dht(humt, DHTTYPE);  

//Arduino to NodeMCU Lib
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//Initialise Arduino to NodeMCU (5=Rx & 6=Tx)
SoftwareSerial nodemcu(5, 6);

//Initialisation of sensors
int temp;
int hum;
int m;

void setup() {
  Serial.begin(115200);
  pinMode(soilp,OUTPUT);
  digitalWrite(soilp,LOW);  //on boot set soil moisture sensor off
  pinMode(soild,INPUT);
  dht.begin();
  nodemcu.begin(115200);
  delay(2000);

  Serial.println("Program started");
}

void loop() {

  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject();

  //Obtain Temp and Hum data
  dht11_func();
  digitalWrite(soilp,HIGH);
  delay(50);
  m = ( 100.00 - ( (analogRead(soila)/1023.00) * 100.00 ) );
  Serial.print("Soil moisture : ");
  Serial.println(m);


  //Assign collected data to JSON Object
  data["humidity"] = hum;
  data["temperature"] = temp;
  data["soilm"] = m; 

  //Send data to NodeMCU
  data.printTo(nodemcu);
  jsonBuffer.clear();

  delay(20000);
}

void dht11_func() {

hum = dht.readHumidity();
temp = dht.readTemperature();
Serial.print("Humidity: ");
Serial.println(hum);
Serial.print("Temperature: ");
Serial.println(temp);

}