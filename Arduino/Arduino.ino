long timeBlock = 0; 
long timeBlock2 = 0;
#include <SharpIR.h>
#include <FastLED.h>
#include <Servo.h>
#define NUM_LEDS 8
#define LED_PIN  3
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

SharpIR sensor1( SharpIR::GP2Y0A41SK0F, A0 );
SharpIR sensor2( SharpIR::GP2Y0A41SK0F, A1 );
SharpIR sensor3( SharpIR::GP2Y0A41SK0F, A2 );

Servo myservo1;
Servo myservo2;

int pos = 0;

char sensorOne;
char sensorTwo;
char sensorThree;



uint8_t gHue = 0;

const int WRITE_CYCLE = 1000; // Would write TO Max every 1000 ms

void setup() {  
  Serial.begin(9600);  // Should be the same baud rate as on Max
  Serial.println("A");  // Just for test
  myservo1.attach(9);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(100);
}

void loop() {    
    if(Serial.available()){
      while(!Serial.available()){}
        sensorOne = Serial.read();
      while(!Serial.available()){}
        sensorTwo = Serial.read();
      while(!Serial.available()){}
        sensorThree = Serial.read();  

      int allSensors = (sensorOne + sensorTwo + sensorThree);
      
      if( allSensors == 0) {
        sad();
        for (int j = 0; j < NUM_LEDS; j++){  //SAD
          sinelon();
          addGlitter(2);
          FastLED.show();
        }
      }else if ( allSensors == 1) {
        happy();
        for (int j = 0; j < NUM_LEDS; j++){   //HAPPY
          bpm();
          addGlitter(12);
          FastLED.show();
        }
      }else if ( allSensors == 2) {
        happier();
        for (int j = 0; j < NUM_LEDS; j++){     //HAPPIER
          confetti();
          FastLED.show();
        }
      }else if (allSensors == 3) {
        anxious();
        for (int j = 0; j < NUM_LEDS; j++){  //Anxies
          leds[j] = CHSV(0, 0, 0);
          addGlitter2(30);
          addGlitter(15);
          FastLED.show();
        }
      }
      
//      if( sensorTwo < 30 && sensorOne < 30) {
//         s = map (sensorTwo, 3, 29, 20, 255);
//         h = map (sensorOne, 3, 29, 20, 255);
//         for (int j = 0; j < NUM_LEDS; j++){
//          leds[j] = CRGB(h, 0, s);
//          FastLED.show();
//         }
//      }else {
//          for (int j = 0; j < NUM_LEDS; j++){
//          leds[j] = CRGB(0, 50, 0);
//          FastLED.show();
//          }
//      }
    }
    
  
  if(millis()-timeBlock2>WRITE_CYCLE){   
            
    int dist1 = sensor1.getDistance();  
    int dist2 = sensor2.getDistance();
    int dist3 = sensor3.getDistance();
    String toSend1 = String(dist1);
    String toSend2 = String(dist2);
    String toSend3 = String(dist3);
    
    Serial.println(toSend1);
    Serial.print(" "); 
    Serial.print(toSend2);
    Serial.print(" ");
    Serial.println(toSend3);
    
    timeBlock2=millis();
  }
}

void addGlitter2( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::Red;
  }
}
void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 30, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void confetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(10), 200, 200);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 35;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void sad()
{
    for (pos = 45; pos <= 135; pos += 1) {
    myservo1.write(pos);
    myservo2.write(pos);              
    delay(15);                       
  }
  for (pos = 135; pos >= 45; pos -= 1) { 
    myservo1.write(pos);  
    myservo2.write(pos);            
    delay(15);                      
  }
}

void happy(){
  for (pos = 45; pos <= 135; pos += 1) {
    myservo1.write(pos);
    myservo2.write(pos);              
    delay(8);                       
  }
  for (pos = 135; pos >= 45; pos -= 1) { 
    myservo1.write(pos);  
    myservo2.write(pos);            
    delay(6);                      
  }
}

void happier(){
  for (pos = 45; pos <= 135; pos += 1) {
    myservo1.write(pos);
    myservo2.write(pos);              
    delay(3);                       
  }
  for (pos = 135; pos >= 45; pos -= 1) { 
    myservo1.write(pos);  
    myservo2.write(pos);            
    delay(6);                      
  }
}

void anxious(){
  for (pos = 45; pos <= 135; pos += 1) {
    myservo1.write(pos);
    myservo2.write(pos);              
    delay(2);                       
  }
  for (pos = 135; pos >= 45; pos -= 1) { 
    myservo1.write(pos);  
    myservo2.write(pos);            
    delay(1);                      
  }
}
