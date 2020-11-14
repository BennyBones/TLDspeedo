// The Long Drive Real World Speedo
// Code by Benjamin Webb (AKA Benny Bones)
// 14/11/20 v1

#include <Arduino.h>
#include <TM1637Display.h>

int incomingByte = 0; // for incoming serial data

// Module connection pins (Digital Pins)
#define CLK A1
#define DIO A0

// The amount of time (in milliseconds) between speedometer updates
#define READ_DELAY   10

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
  }

  //Calabration between byte and speed, aprox 2/3, 67%
  int   speedo = incomingByte*0.67;
  
//display----
  display.setBrightness(0x0f);
  display.showNumberDec(speedo, false); // Expect: ___0
  delay(READ_DELAY);
  }
