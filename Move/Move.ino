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

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

long pos = 0;    // variable to store the servo position
String moodCode = "PLAYFUL";
float distance1;
float distance2;
float distance3;
float distanceAvg;
void setup() {
  myservo.attach(4);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  randNumber = random(60, 120);
  randNumber2 = random(60, 180);
}

void input(){

}
void loop() {
  distance1 = sharp1.getDistance();
  distance2 = sharp2.getDistance();
  distance3 = sharp3.getDistance();
  

  distanceAvg = (distance1 + distance2 + distance3) / 3;
  
  long currPos = myservo.read();
  long posMin = 0;
  long posMax = 180;
  long num1 = randNumber;
  
  if (20 > distanceAvg > 10){
    moodCode = "NEUTRAL";
  }

  if (10 > distanceAvg > 5){
    moodCode = "HAPPY";
  }

  if (distanceAvg < 5) {
    moodCode = "ANXIETY";
  }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if( moodCode == "HAPPY" ){
    for (pos = currPos; pos <= posMax; pos += 2) {   
      myservo.write(pos);                                  
      delay(15);                            
    }                                       
    for (pos = posMax; pos >= posMin; pos -= 2) { 
      myservo.write(pos);              
      delay(15);                       
    }
  }

  if( moodCode == "PLAYFUL" ){
    for (pos = currPos; pos <= num1; pos += 3) { 
        myservo.write(pos);              
        delay(15);                       
    }
    for (pos = num1; pos >= posMin; pos -= 3) { 
        myservo.write(pos);              
        delay(15);                       
    }
  }
  
  
  if( moodCode == "NEUTRAL"){
    for (pos = currPos; pos <= posMax; pos += 1) { 
      myservo.write(pos);              
      delay(15);                       
    }
    for (pos = posMax; pos >= 0; pos -= 1) { 
      myservo.write(pos);              
      delay(15);                       
    }
  }
  
  if( moodCode == "ANXIETY" ){
    randNumber = random(0, 3);
    switch (randNumber){
      case 0:
        for (pos = currPos; pos <= posMax; pos += 1) { 
          myservo.write(pos);              
          delay(15);                       
        }
        for (pos = posMax; pos >= 0; pos -= 4) { 
          myservo.write(pos);              
          delay(15);                       
        }
        break;
      case 1:
        for (pos = currPos; pos <= posMax; pos += 4) { 
          myservo.write(pos);              
          delay(15);                       
        }
        for (pos = posMax; pos >= posMin; pos -= 1) { 
          myservo.write(pos);              
          delay(15);                       
        }
        break;
      case 2:
        
        for (pos = currPos; pos <= 40; pos += 3) { 
          myservo.write(pos);              
          delay(15);                       
        }
        for (pos = 40; pos >= posMin; pos -= 3) { 
          myservo.write(pos);              
          delay(15);                       
        }
        break;
      case 3:
        break;
    }
  }

  if( moodCode == "SAD" ){
    for (pos = currPos; pos <= posMax; pos += 1) {   
      myservo.write(pos);                                    
      delay(15);                            
    }                                       
    for (pos = posMax; pos >= posMin; pos -= 1) { 
      myservo.write(pos);              
      delay(15);                       
    }
  }

  if( moodCode == "ANGER" ){
    for (pos = currPos; pos <= posMax; pos += 6) {   
      myservo.write(pos);                                     
      delay(15);                            
    }                                       
    for (pos = posMax; pos >= posMin; pos -= 6) { 
      myservo.write(pos);              
      delay(15);                       
    }
  }

  if( moodCode == "RAGE" ){
  }
  Serial.println(randNumber);
}
