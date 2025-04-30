#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN1    7 // First NeoPixel strip pin
#define LED_COUNT1  8 // Number of LEDs on first strip

#define LED_PIN2    6 // Second NeoPixel strip pin
#define LED_COUNT2  8 // Number of LEDs on second strip

#define BLINK_FREQUENCY_HZ 40 // Frequency in Hertz (e.g., 2 Hz = 2 times per second)

Adafruit_NeoPixel strip1(LED_COUNT1, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT2, LED_PIN2, NEO_GRB + NEO_KHZ800);

const uint8_t PATTERN_LEN = 8;
const uint8_t onCounts[PATTERN_LEN] = {8, 7, 6,5,4,3,2,1};

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
  for (uint8_t step = 0; step < PATTERN_LEN; step++) {
    // for each LED index…
    for (uint8_t i = 0; i < LED_COUNT1; i++) {
      // turn ON for the first onCounts[step] pixels, else OFF
      if (i < onCounts[step]) {
        strip1.setPixelColor(i, strip1.Color(255, 255, 0)); // red
        strip2.setPixelColor(i, strip2.Color(255, 255, 0));
      } else {
        strip1.setPixelColor(i, strip1.Color(0, 0, 0));   // off
        strip2.setPixelColor(i, strip2.Color(0,0, 0));
      }
    }
    strip1.show();
    strip2.show();
    delay(blinkDelay/PATTERN_LEN);
  }
}