/*

*/
#include "Tlc5940.h"

#define NUM_LEDS 5

struct Color {
  int red;
  int green;
  int blue;
};

struct Led {
  int red;
  int green;
  int blue;
};

Color RED    = { 255, 0, 0 };
Color ORANGE = { 255, 127, 0 };
Color YELLOW = { 255, 255, 0 };
Color GREEN  = { 0, 255, 0 };
Color BLUE   = { 0, 0, 255 };
Color VIOLET = { 148, 0, 211 };

Color rainbow[] = { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };

void setColor(Led led, Color color) {
  Tlc.set(led.red, color.red * 16);
  Tlc.set(led.green, color.green * 16);
  Tlc.set(led.blue, color.blue * 16);
}

void cycleColors(int numLeds, Color colors[], int duration) {
  for(int i=0; i<6; i++) {
    for(int l=0; l<numLeds; l++) {
      int color = (i + l) % 6;
      Led led = { l * 3, l*3+1, l*3+2 };
      setColor(led, colors[color]) ;
    }
    Tlc.update();
    delay(duration);
  }
}

void setup() {
  Tlc.init();
}

void loop() {
  Tlc.clear();

  cycleColors(NUM_LEDS, rainbow, 250);
}
