
const int trigPin1 = A3;
const int trigPin2 = 11;
const int trigPin3 = A5;
const int trigPin4 = A4;

// Stagger these pins so one sensor of each corner is mapped to each
// Later probably make a struct for a corner

const int echoPin1 = 13;
const int echoPin2 = 12;
const int echoPin3 = 2;
const int echoPin4 = 3;

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
  float distance = duration * 0.0343 / 2;
  // Prints the distance on the Serial Monitor
  return distance;
  //filter > 35 or whatever the area is
}

// Tests that one echo pin works for the whole arena. Not accounting for angles.
// First test for arena
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);

  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);

  Serial.begin(9600);
}

// Can't catch both signals - the second times out
// Just do twice ig --> that does in fact work, just insert a delay in between susequent readings
// also try to minimize that

void loop() {
  // put your main code here, to run repeatedly:
  distance1 = calc_distance(trigPin1, echoPin1);
  delay(50);
  distance2 = calc_distance(trigPin2, echoPin2);
  delay(50);
  distance3 = calc_distance(trigPin3, echoPin3);
  delay(50);
  distance4 = calc_distance(trigPin4, echoPin4);  
  delay(50);

  Serial.print("Distance Sensor 1: ");
  Serial.println(distance1);
  Serial.print("Distance Sensor 2: ");
  Serial.println(distance2);
  Serial.print("Distance Sensor 3: ");
  Serial.println(distance3);
  Serial.print("Distance Sensor 4: ");
  Serial.println(distance4);
  delay(1000);
}