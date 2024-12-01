#include "./proximity.h"
#ifndef PROXIMITY_H
#define PROXIMITY_H

typedef struct {
    int trigPin;
    int echoPinLeft;
    int echoPinRight;
    float x;
    float y;
} Corner;

#define CORNERS 4

Point sensor_coords[4] = {
    (Point){.x = 0,  .y = 0},
    (Point){.x = 10, .y = 0},
    (Point){.x = 10, .y = 5},
    (Point){.x = 0,  .y = 5},
};

// https://www.desmos.com/geometry/itrkpaghqt
// Used the desmos to calculate these points
//
// These are the corners of the drawing area
Point area_coords[4] = {
    // NOTE: the order these are in matters!! do it in the same order please
    // xoxo
    (Point){.x = 3.938813, .y = 0.37762592},
    (Point){.x = 6.061187, .y = 0.37762592},
    (Point){.x = 6.061187, .y = 4.6223741},
    (Point){.x = 3.938813, .y = 4.6223741},
};


// Send a ping to all four corners and create a circle for each corner.
//
// The circles returned will have their x and y as the same x and y of the
// corners, and the radii of the circle will be the distance returned by the
// proximity sensors
void send_ping(Corner[CORNERS], Circle *[CORNERS]);

#endif 
