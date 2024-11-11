#include "sensors.h"

// Test all four sensors in one arena, try to only use two echo pins?
// Lay out specific points in the arena so thy can be verified
// Each trigger controls one corner
// If this works, add the other four
// Once set up we can measure the physical distance and verify
// Check full angle with two sensors per corner

const int trigPin1 = 0;
const int trigPin2 = 1;
const int trigPin3 = 11;
const int trigPin4 = 12;

// Stagger these pins so one sensor of each corner is mapped to each
// Later probably make a struct for a corner

const int echo1 = A4;
const int echo2 = A5;

float distance1;
float distance2;
float distance3;
float distance4;

float calc_distance(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  float distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  return distance;
}

// just take the smallest of either sensor probably

float calc_corner_dist(Corner corner){
  float dist1 = calc_distance(corner.trigPin, corner.echoPinLeft);
  delay(500);
  float dist2 = calc_distance(corner.trigPin, corner.echoPinRight);
  delay(500);
  return (dist1 <= dist2) ? dist1 : dist2;
}

// Tests that one echo pin works for the whole corner (two sensors). Not accounting for angle.
// Angle needs to be fixed, we get incorrect readings in the middle
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);

  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);

  Serial.begin(9600);
}

// Can't catch both signals - the second times out
// Just do twice ig --> that does in fact work, just insert a delay in between susequent readings
// also try to minimize that

void loop() {
  // put your main code here, to run repeatedly:

  Corner corner1 = {trigPin1, echo1, echo2, 0.0, 0.0};
  Corner corner2 = {trigPin2, echo1, echo2, 20.0, 0.0};
  Corner corner3 = {trigPin3, echo1, echo2, 20.0,20.0};
  Corner corner4 = {trigPin4, echo1, echo2, 0.0,20.0};

  distance1 = calc_corner_dist(corner1);
  distance2 = calc_corner_dist(corner2);
  distance3 = calc_corner_dist(corner3);
  distance4 = calc_corner_dist(corner4);  

  Serial.print("Distance Sensor 1: ");
  Serial.println(distance1);
  Serial.print("Distance Sensor 2: ");
  Serial.println(distance2);
  Serial.print("Distance Sensor 3: ");
  Serial.println(distance3);
  Serial.print("Distance Sensor 4: ");
  Serial.println(distance4);
}
