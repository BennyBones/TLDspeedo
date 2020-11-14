#The Long Drive Real World Speedometer

*I love playing the long drive. For such a weird and quirky, mindless driving simulator I just keep coming back for more. I even went out and picked up a steeting wheel for it.*

With the new Halloween update (21-10-20) many new features were added including an output for a real world arduino speedo. After spending some time looking to see if anyone else had done it yet with no luck, I thought I'd give it a shot. I only have basic arduino skills, but here we go, it's a start.

![alt text](https://github.com/BennyBones/TLDspeedo/blob/main/realworldspeedo1.jpg "Real world speedo in action")
---
##Hardware - 

*An Arduino, I used an unbranded Uno clone.
*A 7-digit display, I used a TM1637 clone.
*Some M-F hookup wires.

![alt text](https://github.com/BennyBones/TLDspeedo/blob/main/ardunio1.jpg "Arduino")

VCC on the display to 5v on the arduino
GND to GND
CLK to A1
DIO to A0

Upload the sketch to the arduino.

You are going to need to create a .txt file in your The Long Drive data file called usb.txt. For me it was *C:\Program Files (x86)\Steam\steamapps\common\The Long Drive\TheLongDrive_Data*