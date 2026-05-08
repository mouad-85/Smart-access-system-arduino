#include <Servo.h>

// -------------------- Pin Definitions --------------------
const int pirPin = 2;
const int trigPin = 3;
const int echoPin = 4;
const int servoPin = 5;
const int relayPin = 6;
const int buzzerPin = 7;
const int greenLedPin = 8;
const int redLedPin = 9;

// -------------------- Servo Object --------------------
Servo doorServo;

// -------------------- Variables --------------------
long duration;
int distance;
int pirState;

// -------------------- Distance Thresholds --------------------
const int accessDistance = 20;
const int alertDistance = 8;

// =====================================================
// SETUP
// =====================================================
void setup() {

  // Input Pins
  pinMode(pirPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Output Pins
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // Servo Setup
  doorServo.attach(servoPin);

  // Stop continuous servo initially
  doorServo.write(90);

  // Serial Monitor
  Serial.begin(9600);

  // -------------------- Initial Hardware Test --------------------

  // Green LED Test
  digitalWrite(greenLedPin, HIGH);
  delay(500);
  digitalWrite(greenLedPin, LOW);

  // Red LED Test
  digitalWrite(redLedPin, HIGH);
  delay(500);
  digitalWrite(redLedPin, LOW);

  // Relay Test
  digitalWrite(relayPin, HIGH);
  delay(500);
  digitalWrite(relayPin, LOW);

  // Buzzer Test
  tone(buzzerPin, 1000);
  delay(500);
  noTone(buzzerPin);

  // Servo Test (small rotation)
  doorServo.write(180);
  delay(300);

  // Stop Servo
  doorServo.write(90);

  // Initial Safe State
  digitalWrite(greenLedPin, HIGH);
}

// =====================================================
// DISTANCE FUNCTION
// =====================================================
int getDistance() {

  long total = 0;

  for (int i = 0; i < 3; i++) {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    total += duration * 0.034 / 2;

    delay(10);
  }

  distance = total / 3;

  return distance;
}

// =====================================================
// MAIN LOOP
// =====================================================
void loop() {

  // Read Sensors
  pirState = digitalRead(pirPin);

  distance = getDistance();

  // Serial Monitor Output
  Serial.print("PIR: ");
  Serial.print(pirState);
  Serial.print(" | Distance: ");
  Serial.println(distance);

  // =====================================================
  // NORMAL MODE
  // =====================================================
  if (pirState == LOW) {

    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);

    digitalWrite(relayPin, LOW);

    noTone(buzzerPin);

    // Stop Servo
    doorServo.write(90);
  }

  // =====================================================
  // ACCESS MODE
  // =====================================================
  else if (pirState == HIGH &&
           distance <= accessDistance &&
           distance > alertDistance) {

    Serial.println("ACCESS MODE");

    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);

    digitalWrite(relayPin, LOW);

    noTone(buzzerPin);

    // Small Open Rotation
    doorServo.write(180);
    delay(300);

    // Stop Servo
    doorServo.write(90);

    delay(2000);
  }

  // =====================================================
  // ALERT MODE
  // =====================================================
  else if (pirState == HIGH &&
           distance <= alertDistance) {

    Serial.println("ALERT MODE");

    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);

    digitalWrite(relayPin, HIGH);

    // Alarm Sound
    tone(buzzerPin, 1000);

    // Keep Door Closed
    doorServo.write(90);

    delay(1000);

    noTone(buzzerPin);
  }

  // =====================================================
  // DEFAULT FALLBACK
  // =====================================================
  else {

    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);

    digitalWrite(relayPin, LOW);

    noTone(buzzerPin);

    doorServo.write(90);
  }

  delay(100);
}
