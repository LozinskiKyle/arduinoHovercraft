#include <SoftwareSerial.h>
#define rxPin 3                          // define SoftwareSerial rx data pin  
#define txPin 4                          // define SoftwareSerial tx data pin  
SoftwareSerial hc06(rxPin, txPin);  // create instance of SoftwareSerial

char c;
String inData;

void setup()
{
  Serial.begin(9600);                   // Start hardware Serial
  Serial1.begin(9600);                // Start SoftwareSerial
}
void loop()
{
  if (Serial.available())
  {
    c = Serial.read();
    Serial.print(c);                 // Write the character to the Serial Monitor
    Serial1.write (c);             // Write the character to Bluetooth
  }

  while (Serial1.available() > 0) { //While connected to bluetooth
    char received = Serial1.read();

    if (received == '*')
    {
      Serial.print(inData);

    } else {
      if (inData.length() >= 2) { //resets inData
        inData = "";
      }
      inData += received; //adds what it recieved to the data

    }
  }
}
