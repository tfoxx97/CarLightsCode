// Code by: Tyler Elenberger
// basic code for neopixel ring using the NodeMCU ESP8266
#include <Adafruit_NeoPixel.h>

#include <ESP8266WiFi.h>



#define NUM_LEDS 16
#define PIN D6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN);

 
void setup() {
  Serial.begin(115200); 
  strip.begin();
  strip.show();
}

void loop() {
  for(int dot = 0; dot < NUM_LEDS; dot++){ // Run color wipe in continuous loop
    colorWipe(strip.Color(255, 0, 0), 33); // Red
    colorWipe(strip.Color(0, 255, 0), 33); // Green
    colorWipe(strip.Color(0, 0, 255), 33); // Blue
    strip.show(); 
    delay(100);
  }
}

void colorWipe(uint32_t c, uint8_t wait) { // set up colorWipe function so the program runs
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
