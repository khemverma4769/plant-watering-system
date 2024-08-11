// Define pins
const int moistureSensorPin = A0;  // Soil moisture sensor connected to A0
const int relayPin = 7;            // Relay connected to digital pin 7

// Define moisture threshold
int moistureThreshold = 350; // Adjust this value based on your sensor and soil

void setup() {
  pinMode(relayPin, OUTPUT);  // Set relay pin as output
  digitalWrite(relayPin, HIGH); // Ensure the pump is off at the start
  Serial.begin(9600);          // Start serial communication for monitoring
}

void loop() {
  int moistureValue = analogRead(moistureSensorPin); // Read moisture sensor value

  // Print moisture value to Serial Monitor
  Serial.print("Moisture Value: ");
  Serial.println(moistureValue);

  // If the soil is dry, turn on the pump
  if(moistureValue < moistureThreshold) {
    digitalWrite(relayPin, LOW);  // Turn on the pump
    Serial.println("Pump ON");
  } 
  // If the soil is wet enough, turn off the pump
  else {
    digitalWrite(relayPin, HIGH); // Turn off the pump
    Serial.println("Pump OFF");
  }

  delay(1000); // Wait 1 second before taking another reading
}
