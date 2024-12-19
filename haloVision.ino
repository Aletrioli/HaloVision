/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
float distance;
float prevDistance;
float speedDif;


// this is the value that controls how sensitive the distance sensor is
float sensSetting = 5;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  digitalWrite(LED_BUILTIN, LOW);

  // Clears the trigPin
  distance = prevDistance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // processing
  speedDif = abs(prevDistance - distance)
  Serial.print("Difference: ");
  Serial.println(speedDif);

  if (speedDif > sensSetting){
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
