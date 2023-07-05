/** Demonstrate how to play a file by it's (FAT) index number.
 *
 * @author James Sleeman,  http://sparks.gogo.co.nz/
 * @license MIT License
 * @file
 */
 
// This example uses SoftwareSerial on pin 8 and 9
#include <SoftwareSerial.h>
SoftwareSerial mySoftwareSerial(8,9);

// Create the mp3 connection itself, notice how we give it the 
//  serial object we want it to use to talk to the JQ8400 module.
// For example you might use mp3(Serial2) instead of a SoftwareSerial
#include <JQ8400_Serial.h>
JQ8400_Serial mp3(mySoftwareSerial);

void setup() 
{  
  mySoftwareSerial.begin(9600);
  mp3.reset();
  mp3.setVolume(30);
  mp3.playFileByIndexNumber(2);

  delay(3100);
  mp3.reset();
  mp3.setVolume(30);
  mp3.nextFolder();
  mp3.playFileByIndexNumber(100);
}

void loop() {
}
