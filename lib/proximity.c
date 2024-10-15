#include "./proximity.h"
#include <assert.h>
#include <math.h>

Point_t calculate_point(Circle_t points[4]) {
    return (Point_t){0};
}

// https://gist.github.com/jupdike/bfe5eb23d1c395d8a0a1a4ddd94882ac
// https://math.stackexchange.com/questions/256100/how-can-i-find-the-points-at-which-two-circles-intersect

int circle_intersection(Circle_t c1, Circle_t c2, Point_t *res1, Point_t *res2) {
    assert(c1.radius > 0 && "Radius should be positive");
    assert(c2.radius > 0 && "Radius should be positive");

    float r1 = c1.radius;
    float r2 = c2.radius;

    float x1 = c1.center.x;
    float x2 = c2.center.x;

    float y1 = c1.center.y;
    float y2 = c2.center.y;

    float dx = x1 - x2;
    float dy = y1 - y2;

    float dist = sqrt(dx * dx + dy * dy);

    if (fabs(r1 - r2) > dist || dist > r1 + r2) {
        return 0;
    }

    float dist2 = dist * dist;
    float dist4 = dist2 * dist2;

    float r1_2 = r1 * r1;
    float r2_2 = r2 * r2;

    float a = (r1_2 - r2_2) / (2 * dist2);
    float c = sqrt(2 * (r1_2 + r2_2) / dist2 - ((r1_2 - r2_2) * (r1_2 - r2_2)) / dist4 - 1);

    float fx = (x1 + x2) / 2 + a * (x2 - x1);
    float gx = c * (y2 - y1) / 2;

    float fy = (y1 + y2) / 2 + a * (y2 - y1);
    float gy = c * (x2 - x1) / 2;

    *res1 = (Point_t){.x = fx + gx, .y = fy + gy};
    *res2 = (Point_t){.x = fx - gx, .y = fy - gy};

    return 2;
}
