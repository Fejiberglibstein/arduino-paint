#include "point_translation.h"

// Screen is currently set up to be vertical. If you change this you'll need to
// change around the points and recalculate on desmos. Currently `sensor_coords`
// are horizontally scaled which makes `area_coords` be vertically scaled. 
// You will need to flip this to make the screen horizontal
#define SCREEN_PIXEL_HEIGHT 16
#define SCREEN_PIXEL_WIDTH 32

Point scale_point(Point pt) {
    Point bottom_left = area_coords[0];
    Point top_right = area_coords[2];

    // Check if the point is inside the bounding box of the drawing area
    if (
       pt.x < bottom_left.x || pt.y < bottom_left.y || 
       pt.x > top_right.x || pt.y > top_right.y 
    ) {
        return (Point) {.x = -1, .y = -1};
    }

    Point new_pt;

    // Translate the coordinates so that the origin is at the bottom left corner
    // of the drawing area
    new_pt.x = pt.x - bottom_left.x;
    new_pt.y = pt.y - bottom_left.y;

    float width = top_right.x - bottom_left.x;
    float height = top_right.y - bottom_left.y;

    // Scale the coordinates down so that {0,0} is `bottom_left` and 
    // {1,1} is `top_right`

    new_pt.x /= width;
    new_pt.y /= height;

    new_pt.x *= SCREEN_PIXEL_WIDTH;
    new_pt.y *= SCREEN_PIXEL_HEIGHT;

    return new_pt;
}
