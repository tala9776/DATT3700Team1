long timeBlock = 0; 
long timeBlock2 = 0;
#include <SharpIR.h>
#include <FastLED.h>
#define NUM_LEDS 8
#define LED_PIN  3
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
SharpIR sensor1( SharpIR::GP2Y0A41SK0F, A0 );
SharpIR sensor2( SharpIR::GP2Y0A41SK0F, A1 );

char sensorOne;
char sensorTwo;
int h;
int s;
int v;

const int WRITE_CYCLE = 1000; // Would write TO Max every 1000 ms
const int READ_CYCLE = 80;  // Would read FROM Max every 80ms
void setup() {  
  Serial.begin(9600);  // Should be the same baud rate as on Max
  Serial.println("A");  // Just for test
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}

void loop() {
  //if(millis()-timeBlock>READ_CYCLE){     
    if(Serial.available()){
      while(!Serial.available()){}
        sensorOne = Serial.read();
      while(!Serial.available()){}
        sensorTwo = Serial.read();
      
      if( sensorTwo < 30 && sensorOne < 30) {
         s = map (sensorTwo, 3, 29, 20, 255);
         h = map (sensorOne, 3, 29, 20, 255);
         for (int j = 0; j < NUM_LEDS; j++){
          leds[j] = CRGB(h, 0, s);
          FastLED.show();
         }
      }else {
          for (int j = 0; j < NUM_LEDS; j++){
          leds[j] = CRGB(0, 50, 0);
          FastLED.show();
          }
      }
    }
    
  
  if(millis()-timeBlock2>WRITE_CYCLE){   
            
    int dist1=sensor1.getDistance();  
    int dist2=sensor2.getDistance();
    String toSend1 = String(dist1);
    String toSend2 = String(dist2);
    
    Serial.print(toSend1);
    Serial.print(" "); 
    Serial.println(toSend2);
    
    timeBlock2=millis();
  }
}
  //}
