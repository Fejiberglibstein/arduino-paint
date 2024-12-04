#include "point_translation.h"
#include <RGBmatrixPanel.h>

// IDK how colors work for this, 
#define COLOR matrix.Color333(7, 0, 0)

#define CLK  8
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

Corner corners[4] = {
    (Corner){
        .io_pin_left = A3,
        .io_pin_right = A4,

        .x = sensor_coords[0].x,
        .y = sensor_coords[0].y,
    },
    (Corner){
        .io_pin_left = 0, // 0
        .io_pin_right = A5,

        .x = sensor_coords[1].x,
        .y = sensor_coords[1].y,
    },
    (Corner){
        .io_pin_left = 1, // 1
        .io_pin_right = 11,

        .x = sensor_coords[2].x,
        .y = sensor_coords[2].y,
    },
    (Corner){
        .io_pin_left = 12,
        .io_pin_right = 13,

        .x = sensor_coords[3].x,
        .y = sensor_coords[3].y,
    }
};

void setup_screen() {
    matrix.begin();
}


void setup_sensors() {
    // TODO: you will need to do this for all trigpins and echos i think
    // pinMode(trigPin, OUTPUT);
    // pinMode(echo1, INPUT);
    // pinMode(echo2, INPUT);
}

void setup() {
    // Serial.begin(115200);
    setup_screen();
    setup_sensors();
}

int intersections = 0;
int real_intersections = 0;

void binary_display(int k, int loc) {
    for (int i = 15; i >= 0; i --) {
        int r = (k >> i & 1) * 7;
        matrix.drawPixel(loc, i, matrix.Color333(r, r, r));
    }
}

void loop() {
    Circle circles[4] = {0};

    // ping all the corners and get their returned distance into an array of
    // circles
    send_ping(corners, circles);

    // calculate the point from our four circles
    Point p = calculate_point(circles);

    if (p.x != -1 && p.y != -1) {
        // Translate the calculate point's coordinates into from world coordinates
        // to screen coordinates
        p = scale_point(p);
        intersections += 1;
        // binary_display(intersections, 0);

        if (p.x != -1 && p.y != -1) {
            real_intersections += 1;
            // binary_display(real_intersections, 1);
            matrix.drawPixel(p.x, p.y, COLOR);
        }
    }

    // Swapping the x and y here, check the note I left in
    // `point_translation.cpp`


}


