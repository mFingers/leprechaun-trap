/*

*/

#define COMMON_ANODE

struct Color {
  int red;
  int green;
  int blue;
};

int led[3] = {9, 10, 11};

Color RED    = { 255, 0, 0 };
Color ORANGE = { 255, 127, 0 };
Color YELLOW = { 255, 255, 0 };
Color GREEN  = { 0, 255, 0 };
Color BLUE   = { 0, 0, 255 };
Color VIOLET = { 148, 0, 211 };

Color rainbow[6] = { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };

void setColor(int led[], Color color) {
  int red = color.red;
  int green = color.green;
  int blue = color.blue;

  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif

  analogWrite(led[0], red);
  analogWrite(led[1], green);
  analogWrite(led[2], blue);
}

void cycleColors(int led[], Color colors[], int duration) {
  for(int i=0; i<6; i++) {
    setColor(led, colors[i]);
    delay(duration);
  }
}

void setupLed(int led[]) {
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
}

void setup() {
  setupLed(led);
}

void loop() {
  cycleColors(led, rainbow, 500);
}
