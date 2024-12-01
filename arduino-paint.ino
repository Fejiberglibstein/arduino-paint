#include "./point_translation.h"
// IDK how colors work for this, 
#define COLOR matrix.Color333(7, 7, 7)

#define CLK  8
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);
void setup_screen() {
    matrix.begin();
}


void setup_sensors() {
    // TODO: you will need to do this for all trigpins and echos i think
    pinMode(trigPin, OUTPUT);
    pinMode(echo1, INPUT);
    pinMode(echo2, INPUT);
}

Corner corners[4] = {
    (Corner){
        // TODO
        .trigPin = -1,
        .echoPinLeft = -1,
        .echoPinRight = -1,

        .x = sensor_coords[0].x,
        .y = sensor_coords[0].y,
    },
    (Corner){
        // TODO
        .trigPin = -1,
        .echoPinLeft = -1,
        .echoPinRight = -1,

        .x = sensor_coords[1].x,
        .y = sensor_coords[1].y,
    },
    (Corner){
        // TODO
        .trigPin = -1,
        .echoPinLeft = -1,
        .echoPinRight = -1,

        .x = sensor_coords[2].x,
        .y = sensor_coords[2].y,
    },
    (Corner){
        // TODO
        .trigPin = -1,
        .echoPinLeft = -1,
        .echoPinRight = -1,

        .x = sensor_coords[3].x,
        .y = sensor_coords[3].y,
    }
}

void setup() {
    Serial.begin(115200);
    setup_screen();
    setup_sensors();
}

void loop() {
    Circle circles[4] = {0};

    // ping all the corners and get their returned distance into an array of
    // circles
    send_ping(corners, &circles);

    // calculate the point from our four circles
    Point p = calculate_point(circles);

    // Translate the calculate point's coordinates into from world coordinates
    // to screen coordinates
    p = scale_point(p)

    // Swapping the x and y here, check the note I left in
    // `point_translation.cpp`
    matrix.drawPixel(p.y, p.x, COLOR);

}

