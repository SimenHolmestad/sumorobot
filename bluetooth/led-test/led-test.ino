/* 
 *  Hvis arduinoen kjører dette programmet kan du få den til å slå av og
 *  på pin-7 ved å sende inn p og a i serialTools
 */

#include <SoftwareSerial.h>
#include <PLabBTSerial.h>

#define txPin 2  // Tx pin on Bluetooth unit
#define rxPin 3  // Rx pin on Bluetooth unit

const int ledPin = 7;

PLabBTSerial btSerial(txPin, rxPin);

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);   // Open serial communication to Serial Monitor
    btSerial.begin(9600); // Open serial communication to Bluetooth unit
}

void writeStringToSerial (String string) {
  for (int x = 0; x < string.length(); x++) {
    btSerial.write(string.charAt(x));
  }
  btSerial.write('\n');
}

void loop() {
    while (btSerial.available()) { // If input available from Bluetooth unit
      char c = btSerial.read();    // Read character from from Bluetooth unit
      if (c == 'p') {
        digitalWrite(ledPin, HIGH);
        writeStringToSerial("Pin activated");
      } else if (c == 'a') {
        digitalWrite(ledPin, LOW);
        writeStringToSerial("Pin deactivated");
      } else if ((int) c != 0) {
        writeStringToSerial("Ulovlig kommando");             // Write that character to Serial Monitor 
      }
    };
    while (Serial.available()) { // If input available from Serial Monitor
      char c = Serial.read();    // Read character from from Serial Monitor
      btSerial.write(c);         // Write that character to Bluetooth unit
    };
}


