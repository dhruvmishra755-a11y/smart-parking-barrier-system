#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

const int detectionDistance = 20;
const int closedAngle = 0;
const int openAngle = 90;

const unsigned long closingDelay = 2000;

Servo barrierServo;

long duration;
float distance;

bool gateOpen = false;
unsigned long lastVehicleSeen = 0;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  barrierServo.attach(servoPin);
  barrierServo.write(closedAngle);

  Serial.println("Smart Parking Barrier System Ready");
}

void loop() {
  // Generate the ultrasonic trigger pulse.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the returning echo.
  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    distance = -1;
  } else {
    distance = duration * 0.0343 / 2.0;
  }

  unsigned long currentTime = millis();

  Serial.print("Distance: ");
  if (distance < 0) {
    Serial.println("No echo");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Open the barrier when a vehicle is detected within 20 cm.
  if (distance > 0 && distance < detectionDistance) {
    lastVehicleSeen = currentTime;

    if (!gateOpen) {
      barrierServo.write(openAngle);
      gateOpen = true;
      Serial.println("Vehicle detected: GATE OPEN");
    }
  }

  // Close the barrier after no valid near detection for 2 seconds.
  if (gateOpen &&
      currentTime - lastVehicleSeen >= closingDelay) {
    barrierServo.write(closedAngle);
    gateOpen = false;
    Serial.println("Area clear: GATE CLOSED");
  }

  delay(100);
}
