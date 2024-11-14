const int trigPin = A3;
const int echo1 = A4;
const int echo2 = A5;

float distance1;
float distance2;


float calc_distance(int echoPin){
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

// Tests that one trig pin works for the whole corner (two sensors). Not accounting for angle.
// Angle needs to be fixed, we get incorrect readings in the middle
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
}

// Can't catch both signals - the second times out
// Just do twice ig - that does in fact work, just insert a delay in between susequent readings
// Try to minimize that

void loop() {
  // put your main code here, to run repeatedly:
  distance1 = calc_distance(echo1);
  delay(100);
  distance2 = calc_distance(echo2);
  delay(100);
  Serial.print("Distance Sensor 1: ");
  Serial.println(distance1);
  Serial.print("Distance Sensor 2: ");
  Serial.println(distance2);

  // just take the smallest of either sensor probably
}
