#include "./sensors.h"
#include <Arduino.h>

float calc_distance(int pin) {
 //set the pin as output for the trig pin part
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin, LOW);
    //set the pin as input for the echo section
    pinMode(pin, INPUT);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(pin, HIGH);
    // Calculating the distance
    float distance = duration * 0.034 / 2;
    return distance;
}

float calc_corner_dist(Corner corner) {
    float dist1 = calc_distance(corner.io_pin_left);
    delay(500);
    float dist2 = calc_distance(corner.trigPin, io_pin_right);
    delay(500);
    // just take the smallest of either sensor probably
    return (dist1 < dist2) ? dist1 : dist2;
}

// Set each to high then calculate the distance
// pulseIn takes an echoPin - each corner has to use a different echo.
// Since it's one corner at a time, borrowing an echo pin from another
// sensor should be fine. May have to do trigger twice per corner in
// case the first times out.
void send_ping(Corner corners[CORNERS], Circle *circles[CORNERS]) {
    for (int i = 0; i < CORNERS; i++) {
        circles[i]->center = Point{.x = corners[i].x, .y = corners[i].y};
        circles[i]->radius = calc_corner_dist(corners[i]);
    }
}
