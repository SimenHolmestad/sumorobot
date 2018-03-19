
/* 
 */

#include <SoftwareSerial.h>
#include <PLabBTSerial.h>

#define txPin 2  // Tx pin on Bluetooth unit
#define rxPin 3  // Rx pin on Bluetooth unit


PLabBTSerial btSerial(txPin, rxPin);

void BTSerialMessageReceived(String msgString) {
  Serial.println(msgString);
  BTSerialSendMessage(msgString);
}

//...........................................................................
// Always include this method.
// It reads from the BT port and calls BTSerialMessageReceived.
// 
char msg[100];
void updateBTSerial() {
  if (btSerial.available()) {
    String msgString = "";
    while (btSerial.available()) {
      char c = btSerial.read();
      msgString += c;
    }
    BTSerialMessageReceived(msgString);
  }
}
/*
void updateBTSerial() {
  int availableCount = btSerial.available();
  if (availableCount > 0) {
    btSerial.read(msg, availableCount);
    char *divided = strchr(msg,',');
    int msgValue = 0;
    if (divided != 0) {
       divided[0] = 0; divided++;
       String str(divided);
       msgValue = str.toInt();
    };
    String msgString(msg);
    BTSerialMessageReceived(msgString,msgValue);   
  }
}
*/
//...........................................................................

//...........................................................................
// Always include these two methods .
// They send a message to the BT port, without or with an int value
// 
void BTSerialSendMessage(String msgString) {
  btSerial.println(msgString); 
}

void BTSerialSendMessage(String msgString,int msgValue) {
  btSerial.print(msgString); 
  btSerial.print(",");
  btSerial.println(msgValue);
}
//...........................................................................

void setup()
{
    Serial.begin(9600);   // Open serial communication to Serial Monitor
    btSerial.begin(9600); // Open serial communication to Bluetooth unit
}

void loop() {
    updateBTSerial();
    /*
    while (btSerial.available()) { // If input available from Bluetooth unit
      char c = btSerial.read();    // Read character from from Bluetooth unit
      Serial.write(c);             // Write that character to Serial Monitor
    };
    while (Serial.available()) { // If input available from Serial Monitor
      char c = Serial.read();    // Read character from from Serial Monitor
      btSerial.write(c);         // Write that character to Bluetooth unit
    };*/
}


