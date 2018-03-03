/*

*/

#define COMMON_ANODE

struct Color {
  int red;
  int green;
  int blue;
};

int led1[] = {9, 10, 11};
int led2[] = {3, 5, 6};

Color RED    = { 255, 0, 0 };
Color ORANGE = { 255, 127, 0 };
Color YELLOW = { 255, 255, 0 };
Color GREEN  = { 0, 255, 0 };
Color BLUE   = { 0, 0, 255 };
Color VIOLET = { 148, 0, 211 };

Color rainbow[] = { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };

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
  for(int i=0; i<3; i++) {
    pinMode(led[i], OUTPUT);
    #ifdef COMMON_ANODE
      digitalWrite(led[i], HIGH);
    #else
      digitalWrite(led[i], LOW);
    #endif
  }
}

void setup() {
  setupLed(led1);
  setupLed(led2);
}

void loop() {
  cycleColors(led2, rainbow, 500);
}
