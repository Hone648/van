#include "Arduino.h"
#include "PCF8574.h"
#include <Adafruit_Sensor.h>

PCF8574 relayBoard(0x27);
//Relay 1
uint8_t lithiumVout = P7;
// uint8_t relay2 = P6;
// uint8_t relay3 = P5;
// uint8_t relay4 = P4;
// uint8_t relay5 = P3;
// uint8_t relay6 = P2;
// uint8_t relay7 = P1;
// uint8_t relay8 = P0;
// uint32_t delayMS;
int leadAcidSense = A0;

void setup() {
  Serial.begin(115200);
  pinMode(leadAcidSense, INPUT);
  relayBoard.pinMode(lithiumVout, OUTPUT);
  // relayBoard.pinMode(relay2, OUTPUT);
  // relayBoard.pinMode(relay3, OUTPUT);
  // relayBoard.pinMode(relay4, OUTPUT);
  // relayBoard.pinMode(relay5, OUTPUT);
  // relayBoard.pinMode(relay6, OUTPUT);
  // relayBoard.pinMode(relay7, OUTPUT);
  // relayBoard.pinMode(relay8, OUTPUT);
  Serial.println("Initializing the Relay Board..."); delay(500);
	if (relayBoard.begin()){
		Serial.print("Connected to Address: "); Serial.println("0x27");
	}else{
		Serial.println("Unable to connect to relay board. Check address and connections."); delay(500);
	}
}

void loop() {
  int leadAcidVoltage = analogRead(leadAcidSense);
  bool alternator = false;
  // If the alternator is on it will switch all systems to run off the alternator
  // thus allowing the lithium to charge off solar without any load.
  if(leadAcidVoltage < 842) {
    alternator = false;
  } else if (leadAcidVoltage > 842) {
    alternator = true;
  }
  if(alternator) {
    //if alternator is on we always want to run off that
    relayBoard.digitalWrite(lithiumVout, HIGH);
  } else {
    //if alternator is off we want to run off the lead acid until the voltage drops to 12.7V(822)
    //in which case we switch to the lithium battery
    if (leadAcidVoltage < 822) {
      relayBoard.digitalWrite(lithiumVout, LOW);
    } else {
      relayBoard.digitalWrite(lithiumVout, HIGH);
    }
  }
  delay(13000);
}


 


    

