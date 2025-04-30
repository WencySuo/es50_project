#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN1    7 // First NeoPixel strip pin
#define LED_COUNT1  8 // Number of LEDs on first strip

#define LED_PIN2    6 // Second NeoPixel strip pin
#define LED_COUNT2  8 // Number of LEDs on second strip

#define BLINK_FREQUENCY_HZ 21.3 // Frequency in Hertz (e.g., 2 Hz = 2 times per second)

Adafruit_NeoPixel strip1(LED_COUNT1, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT2, LED_PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  strip1.begin();
  strip2.begin();
  strip1.show();
  strip2.show();
  strip1.setBrightness(50);
  strip2.setBrightness(50);
}

void loop() {
  int blinkDelay = (1000 / BLINK_FREQUENCY_HZ) / 2; // ON and OFF times

  // Turn strip1 RED, strip2 OFF
  for (int i = 0; i < strip1.numPixels(); i++) {
    strip1.setPixelColor(i, strip1.Color(255, 0, 0)); // Red
  }
  for (int i = 0; i < strip2.numPixels(); i++) {
    strip2.setPixelColor(i, strip2.Color(0, 255, 0)); // green
  }
  strip1.show();
  strip2.show();
  delay(blinkDelay);

  // Turn strip1 OFF, strip2 Red (or any color you want)
  for (int i = 0; i < strip1.numPixels(); i++) {
    strip1.setPixelColor(i, strip1.Color(0, 0, 255)); // Off
  }
  for (int i = 0; i < strip2.numPixels(); i++) {
    strip2.setPixelColor(i, strip2.Color(255, 255, 255)); // Red
  }
  strip1.show();
  strip2.show();
  delay(blinkDelay);
  // Turn strip1 RED, strip2 OFF
  for (int i = 0; i < strip1.numPixels(); i++) {
    strip1.setPixelColor(i, strip1.Color(0, 255, 0)); // Red
  }
  for (int i = 0; i < strip2.numPixels(); i++) {
    strip2.setPixelColor(i, strip2.Color(255, 0, 0)); // Off
  }
  strip1.show();
  strip2.show();
  delay(blinkDelay);

  // Turn strip1 OFF, strip2 Red (or any color you want)
  for (int i = 0; i < strip1.numPixels(); i++) {
    strip1.setPixelColor(i, strip1.Color(255, 255, 255)); // Off
  }
  for (int i = 0; i < strip2.numPixels(); i++) {
    strip2.setPixelColor(i, strip2.Color(0, 0, 255)); // Red
  }
  strip1.show();
  strip2.show();
  delay(blinkDelay);
}
