/*

*/

#define COMMON_ANODE

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

Led led1 = {9, 10, 11};
Led led2 = {3, 5, 6};

Color RED    = { 255, 0, 0 };
Color ORANGE = { 255, 127, 0 };
Color YELLOW = { 255, 255, 0 };
Color GREEN  = { 0, 255, 0 };
Color BLUE   = { 0, 0, 255 };
Color VIOLET = { 148, 0, 211 };

Color rainbow[] = { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };
Led runway[] = { led1, led2 };

void setColor(Led led, Color color) {
  int red = color.red;
  int green = color.green;
  int blue = color.blue;

  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif

  analogWrite(led.red, red);
  analogWrite(led.green, green);
  analogWrite(led.blue, blue);
}

void cycleColors(Led leds[], Color colors[], int duration) {
  for(int i=0; i<6; i++) {
    for(int l=0; l<2; l++) {
      int color = (i + l) % 6;
      setColor(leds[l], colors[color]) ;
    }
    delay(duration);
  }
}

void setupLed(Led led) {
  pinMode(led.red, OUTPUT);
  pinMode(led.green, OUTPUT);
  pinMode(led.blue, OUTPUT);
  #ifdef COMMON_ANODE
    digitalWrite(led.red, HIGH);
    digitalWrite(led.green, HIGH);
    digitalWrite(led.blue, HIGH);
  #else
    digitalWrite(led.red, LOW);
    digitalWrite(led.green, LOW);
    digitalWrite(led.blue, LOW);
  #endif
}

void setup() {
  setupLed(led1);
  setupLed(led2);
}

void loop() {
  cycleColors(runway, rainbow, 500);
}
