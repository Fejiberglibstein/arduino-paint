// #include <Arduino.h>
#include "./proximity.h"

typedef struct {
    int trigPin;
    int echoPinLeft;
    int echoPinRight;
    float x;
    float y;
} Corner;

#define CORNERS 4

// Calculate the four distances from each corner in the arena
// Set each to high then calculate the distance
// pulseIn takes an echoPin - each corner has to use a different echo.
// Since it's one corner at a time, borrowing an echo pin from another
// sensor should be fine. May have to do trigger twice per corner in
// case the first times out.

void send_ping(Corner[CORNERS], Circle *[CORNERS]);
