#include "Arduino.h"
#include "PCF8574.h"
#include <Adafruit_Sensor.h>

PCF8574 relayBoard(0x27);
//Relay 1
uint8_t lithiumVout = P7;
uint8_t relay2 = P6;
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
  relayBoard.pinMode(relay2, OUTPUT);
  relayBoard.pinMode(relay3, OUTPUT);
  relayBoard.pinMode(relay4, OUTPUT);
  relayBoard.pinMode(relay5, OUTPUT);
  relayBoard.pinMode(relay6, OUTPUT);
  relayBoard.pinMode(relay7, OUTPUT);
  relayBoard.pinMode(relay8, OUTPUT);
  Serial.println("Initializing the Relay Board..."); delay(500);
	if (relayBoard.begin()){
		Serial.print("Connected to Address: "); Serial.println("0x27");
	}else{
		Serial.println("Unable to connect to relay board. Check address and connections."); delay(500);
	}
}

void loop() {
  static int counter = 0;
  int batteryVoltage = analogRead(A0);
  bool alternator = false;
  if(batteryVoltage < 842) {
    alternator = false;
  } else if (batteryVoltage > 842) {
    alternator = true;
  }
  Serial.println(alternator);
  if(alternator) {
    relayBoard.digitalWrite(lithiumVout, HIGH);
  } else {
    relayBoard.digitalWrite(lithiumVout, LOW);
  }
  Serial.println(batteryVoltage);
  delay(13000);
}


 


    

