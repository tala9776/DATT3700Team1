long timeBlock = 0; 
long timeBlock2 = 0;
#include <FastLED.h>
#include <Servo.h>
#define NUM_LEDS 8
#define LED_PIN  3
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

const int button1 = 4;
const int button2 = 5;
const int button3 = 6;

int button1State = 0;
int button2State = 0;
int button3State = 0;

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
  myservo2.attach(10);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(100);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  
  
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
        sinelon();
        addGlitter(2);
        FastLED.show();
      }else if ( allSensors == 1) {
        happy();
        bpm();
        addGlitter(12);
        FastLED.show();
      }else if ( allSensors == 2) {
        happier();
        confetti();
        FastLED.show();
      }else if (allSensors == 3) {
        anxious();
        addGlitter2(30);
        addGlitter(15);
        FastLED.show();
      }
    }
  EVERY_N_MILLISECONDS( 5 ) { gHue++; }
  
  if(millis()-timeBlock2>WRITE_CYCLE){   
    button1State = digitalRead(button1);
    button2State = digitalRead(button2);
    button3State = digitalRead(button3);

    Serial.print(button1State);
    Serial.print(" "); 
    Serial.print(button2State);
    Serial.print(" ");
    Serial.println(button3State);
    
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
