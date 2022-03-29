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
// create servo object to control a servo
// twelve servo objects can be created on most boards

long pos1 = 0;    // variable to store the servo position
long pos2 = 0;
String moodCode = "NEUTRAL";
float distance1;
float distance2;
float distance3;
float distanceAvg;
void setup() {
  myservo1.attach(4);  // attaches the servo on pin 9 to the servo object
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
  
  long currPos1 = myservo1.read();
  long currPos2 = myservo2.read();
  long posMin = 45;
  long posMax = 135;

  if (distanceAvg > 30){
    moodCode = "SAD";
  }
  
  if (30 > distanceAvg > 20){
    moodCode = "NEUTRAL";
  }

  if (20 > distanceAvg > 10){
    moodCode = "HAPPY";
  }

  if (distanceAvg < 10) {
    moodCode = "ANXIETY";
  }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if( moodCode == "HAPPY" ){
    for (pos1 = currPos1; pos1 <= posMax; pos1 += 2) {   
      myservo1.write(pos1);
      myservo2.write(pos1);                                  
      delay(15);                            
    }                                       
    for (pos1 = posMax; pos1 >= posMin; pos1 -= 2) { 
      myservo1.write(pos1);       
      myservo2.write(pos1);       
      delay(15);                       
    }
  }
////////////////////////////////////////////////////////////////////
  if( moodCode == "PLAYFUL" ){
    randNumber = random(0,3);
    switch(randNumber){
      case 0:
        for (pos1 = currPos1; pos1 <= posMax; pos1 += 3){
        }
        break;  
    }
    for (pos1 = currPos1; pos1 <= posMax; pos1 += 3) { 
        myservo1.write(pos1);              
        delay(15);                       
    }
    for (pos1 = posMax; pos1 >= posMin; pos1 -= 3) { 
        myservo1.write(pos1);              
        delay(15);                       
    }
  }
////////////////////////////////////////////////////////////////////  
  if( moodCode == "NEUTRAL"){
    for (pos1 = currPos1; pos1 <= posMax; pos1 += 1) { 
      myservo1.write(pos1);              
      delay(15);                       
    }
    for (pos1 = posMax; pos1 >= 0; pos1 -= 1) { 
      myservo1.write(pos1);              
      delay(15);                       
    }
    for (pos2 = currPos2; pos2 <= posMax; pos2 += 1) { 
      myservo1.write(pos2);              
      delay(15);                       
    }
    for (pos2 = posMax; pos2 >= 0; pos2 -= 1) { 
      myservo1.write(pos2);              
      delay(15);                       
    }
  }
////////////////////////////////////////////////////////////////////  
  if( moodCode == "ANXIETY" ){
    randNumber = random(0, 3);
    switch (randNumber){
      case 0:
        for (pos1 = currPos1; pos1 <= posMax; pos1 += 1) { 
          myservo1.write(pos1);              
          delay(15);                       
        }
        for (pos1 = posMax; pos1 >= 0; pos1 -= 4) { 
          myservo1.write(pos1);              
          delay(15);                       
        }
        break;
      case 1:
        for (pos2 = currPos2; pos2 <= posMax; pos2 += 4) { 
          myservo1.write(pos2);              
          delay(15);                       
        }
        for (pos2 = posMax; pos2 >= posMin; pos2 -= 1) { 
          myservo1.write(pos2);              
          delay(15);                       
        }
        break;
      case 2:
        for (pos1 = currPos1; pos1 <= 90; pos1 += 3) { 
          myservo1.write(pos1);              
          delay(15);                       
        }
        for (pos1 = 90; pos1 >= posMin; pos1 -= 3) { 
          myservo1.write(pos1);              
          delay(15);                       
        }
        for (pos2 = currPos2; pos2 <= 90; pos2 += 3) { 
          myservo1.write(pos2);              
          delay(15);                       
        }
        for (pos2 = 90; pos2 >= posMin; pos2 -= 3) { 
          myservo1.write(pos2);              
          delay(15);                       
        }
        break;
      case 3:
        for (pos1 = currPos1; pos1 <= 120; pos1 += 3) { 
          pos2 = currPos2;
          myservo1.write(pos1);      
          myservo2.write(pos2);
          pos2 -= 3;        
          delay(15);                       
        }
        for (pos1 = 120; pos1 >= posMin; pos1 -= 3) { 
          pos2 = currPos2;
          myservo1.write(pos1);            
          myservo2.write(pos2);
          pos2 += 3;  
          delay(15);                       
        }
        break;
    }
  }
////////////////////////////////////////////////////////////////////
  if( moodCode == "SAD" ){
    for (pos1 = currPos1; pos1 <= posMax; pos1 += 1) {   
      myservo1.write(pos1);                                    
      delay(15);                            
    }                                       
    for (pos1 = posMax; pos1 >= posMin; pos1 -= 1) { 
      myservo1.write(pos1);              
      delay(15);                       
    }
    for (pos2 = currPos2; pos2 <= posMax; pos2 += 1) {   
      myservo1.write(pos2);                                    
      delay(15);                            
    }                                       
    for (pos2 = posMax; pos2 >= posMin; pos2 -= 1) { 
      myservo1.write(pos2);              
      delay(15);                       
    }
  }

  if( moodCode == "ANGER" ){
    for (pos1 = currPos1; pos1 <= posMax; pos1 += 6) {   
      myservo1.write(pos1);                                     
      delay(15);                            
    }                                       
    for (pos1 = posMax; pos1 >= posMin; pos1 -= 6) { 
      myservo1.write(pos1);              
      delay(15);                       
    }
  }
////////////////////////////////////////////////////////////////////
  if( moodCode == "RAGE" ){
  }
  Serial.println(randNumber);
}
