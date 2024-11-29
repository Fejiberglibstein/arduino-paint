#include "sensors.h"
#ifndef SENSORS_H
#define SENSORS_H

// Will scale a point in world-coords to fit within the screen-coords.
//
// Will return {-1, -1} if the point is out of range of the drawing area
Point scale_point(Point);

#endif
