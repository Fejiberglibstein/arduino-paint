#include "./sensors.h"
#include <Arduino.h>

#define SENSOR_TO_CENTER 7
#define SENSOR_ANGLE 45

// (SENSOR_TO_CENTER * cos(SENSOR_ANGLE / 2))
const float H = 6.46715673;


Point sensor_coords[4] = {
    (Point){.x = 0,  .y = 0},
    (Point){.x = 20.6, .y = 0},
    (Point){.x = 20.6, .y = 41.2},
    (Point){.x = 0,  .y = 41.2},
};

Point area_coords[4] = {
    // NOTE: the order these are in matters!! do it in the same order please
    // xoxo
    (Point){.x = 2.1854442, .y = 16.542722},
    (Point){.x = 18.414556, .y = 16.542722},
    (Point){.x = 18.414556, .y = 24.657278},
    (Point){.x = 2.1854442, .y = 24.657278},
};


float calc_distance(int pin) {
 //set the pin as output for the trig pin part
    delayMicroseconds(50);
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
    float distance = duration * 0.0343;

    // pinMode(pin, OUTPUT);
    return distance;
}

float calc_corner_dist(Corner corner) {
    float dist1 = 0;
    if (corner.io_pin_left != -1) {
        dist1 = calc_distance(corner.io_pin_left);
    }
    float dist2 = calc_distance(corner.io_pin_right);
    // just take the smallest of either sensor

    /*Serial.print(dist1);*/
    /*Serial.print("\t");*/
    /*Serial.print(dist2);*/
    /*Serial.println();*/

    if (dist1 == 0 || dist2 == 0) {
        return (dist1 == 0) ? dist2 : dist1;
    }
    /*return (dist1 + dist2) * H * 0.5;*/
    return (dist1 < dist2) ? dist1 : dist2;
}

// Set each to high then calculate the distance
// pulseIn takes an echoPin - each corner has to use a different echo.
// Since it's one corner at a time, borrowing an echo pin from another
// sensor should be fine. May have to do trigger twice per corner in
// case the first times out.
void send_ping(Corner corners[CORNERS], Circle *circles) {
    /*Serial.println("\n\n\n\n\n\n\n");*/
    for (int i = 0; i < 4; i++) {
        circles[i].center = Point{.x = corners[i].x, .y = corners[i].y};
        circles[i].radius = calc_corner_dist(corners[i]);
    }
}
