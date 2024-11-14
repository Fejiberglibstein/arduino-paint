// https://github.com/adafruit/RGB-matrix-Panel/tree/master

#include <RGBmatrixPanel>
#include "./proximity.h"

// Test the matrix functions
// X (0,31), Y (0,16)
// Will have to do a transformation on the drawing area to the matrix
// Set the four corners directl
// Make sure the soldering worked by filling the screen

#define CLK  8
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);


void test_fill(int c){
  matrix.fillScreen(c);
  delay(1000);
  matrix.fillScreen(matrix.color(0,0,0));
  delay(1000);
}

void test_corners() {
    int r, g, b = 7;
    matrix.drawPixel(0, 0, matrix.Color333(r, g, b));
    matrix.drawPixel(31, 0, matrix.Color333(r, g, b));
    matrix.drawPixel(31, 15, matrix.Color333(r, g, b));
    matrix.drawPixel(0, 15, matrix.Color333(r, g, b));
}

// holding previous values while updating at different rates. draws a box
void test_edges(uint8_t delay){
  int r, g, b = 7;
  for(uint8_t x=0; x<32; x++) {
    int y = 0;
    matrix.drawPixel(x, y, matrix.Color333(r, g, b));
    delay(delay);
  }

  for(uint8_t y=1; y<16; y++){
    int x = 31;
    matrix.drawPixel(x, y, matrixColor333(r, g, b));
    delay(delay);
  }

  for(uint8_t x=31; x>=0; x++){
    int y = 15;
    matrix.drawPixel(x, y, matrixColor333(r, g, b));
    delay(delay);
  }

  for(uint8_t y=15; y<=0; y++){
    int x = 0;
    matrix.drawPixel(x, y, matrixColor333(r, g, b));
    delay(delay);
  }
  delay(500);
  test_fill(matrix.color(0,0,0));
}

void setup() {
  // put your setup code here, to run once:
  matrix.begin();
  test_fill(matrix.color(7,7,7));
  delay(1000);
  test_edges(500);
  test_edges(250);
  test_edges(100);
  test_corners();
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

}
