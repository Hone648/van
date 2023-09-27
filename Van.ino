#include "Arduino.h"
#include "PCF8574.h"
#include <Adafruit_Sensor.h>

PCF8574 relayBoard(0x27);
uint8_t lithiumVout = P7;
uint8_t leadAcidVout = P6;
uint8_t relay3 = P5;
uint8_t relay4 = P4;
uint8_t relay5 = P3;
uint8_t relay6 = P2;
uint8_t relay7 = P1;
uint8_t relay8 = P0;
uint32_t delayMS;

void setup() {
  Serial.begin(115200);
  pinMode(A6, INPUT);
  relayBoard.pinMode(lithiumVout, OUTPUT);
  relayBoard.pinMode(leadAcidVout, OUTPUT);
  relayBoard.pinMode(relay3, OUTPUT);
  relayBoard.pinMode(relay4, OUTPUT);
  relayBoard.pinMode(relay5, OUTPUT);
  relayBoard.pinMode(relay6, OUTPUT);
  relayBoard.pinMode(relay7, OUTPUT);
  relayBoard.pinMode(relay8, OUTPUT);
  Serial.print("Initializing the Relay Board."); delay(500);
	if (relayBoard.begin()){
		Serial.print("."); delay(500);
    Serial.println(". ...and I lava you!"); delay(500);
	}else{
		Serial.println("Unable to connect to relay board. Check address and connections."); delay(500);
	}
}


void loop() {
  bool alternator = true;
  
  relayBoard.digitalWrite(lithiumVout, HIGH);
  delay(2000);
}


 


    

