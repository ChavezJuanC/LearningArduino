int pinR = 6;
int pinB = 5;
int pinG = 3;

int tmpPin = A0;
int tmpTemp = 0;
int lightMode = 0;

int colorSets[9][3] = {
  //coldest
  { 0, 255, 255 },  // Cyan
  //colder
  { 135, 206, 250 },  // Light Sky Blue
  //cold
  { 173, 216, 230 },  // Light Blue
  //warm
  { 255, 215, 0 },   // Gold
  //warmer
  { 255, 165, 0 },   // Orange
  //warmest
  { 255, 140, 0 },   // Yellow-Orange
  //hot
  { 255, 69, 0 },    // Red-Orange
  //hotter
  { 255, 99, 71 },   // Tomato
  //hottest
  { 255, 0, 0 }      // Red
};

void setup() {
  // put your setup code here, to run once:
  pinMode(pinR, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(tmpPin, INPUT);
  Serial.begin(9600);
}

void setRGBMode(int lightMode) {
  analogWrite(pinR, colorSets[lightMode][0]);
  analogWrite(pinG, colorSets[lightMode][1]);
  analogWrite(pinB, colorSets[lightMode][2]);
}

void loop() {
  tmpTemp = analogRead(tmpPin);
  lightMode = map(tmpTemp, 20, 358, 0, 8);
  Serial.println(lightMode);
  setRGBMode(lightMode);
}
