/*
https://www.tinkercad.com/things/2puN5vs3xur/editel?lessonid=EMPJJJYJI4U815F&projectid=OJGMQFOL26F9H0F&collectionid=O0K87SQL1W5N4P2&title=PIR+Motion+Sensor+%28Digital+Input%29#/lesson-viewer

Sample timmed lighting project
*/

int ledPin = 13;
int pirPin = 2;

int pirLevel = 0;
int strikes = 0;

int timmer =10000 //ms

unsigned long lastStrikeTime = 0; 
unsigned long lastMotionTime = 0; 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
}

bool readPIRLevel() {
  pirLevel = digitalRead(pirPin);
  return (pirLevel == HIGH);
}

void loop() {
  bool motionDetected = readPIRLevel();
  unsigned long currentTime = millis();

  if (motionDetected) {
    digitalWrite(ledPin, HIGH);
    lastMotionTime = currentTime; 
    strikes = 0; 
    Serial.println("Motion detected, strikes reset.");
  } else {
    if (currentTime - lastMotionTime >= timmer) { 
      digitalWrite(ledPin, LOW);
      strikes = 0; 
      Serial.println("Lights off due to inactivity.");
    } else if (currentTime - lastStrikeTime >= 1000) { 
      lastStrikeTime = currentTime;
      strikes++;
      Serial.print("Strikes: ");
      Serial.println(strikes);
    }
  }
}
