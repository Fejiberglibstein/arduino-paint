
// gcc lib/proximity.c tests/proxest.c -lm -o test && ./test

#include "../point_translation.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define EPSILON 0.0001

void test_circle_intersection();
void test_calculate_point();
void test_translation();

int main(int argc, char **argv) {
    test_circle_intersection();
    test_calculate_point();
    test_translation();
}

bool compare_doubles(double d1, double d2) {
    return fabs(d1 - d2) < 0.0001;
}

bool points_equal(Point p1, Point p2) {
    return compare_doubles(p1.x, p2.x) && compare_doubles(p1.y, p2.y);
}

void test_circles(Circle c1, Circle c2, Point expected) {
    Point res1, res2;
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
        (Circle){.radius = 5, .center = (Point){.x = 0, .y = 0}},
        (Circle){.radius = 5, .center = (Point){.x = 10, .y = 0}},
        (Point){.x = 5, .y = 0}
    );

    test_circles(
        (Circle){.radius = 4.1231056, .center = (Point){.x = 0, .y = 0}},
        (Circle){.radius = 4.1231056, .center = (Point){.x = 5, .y = 5}},
        (Point){.x = 1, .y = 4}
    );

    test_circles(
        (Circle){.radius = 6.7082039, .center = (Point){.x = 12, .y = 9}},
        (Circle){.radius = 5.9637991, .center = (Point){.x = 5.13, .y = 6.1}},
        (Point){.x = 6, .y = 12}
    );
}

// https://www.desmos.com/calculator/mtrovlvxyv
// Used to get the radii and expected points for the tests
#define TEST_SIZE 2
void test_calculate_point() {

    Circle circleest[TEST_SIZE][4] = {
        {
            (Circle){.radius = 4.6341774, .center = {.x = 0, .y = 0}},
            (Circle){.radius = 6.2829611, .center = {.x = 0, .y = 10}},
            (Circle){.radius = 9.8120130, .center = {.x = 10, .y = 10}},
            (Circle){.radius = 8.8473499, .center = {.x = 10, .y = 0}},
        },
        {
            (Circle){.radius = 4.6337566, .center = {.x = 3.7, .y = 0.37}},
            (Circle){.radius = 9.2579263, .center = {.x = 3.48, .y = 11.82}},
            (Circle){.radius = 2.0560156, .center = {.x = 6, .y = 5}},
            (Circle){.radius = 5.3851648, .center = {.x = 6.72, .y = -2}},
        }
    };

    Point expected[TEST_SIZE] = {
        (Point){.x = 2.16, .y = 4.1},
        (Point){.x = 7.24, .y = 3.36},
    };

    for (int i = 0; i < TEST_SIZE; i++) {
        Circle *circles = circleest[i];

        assert(points_equal(calculate_point(circles), expected[i]) && "Points were NOT equal");
    }
}

void test_translation() {
    Point res;

    res = scale_point(area_coords[0]);
    assert(res.x == 0);
    assert(res.y == 0);

    res = scale_point(area_coords[1]);
    assert(res.x == 32);
    assert(res.y == 0);

    res = scale_point(area_coords[2]);
    assert(res.x == 32);
    assert(res.y == 16);

    res = scale_point(area_coords[3]);
    assert(res.x == 0);
    assert(res.y == 16);
}
