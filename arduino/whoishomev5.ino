//the Arduino Script and walk through and setup of the home lab was done by : Dylan Poll
//https://www.linkedin.com/in/dylan-poll-4a324a1a2/
// I used the FastLED libraries demo-reel as a foundation for this, please check out the fastLED github!!

#include <FastLED.h>
FASTLED_USING_NAMESPACE
#define DATA_PIN    9
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    10
CRGB leds[NUM_LEDS];
#define BRIGHTNESS  10
#define FRAMES_PER_SECOND  20

char person = 'F';
int d=0;
int l=0;
int k=0;
int j=0;
int count;

void holdup();

void setup() {
  delay(3000); // 3 second delay for recovery
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.delay(1000/FRAMES_PER_SECOND);
  Serial.begin(9600);
}
void loop(){
   if (Serial.available() > 0) {     
        Serial.println();
        person = Serial.read();      
            delay(1000);             
       switch(person){
            case'D':
              d = 1;
              person = 'F'; 
              count=count+1;
              break;
            case'd':
              d = 0;
              person = 'F'; 
              count=count+1;
              break;
            case'L':
            
              l = 1;
              person = 'F';
              count=count+1;
              break;
            case'l': 
            
              l = 0;
              person = 'F';
              count=count+1;
              break;
            case'K':
            
              k = 1;
              person = 'F';
              count=count+1;
              break;
            case'k':
            
              k = 0;
              person = 'F';
              count=count+1;
              break;
            case'J':
            
              j = 1;
              person = 'F';
              count=count+1;
              break;
            case'j':
            
              j = 0;
              person = 'F';
              count=count+1;
              break;
            case'F':
              break;
            }
  if(count == 4){holdup();}
  }
}

void holdup(){ //first set them all to off
        leds[0] =  CRGB::Black;
        leds[1] =  CRGB::Black;
        leds[2] =  CRGB::Black; 
        leds[3] =  CRGB::Black; 
        leds[4] =  CRGB::Black;
        leds[5] =  CRGB::Black; 
        leds[6] =  CRGB::Black; 
        leds[7] =  CRGB::Black;
        leds[8] =  CRGB::Black;
        leds[9] =  CRGB::Black;  
        
         //turn on what you need
    if(d == 1){                 
        leds[0] = 0xdd8bff;  //purple 
        leds[1] = 0xdd8bff;}
    if(l == 1){
        leds[2] = CRGB::Green; 
        leds[3] = CRGB::Green;}
    if(k == 1){
        leds[4] = CRGB::Red;  
        leds[5] = CRGB::Red; }
    if(j == 1){
        leds[6] = CRGB::Blue; 
        leds[7] = CRGB::Blue;}
FastLED.show();
delay(30000);           //10 second wait  
  d=0;
  l=0;
  k=0;
  j=0;
count=0;
person = 'F';
}

/*
        leds[i] = 0xff2d00;         
        leds[i] = 0xffe200;
        leds[i] = 0x71ff0;
        leds[i] = 0x00ffe2;  blue
        leds[i] = 0x003fff;
        leds[i] = 0xf200ff;
        leds[i] = 0xdd8bff;  purple
CRGB::Red
CRGB::Blue
CRGB::Green
*/
