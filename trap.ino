/*

*/

#define COMMON_ANODE

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
    rainbow();
}

void rainbow() {
  setColor(255, 0, 0);  // red
  delay(500);
  setColor(255, 127, 0); // orange (#FF7F00)
  delay(500);
  setColor(255, 255, 0);  // yellow
  delay(500);
  setColor(0, 255, 0);  // green
  delay(500);
  setColor(0, 0, 255);  // blue
  delay(500);
  setColor(148, 0, 211);  // violet
  delay(500);
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
