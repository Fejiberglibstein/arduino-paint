#include "proximity.h"
#ifndef SENSORS_H
#define SENSORS_H

typedef struct {
    int io_pin_left;
    int io_pin_right;

    float x;
    float y;
} Corner;

#define CORNERS 4

extern Point sensor_coords[4];

extern Point area_coords[4];

// https://www.desmos.com/geometry/itrkpaghqt
// Used the desmos to calculate these points
//
// These are the corners of the drawing area


// Send a ping to all four corners and create a circle for each corner.
//
// The circles returned will have their x and y as the same x and y of the
// corners, and the radii of the circle will be the distance returned by the
// proximity sensors
void send_ping(Corner[CORNERS], Circle **);

#endif 
