/* ********************
Summer 2022 ELEE 4230 E
Project Update 1
Sidharth Chaudhary
******************** */

#define LED 13 // Pin for LED indicator

void setup() {
  // Initialize serial communication to recieve voltage output 
  Serial.begin(9600);
  // Declare the LED as an output
  pinMode(LED, OUTPUT);
}

void loop() {
  // Read input on analog pin A0
  int sensorValue = analogRead(A0);
  // Convert analog reading to voltage
  float voltage = sensorValue * (5.0 / 1023.0);
  // Print voltage for debugging
  Serial.println(voltage);
  // If room is dark enough to need lighting...
  if (voltage > 4.4)
    // Turn LED on
    digitalWrite(LED, HIGH);
  else
    // Turn LED off
    digitalWrite(LED, LOW);
}

