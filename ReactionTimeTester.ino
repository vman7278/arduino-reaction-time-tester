
const int ledPin = 8;
const int buttonPin = 2;

unsigned long bestTime = 0;
int roundNumber = 0;

bool buttonPressed() {
  return digitalRead(buttonPin) == LOW;
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  randomSeed(analogRead(A0));

  Serial.println("REACTION TIME CHALLENGE!");
  Serial.println("Wait for the LED, then press!");
}

void loop() {
  digitalWrite(ledPin, LOW);

  while (buttonPressed()) {
    delay(10);
  }

  roundNumber++;

  Serial.println();
  Serial.print("ROUND ");
  Serial.println(roundNumber);

  // Three-second countdown
  for (int i = 3; i >= 1; i--) {
    Serial.println(i);

    for (int j = 0; j < 100; j++) {
      if (buttonPressed()) {
        falseStart();
        return;
      }
      delay(10);
    }
  }

  Serial.println("WAIT...");

  // Random delay between 1 and 4 seconds
  unsigned long waitTime = random(1000, 4001);
  unsigned long waitStart = millis();

  while (millis() - waitStart < waitTime) {
    if (buttonPressed()) {
      falseStart();
      return;
    }
  }

  // Start measuring reaction time
  digitalWrite(ledPin, HIGH);
  unsigned long startTime = millis();

  while (!buttonPressed()) {
  }

  unsigned long reactionTime = millis() - startTime;
  digitalWrite(ledPin, LOW);

  Serial.print("Reaction time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  if (bestTime == 0 || reactionTime < bestTime) {
    bestTime = reactionTime;
    Serial.println("NEW PERSONAL BEST!");
  }

  Serial.print("Best time: ");
  Serial.print(bestTime);
  Serial.println(" ms");

  delay(1000);
}

void falseStart() {
  digitalWrite(ledPin, LOW);
  Serial.println("FALSE START! Too early!");

  while (buttonPressed()) {
    delay(10);
  }

  delay(1500);
}
