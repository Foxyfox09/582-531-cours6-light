// Le code minimal

#include <Arduino.h> 
#include <MicroOscSlip.h>
#include <FastLED.h>
CRGB monPixel;

#define MA_BROCHE_ANGLE 32

MicroOscSlip<128> monOsc(&Serial);

void setup() {
Serial.begin(115200);  
FastLED.addLeds<WS2812,27,GRB>( & monPixel, 1  );
}

void loop() {
  int maLectureAnalogique;
   maLectureAnalogique = analogRead(MA_BROCHE_ANGLE );

   monOsc.sendInt( "/angle" , maLectureAnalogique);

   Serial.print(maLectureAnalogique);
   Serial.println();
  delay(100);


    if (maLectureAnalogique < 1365) {
    monPixel = CRGB(0,0,255);
  } else if (maLectureAnalogique >= 1365 && maLectureAnalogique <= 2730) {
    monPixel = CRGB(0,255,0);
  } else if (maLectureAnalogique > 2730) {
    monPixel = CRGB(255,0,0);
  }
    FastLED.show();

  // if (maLectureAnalogique > 2048) {
  //   monPixel = CRGB(255,0,0);
  //   FastLED.show();
  // } else if (maLectureAnalogique < 2048) {
  //   monPixel = CRGB(0,0,0);
  //   FastLED.show();
  // }
}