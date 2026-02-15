#include <Wire.h>
#include <VL53L0X.h>

#define BUTTON_PIN 6
#define LED_PIN 8

VL53L0X sensor;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Ambulance alert activated! /");
    delay(1000); // Keep the LED on for 1 second
    digitalWrite(LED_PIN, LOW);
  }

  int distance = sensor.readRangeContinuousMillimeters();
  if (sensor.timeoutOccurred()) {
    Serial.print("Sensor timeout!");
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");

  delay(100); // Small delay for sensor reading stability
}