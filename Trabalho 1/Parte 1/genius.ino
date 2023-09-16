int input;

const int pinoRED = 11;
const int pinoGREEN = 10;
const int pinoBLUE = 9;

void blinkRGB(int r, int g, int b, int _delay = 1000) {
  analogWrite(pinoRED, r);
  analogWrite(pinoGREEN, g);
  analogWrite(pinoBLUE, b);
}

void blueLed() {
  blinkRGB(255, 255, 0);
}

void greenLed() {
  blinkRGB(255, 0, 255);
}

void redLed() {
  blinkRGB(0, 255, 255);
}

void yellowLed() {
  blinkRGB(200, 100, 255);
}

void setup() {
  Serial.begin(9600);

  pinMode(pinoRED, OUTPUT);
  pinMode(pinoGREEN, OUTPUT);
  pinMode(pinoBLUE, OUTPUT);

  Serial.setTimeout(1);
}

void loop() {

  while (!Serial.available()) {};

  input = Serial.readString().toInt();

  if (input == 0) {
    blueLed();
  } else if (input == 1) {
    yellowLed();
  } else if (input == 2) {
    redLed();
  } else if (input == 3) {
    greenLed();
  } else {
    blinkRGB(0, 0, 0);
  }

  Serial.print(input);
}
