#include "./sensors.h"

float calc_distance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    float distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    return distance;
}

// just take the smallest of either sensor probably

float calc_corner_dist(Corner corner) {
    float dist1 = calc_distance(corner.trigPin, corner.echoPinLeft);
    delay(500);
    float dist2 = calc_distance(corner.trigPin, corner.echoPinRight);
    delay(500);
    return (dist1 <= dist2) ? dist1 : dist2;
}

void send_ping(Corner corners[CORNERS], Circle *circles[CORNERS]) {
    for (int i = 0; i < CORNERS; i++) {
        circles[i]->center = Point{.x = corners[i].x, .y = corners[i].y};
        circles[i]->radius = calc_corner_dist(corners[i]);
    }
}
