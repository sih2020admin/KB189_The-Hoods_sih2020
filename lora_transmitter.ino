#include <SPI.h>

#include <LoRa.h>

#include <Wire.h>

Int counter = 0;

Const int analogInPin = 36;

Int sensorValue = 0;

Unsigned long int avgValue;

Float v, b, x, m;

//double v;

Int temp, i;

//unsigned long elapsedTime, StartTime, Interval = 10; // in sec

//unsigned int AVG_CNT = 10;

//int16_t packetnum = 0; // packet counter,

SSD1306 display(0x3C, 21, 22);

Void setup() {

 Display.init();

 Display.flipScreenVertically();

 Display.setTextAlignment(TEXT_ALIGN_CENTER);

 Display.setFont(ArialMT_Plain_16);

 //display.clear();

 Display.drawString(64, 0, “Configuring”);

 Display.drawString(64, 20, “Device”);

 Display.display();

 //setup LoRa transceiver module

LoRa.setPins(RFM95_CS, RFM95_RST, RFM95_INT);

 While (!LoRa.begin(0)) {

 Display.clear();

Display.drawString(64, 0, “LoRa”);

 Display.drawString(64, 20, “Init Failed”);

 Display.display();

 Delay(1000);

 }

 // Change sync word (0xF3) to match the receiver

 // The sync word assures you don’t get LoRa messages from other LoRa 

Transceivers

 // ranges from 0-0xFF

 LoRa.setSyncWord(0xF3);

 //Serial.println(“LoRa Initializing OK!”);

 Display.clear();

 Display.drawString(64, 0, “LoRa Init”);

 Display.display();

 Delay(2000); 

Display.clear();

 Display.drawString(64, 20, “Sensor Node”);

 Display.display();

 Delay(2000); 
}
