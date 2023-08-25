
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL3CkIZFISg"
#define BLYNK_TEMPLATE_NAME "AGUA"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG
//#include <SimpleTimer.h>

//#include <BlynkTimer.h>


// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include "DHT.h"
#define DHTPIN 4 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int t, h, s;
BlynkTimer timer;
BLYNK_WRITE(V0)
{
  if(param.asInt()==1){
    digitalWrite(16, HIGH);
  }
  else{
    digitalWrite(16, LOW);
  }
}

/*BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);
  
}
*/
void myTimer() 
{
  // This function describes what will happen with each timer tick
  // e.g. writing sensor value to datastream V5
  Blynk.syncVirtual(V0);
  Blynk.virtualWrite(V3, s);  
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, t);
}

void setup()
{
  pinMode(16, OUTPUT); // Initialise digital pin 0 as an output pin
  Serial.begin(115200);
  dht.begin();
  delay(2000);

  BlynkEdgent.begin();
  timer.setInterval(1000L, myTimer); 
}

void loop() {
  s= ( 100.00 - ( (analogRead(A0)/1023.00) * 100.00 ) );
  h = dht.readHumidity();
  t = dht.readTemperature(); 
  Serial.print("soil= ");
  Serial.println(s);
  Serial.println("temp= ");
  Serial.println(t);
  Serial.println("hum= ");
  Serial.println(h);
  BlynkEdgent.run();
  timer.run(); 
}