#include <FastLED.h>
#define NUM_LEDS 3
#define DATA_PIN 2
#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define MAX_brightness 125
#define MIN_brightness 8
#define VOLTS 5
#define MAX_AMPS 500

int button =7;
//int buttonState=0;
int lastButtonState=0;
int mainState=0;
String endCom;
const int MotorPinA = 12; // for motor A
const int MotorSpeedPinA = 3; // for motor A
const int MotorBrakePinA = 9; // for motor A

CRGB leds[NUM_LEDS];

int hue=0;
int divisor=10;
int signPicker=-1;
int paletteIndex=0;
DEFINE_GRADIENT_PALETTE (choice1){
  0,0,0,0,
  128,255,0,0,
  200,255,255,0,
  255,255,255,255
};

DEFINE_GRADIENT_PALETTE (choice2){
  0,0,0,0,
  128,37,196,196,
  200,24,10,148,
  255,230,149,225
};

DEFINE_GRADIENT_PALETTE (choice3){
  0,237,233,154,
  128,154,237,237,
  200,247,213,246,
  255,242,247,213
};

CRGBPalette16 pal1 = choice1;
CRGBPalette16 pal2 = choice2;
CRGBPalette16 pal3 = choice3;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<CHIPSET,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS,MAX_AMPS);
  FastLED.setBrightness(MAX_brightness);
  FastLED.clear();
  FastLED.show();
  Serial.begin(9600);

  pinMode(MotorPinA, OUTPUT);
  pinMode(MotorSpeedPinA, OUTPUT);
  pinMode(MotorBrakePinA, OUTPUT);

  pinMode(button,INPUT);
  
}


void loop() {
  randomSeed(random(999));
  int buttonState= digitalRead(button);
  //Serial.println(buttonState);

  if(buttonState==0){
    if(mainState==0){
      //digitalWrite(MotorPinA,LOW);
  float breath=(exp(sin(millis()/5000*PI))-0.3678)*208;
  breath =map(breath,0,255,MIN_brightness,MAX_brightness);
  FastLED.setBrightness(breath);

  fill_solid(leds,NUM_LEDS,(hue+=10/divisor));
  if(hue==255){
    hue=0;
  }
  FastLED.show();
  delay(5);
  //Serial.println("test");
  }}
  
  
  else{
    mainState=1;
    
    if(buttonState!=lastButtonState && buttonState==1){
    signPicker=random(1,351);
//    Serial.print("number is: ");
//    Serial.println(signPicker);
    }
    //random(4);
//    leds[0]=CRGB::Red;
//    leds[1]=CRGB::Green;
//    leds[2]=CRGB::Blue;
//    FastLED.show();
    while (signPicker >=0 && signPicker<=100){
          fill_palette(leds,NUM_LEDS,paletteIndex,255/NUM_LEDS,pal1,255,LINEARBLEND);
          EVERY_N_MILLISECONDS(15){
            paletteIndex+=10;
            //Serial.println(paletteIndex);
          }
          FastLED.show();
          digitalWrite(MotorPinA,HIGH);
          analogWrite(MotorSpeedPinA,127);
          for(int i=0;i<10;i++){
            Serial.println("1");
            
          }}
////          delay(2000);
////          signPicker=-1;
//    }
     while (signPicker >=101 && signPicker<=200){
          fill_palette(leds,NUM_LEDS,paletteIndex,255/NUM_LEDS,pal2,255,LINEARBLEND);
          EVERY_N_MILLISECONDS(15){
            paletteIndex+=10;
            //Serial.println(paletteIndex);
          }
          FastLED.show();
          digitalWrite(MotorPinA,HIGH);
          analogWrite(MotorSpeedPinA,127);
          for(int i=0;i<10;i++){
            Serial.println("2");
          }}
////          delay(2000);
////          signPicker=-1;
//    }
    while (signPicker >=201 && signPicker<=350){
          fill_palette(leds,NUM_LEDS,paletteIndex,255/NUM_LEDS,pal3,255,LINEARBLEND);
          EVERY_N_MILLISECONDS(15){
            paletteIndex+=10;
            //Serial.println(paletteIndex);
          }
          FastLED.show();
          digitalWrite(MotorPinA,HIGH);
          analogWrite(MotorSpeedPinA,127);
          for(int i=0;i<10;i++){
            Serial.println("3");
          }
          }
////          delay(2000);
////          signPicker=-1;
//    }
//    while (signPicker ==3){
//          leds[0]=CRGB::Black;
//          leds[1]=CRGB::Black;
//          leds[2]=CRGB::Black;
//          leds[3]=CRGB::Red;
//          FastLED.show();
//          for(int i=0;i<10;i++){
//            //Serial.println(signPicker);
//          }
//          delay(2000);
//          signPicker=-1;
    }
    
    
    
//    for(int i=0;i<4;i++){
//    leds[i]=CRGB::Red;
//    FastLED.show();
//    delay(1000);
//    leds[i]=CRGB::Black;
//    FastLED.show();
//    delay(1000);
//    
//  }
lastButtonState= buttonState;
  }
  
