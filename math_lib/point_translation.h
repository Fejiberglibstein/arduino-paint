#include "sensors.h"
#ifndef POINT_H
#define POINT_H

// Will scale a point in world-coords to fit within the screen-coords.
//
// Will return {-1, -1} if the point is out of range of the drawing area
Point scale_point(Point);

#endif
