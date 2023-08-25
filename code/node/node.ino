//Sending Data from Arduino to NodeMCU Via Serial Communication
//NodeMCU code

//Include Lib for Arduino to Nodemcu
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//D6 = Rx & D5 = Tx
SoftwareSerial nodemcu(12, 14);


void setup() {
  // Initialize Serial port
  Serial.begin(115200);
  nodemcu.begin(115200);
  while (!Serial) continue;
}

void loop() {
  
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(nodemcu);

  if (data == JsonObject::invalid()) {
    //Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
  }

  Serial.println("JSON Object Recieved");
  Serial.print("Recieved Humidity:  ");
  int hum = data["humidity"];
  Serial.println(hum);
  Serial.print("Recieved Temperature:  ");
  int temp = data["temperature"];
  Serial.println(temp);
  Serial.print("soil moisture:  ");
  int m = data["soilm"];
  Serial.println(m);
  Serial.println("-----------------------------------------");
}