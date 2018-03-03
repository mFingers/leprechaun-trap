/*

*/

#define COMMON_ANODE

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int led[3] = {9, 10, 11};

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
    rainbow();
}

void rainbow() {
  setColor(led, 255, 0, 0);  // red
  delay(500);
  setColor(led, 255, 127, 0); // orange (#FF7F00)
  delay(500);
  setColor(led, 255, 255, 0);  // yellow
  delay(500);
  setColor(led, 0, 255, 0);  // green
  delay(500);
  setColor(led, 0, 0, 255);  // blue
  delay(500);
  setColor(led, 148, 0, 211);  // violet
  delay(500);
}

void setColor(int pin[], int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif

  analogWrite(pin[0], red);
  analogWrite(pin[1], green);
  analogWrite(pin[2], blue);
}
