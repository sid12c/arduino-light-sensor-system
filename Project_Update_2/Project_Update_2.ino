/* ********************
Summer 2022 ELEE 4230 E
Project Update 2
Sidharth Chaudhary
******************** */

#define LED 13 // Pin for LED indicator
#define sensorPin 3 // Pin for Ultrasonic Sensor
double timer = 0.0;

void setup() {
  // Initialize serial communication to recieve voltage output 
  Serial.begin(9600);
  // Declare the LED as an output and snesorPin as input
  pinMode(LED, OUTPUT);
  pinMode(sensorPin,INPUT);
}

void loop() {
  // Read input of ultrasonic on sensor pin 3
  byte state = digitalRead(sensorPin);
  // Read input of first ldr on analog pin A0
  int sensorValue = analogRead(A0);
  //int sensorValue1 = analogRead(A1)
  // Convert analog reading to voltage
  float voltage = sensorValue * (5.0 / 1023.0);
  //float voltage1 = sensorValue1 * (5.0 / 1023.0);
  // Print voltage for debugging
  Serial.println(voltage);
  // If room is dark enough to need lighting...
  if (voltage > 4.4) {//} && voltage1 > 4.4) {
    // if there is motion in the room
    if (state == 1) {
      // Turn LED on
      digitalWrite(LED, HIGH);
      // reset timer to 0 seconds
      timer = 0;  
    } else {
      if (timer >= 10.0) // adjust number for time inactive in seconds
        digitalWrite(LED, LOW);
      else
        timer += 0.5;
    }
  } else {
    // Turn LED off
    digitalWrite(LED, LOW);
  }
  delay(500);
}

