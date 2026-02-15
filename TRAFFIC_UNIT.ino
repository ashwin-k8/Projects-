// TRAFFIC_UNIT.ino - RSU Traffic Light Controller Code

#include <Arduino.h>

#define RED_LIGHT 2
#define YELLOW_LIGHT 3
#define GREEN_LIGHT 4

void setup() {
    pinMode(RED_LIGHT, OUTPUT);
    pinMode(YELLOW_LIGHT, OUTPUT);
    pinMode(GREEN_LIGHT, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Simulate traffic light states
    digitalWrite(GREEN_LIGHT, HIGH);
    Serial.println("Traffic light state: GREEN");
    delay(7000);

    digitalWrite(GREEN_LIGHT, LOW);
    digitalWrite(YELLOW_LIGHT, HIGH);
    Serial.println("Traffic light state: YELLOW");
    delay(2000);

    digitalWrite(YELLOW_LIGHT, LOW);
    digitalWrite(RED_LIGHT, HIGH);
    Serial.println("Traffic light state: RED");
    delay(7000);

    digitalWrite(RED_LIGHT, LOW);
}