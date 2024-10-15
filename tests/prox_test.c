#include "../lib/proximity.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define EPSILON 0.0001

void test_circle_intersection();

int main(int argc, char **argv) {
    test_circle_intersection();
}

bool compare_doubles(double d1, double d2) {
    return fabs(d1 - d2) < 0.0001;
}

bool points_equal(Point_t p1, Point_t p2) {
    return compare_doubles(p1.x, p2.x) && compare_doubles(p1.y, p2.y);
}

void test_circles(Circle_t c1, Circle_t c2, Point_t expected) {
    Point_t res1, res2;
    assert(circle_intersection(c1, c2, &res1, &res2) != 0 && "No points returned");

    fprintf(stderr, "{%f, %f} & {%f, %f}\n", res1.x, res1.y, res2.x, res2.y);
    assert(
        (points_equal(res1, expected) || points_equal(res2, expected)) &&
        "Neither points match the expected"
    );
}

// https://www.desmos.com/calculator/himklfxubq
// Used to get the radii and expected points for the tests
void test_circle_intersection() {

    test_circles(
        (Circle_t){.radius = 5, .center = (Point_t){.x = 0, .y = 0}},
        (Circle_t){.radius = 5, .center = (Point_t){.x = 10, .y = 0}},
        (Point_t){.x = 5, .y = 0}
    );

    test_circles(
        (Circle_t){.radius = 4.1231056, .center = (Point_t){.x = 0, .y = 0}},
        (Circle_t){.radius = 4.1231056, .center = (Point_t){.x = 5, .y = 5}},
        (Point_t){.x = 1, .y = 4}
    );

    test_circles(
        (Circle_t){.radius = 6.7082039, .center = (Point_t){.x = 12, .y = 9}},
        (Circle_t){.radius = 5.9637991, .center = (Point_t){.x = 5.13, .y = 6.1}},
        (Point_t){.x = 6, .y = 12}
    );

}
