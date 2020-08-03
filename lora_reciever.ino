#include <SPI.h>

#include <LoRa.h>

#include <Wire.h>

#include <WiFi.h>

#include <WiFiMulti.h>

Const char* ssid = “ECE”; 

Const char* password = “123456789”;

Const char* host = “api.thingspeak.com”;

String w_api_key = “L8DP0PN9S5Z7NBZC”;

// RFM9x

#define RFM95_CS

SSD1306 display(0x3C, 21, 22);

Void setup() {

Display.init();

Display.flipScreenVertically();

Display.setTextAlignment(TEXT_ALIGN_CENTER);

Display.setFont(ArialMT_Plain_16);

//setup LoRa transceiver module

LoRa.setPins(RFM95_CS, RFM95_RST, RFM95_INT);

While (!LoRa.begin(0)) 

{

Display.drawString(64, 40, “LoRa Not Initilized” );

Display.display();

 }

 // Change sync word (0xF3) to match the receiver

// The sync word assures you don’t get LoRa messages from other LoRa 

Transceivers

 // ranges from 0-0xFF

 LoRa.setSyncWord(0xF3);

 Display.clear();

 Display.drawString(64, 0, “LoRa Init “);

 //display.drawString(64, 20, “OK”);

 Display.display();

 Delay(2000);

 Display.clear(); 

 Display.drawString(64, 20, “Gateway Node”);

 Display.display();

 Delay(2000);

 }

 Void loop() {

 // try to parse packet

 Int packetSize = LoRa.parsePacket();

 If (packetSize) { 

 Display.clear();

 Display.drawString(64, 0, “Received data”);

 Display.display();

 Delay(2000);

 // read packet

 While (LoRa.available()) 

 {

 String LoRaData = LoRa.readString();

 //display.clear();

Display.drawString(64, 20, “pH Value: “ + String (LoRaData));

 //display.drawString(64, 20, String (LoRaData));

 Display.display();

 Delay(2000);

 }

 }

 }

 Void loop() {

Unsigned long s = 0;

 For(unsigned int i = 0; i<50; i++)

 {

 S += analogRead(analogInPin);

 }

 S /=50;

 Float finalpH = 12.27;

 Display.clear();

 //display.drawString(0, 0, “ADC Value:” + String (s));

 Float phVol = (float)((3.296 / 4095.0) * (s * 1.495)); 

 //display.drawString(0, 20, “pH Volt: “ + String ( phVol));

 //float final = ((-0.0456 * pHVol ) + 1.1010);

// float finalpH = (float)((-5.70 * phVol) + 21.34); 

 Display.drawString(64, 20, “pH Value: “ + String (finalpH));

 //display.drawString(64, 0, “Sending Data”);

 //display.drawString(64, 20, finalpH);

 Display.display();

 // display.clear();

Delay(2000);

 LoRa.beginPacket();

 LoRa.print(finalpH);

 LoRa.endPacket();

 Delay(10000);

 }
