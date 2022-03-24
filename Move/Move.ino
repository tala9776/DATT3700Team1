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

SharpIR sharp1( SharpIR::GP2Y0A41SK0F, A0 ); 
SharpIR sharp2( SharpIR::GP2Y0A41SK0F, A1 ); 
SharpIR sharp3( SharpIR::GP2Y0A41SK0F, A2 ); 

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

float pos = 0;    // variable to store the servo position
String moodCode;
float distance1;
float distance2;
float distance3;
float distanceAvg;
void setup() {
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
}

void input(){
  distance1 = sharp1.getDistance();
  distance2 = sharp2.getDistance();
  distance3 = sharp3.getDistance();
  distanceAvg = (distance1 + distance2 + distance3) / 3;
  
  if (20 > distanceAvg > 10){
    moodCode = "NEUTRAL";
  }

  if (10 > distanceAvg > 5){
    moodCode = "HAPPY";
  }

  if (distanceAvg < 5) {
    moodCode = "ANXIETY";
  }

}
void loop() {
  if( moodCode == "HAPPY" ){
    for (pos = 0; pos <= 180; pos += 0.5) { // goes from 0 degrees to 180 degrees
                                      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
  }

  if( moodCode == "PLAYFUL" ){
  
  }
  
  if( moodCode == "NEUTRAL"){
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
  }
  
  if( moodCode == "ANXIETY" ){
  }

  if( moodCode == "SAD" ){
  }

  if( moodCode == "ANGER" ){
  }

  if( moodCode == "RAGE" ){
  }

}
