#include <Arduino.h>
#include <TM1637Display.h>

int incomingByte = 0; // for incoming serial data
#define DEVICE_NAME "TLD_Speedo" //{"Group":"General","Name":"DEVICE_NAME","Title":"Device name,\r\n make sure to use a unique name when using multiple arduinos","DefaultValue":"SimHub Dash","Type":"string","Template":"#define DEVICE_NAME \"{0}\""}

// Module connection pins (Digital Pins)
#define CLK A1
#define DIO A0

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   10


const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
  };

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

  //adjustments to the gamespeed, 67%
  int   speedo = incomingByte*0.67;
  
//display----
  int k;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
  display.setBrightness(0x0f);

 
  /*
  for(k = 3; k >= 0; k--) {
  display.setSegments(data, 1, k);
  delay(TEST_DELAY);
  }
  */

  // Show decimal numbers with/without leading zeros
  display.showNumberDec(speedo, false); // Expect: ___0
  delay(TEST_DELAY);
  
  // Brightness Test
  //for(k = 0; k < 4; k++)
  //data[k] = 0xff;
  //for(k = 0; k < 7; k++) {
  //  display.setBrightness(k);
  //  display.setSegments(data);
  //  delay(TEST_DELAY);
  //}
  
  // On/Off test
  //for(k = 0; k < 4; k++) {
  //  display.setBrightness(7, false);  // Turn off
  //  display.setSegments(data);
  //  delay(TEST_DELAY);
  //  display.setBrightness(7, true); // Turn on
  //  display.setSegments(data);
  //  delay(TEST_DELAY);  
  //}

}
