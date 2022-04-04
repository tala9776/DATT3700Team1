/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>
#include <SharpIR.h>

#define sensor1 A0
#define sensor2 A1
#define sensor3 A2

long randNumber;
long randNumber2;

SharpIR sharp1( SharpIR::GP2Y0A41SK0F, A0 ); 
SharpIR sharp2( SharpIR::GP2Y0A41SK0F, A1 ); 
SharpIR sharp3( SharpIR::GP2Y0A41SK0F, A2 ); 

Servo myservo1;
Servo myservo2;

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;
float distance1;
float distance2;
float distance3;
float distanceAvg;
String moodCode = "";
void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
}

void loop() {
  distance1 = sharp1.getDistance();
  distance2 = sharp2.getDistance();
  distance3 = sharp3.getDistance();
  
  distanceAvg = (distance1 + distance2 + distance3) / 3;
  
  long currPos1 = myservo1.read();
  long currPos2 = myservo2.read();
  long posMin = 45;
  long posMax = 135;

  if (distanceAvg > 30){
    moodCode = "SAD";
  }
  
  if (30 > distanceAvg > 25){
    moodCode = "NEUTRAL";
  }

  if (25 > distanceAvg > 20){
    moodCode = "HAPPY";
  }

  if (20 > distanceAvg > 10){
    moodCode = "PLAYFUL";  
  }

  if (distanceAvg < 10) {
    moodCode = "ANXIETY";
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if( moodCode == "HAPPY" ){
    for (pos1 = posMin; pos1 <= posMax; pos1 += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
      myservo1.write(pos1); 
      myservo2.write(pos2);                           // tell servo to go to position in variable 'pos'
      delay(15);                                     // waits 15 ms for the servo to reach the position
    }
    for (pos1 = posMax; pos1 >= posMin; pos1 -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos1);                           // tell servo to go to position in variable 'pos'
      myservo2.write(pos2);
      delay(15);                                     // waits 15 ms for the servo to reach the position
    }
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  if( moodCode == "NEUTRAL" ){
    for (pos1 = posMin; pos1 <= posMax; pos1 += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
      myservo1.write(pos1);
      pos1 = pos2; 
      myservo2.write(pos2);                           // tell servo to go to position in variable 'pos'
      delay(90);                                     // waits 15 ms for the servo to reach the position
    }
    for (pos1 = posMax; pos1 >= posMin; pos1 -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos1);                           // tell servo to go to position in variable 'pos'
      pos1 = pos2;
      myservo2.write(pos2);
      delay(90);                                     // waits 15 ms for the servo to reach the position
    }
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  if( moodCode == "SAD" ){
    for (pos1 = posMin; pos1 <= posMax; pos1 += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
      myservo1.write(pos1); 
      pos1 = pos2;
      myservo2.write(pos2);                           // tell servo to go to position in variable 'pos'
      delay(180);                                     // waits 15 ms for the servo to reach the position
    }
    for (pos1 = posMax; pos1 >= posMin; pos1 -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos1);                           // tell servo to go to position in variable 'pos'
      pos1 = pos2;
      myservo2.write(pos2);
      delay(180);                                     // waits 15 ms for the servo to reach the position
    }
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  if( moodCode == "PLAYFUL" ){
    for (pos1 = posMin; pos1 <= posMax; pos1 += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
      myservo1.write(pos1);                           // tell servo to go to position in variable 'pos'
      delay(15);                                     // waits 15 ms for the servo to reach the position
    }
    for (pos1 = posMax; pos1 >= posMin; pos1 -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos1);                           // tell servo to go to position in variable 'pos'
      delay(15);                                     // waits 15 ms for the servo to reach the position
    }
    for (pos2 = posMin; pos2 <= posMax; pos2 += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
      myservo2.write(pos2);                           // tell servo to go to position in variable 'pos'
      delay(15);                                     // waits 15 ms for the servo to reach the position
    }
    for (pos2 = posMax; pos2 >= posMin; pos2 -= 1) { // goes from 180 degrees to 0 degrees
      myservo2.write(pos2);                           // tell servo to go to position in variable 'pos'
      delay(15);                                     // waits 15 ms for the servo to reach the position
    }
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  if( moodCode == "ANXIETY" ){
    for (pos1 = posMin; pos1 <= posMax; pos1 += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
      myservo1.write(pos1);                           // tell servo to go to position in variable 'pos'
      delay(180);                                     // waits 15 ms for the servo to reach the position
    }
    for (pos1 = posMax; pos1 >= posMin; pos1 -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos1);                           // tell servo to go to position in variable 'pos'
      delay(180);                                     // waits 15 ms for the servo to reach the position
    }
    for (pos2 = posMin; pos2 <= posMax; pos2 += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
      myservo2.write(pos2);                           // tell servo to go to position in variable 'pos'
      delay(180);                                     // waits 15 ms for the servo to reach the position
    }
    for (pos2 = posMax; pos2 >= posMin; pos2 -= 1) { // goes from 180 degrees to 0 degrees
      myservo2.write(pos1);                           // tell servo to go to position in variable 'pos'
      delay(180);                                     // waits 15 ms for the servo to reach the position
    }
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
}
