#define BLYNK_PRINT_Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk credentials
char auth[] = "2079IT"; 
char ssid[] = "IoT_Network";        
char pass[] = "12345";    

// Eye blink sensor setup
int sensorPin = A0; // Eye blink sensor pin
int sensorValue = 0;
const int threshold = 500; // Threshold value for detecting drowsiness

// Blynk virtual pin
#define VIRTUAL_PIN V1

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize Blynk connection
  Blynk.begin(auth, ssid, pass);

  // Confirm setup
  Serial.println("Blynk and Eye Blink Sensor initialized...");
}

void loop() {
  // Run the Blynk app communication
  Blynk.run();

  // Read sensor value
  sensorValue = analogRead(sensorPin);
  
  // Check drowsiness status
  if (sensorValue > threshold) {
    // Send "DROWSY" status to Blynk and Serial Monitor
    Blynk.virtualWrite(VIRTUAL_PIN, "DROWSY");
    Serial.println("Driver is DROWSY!");
  } else {
    // Send "ALERT" status to Blynk and Serial Monitor
    Blynk.virtualWrite(VIRTUAL_PIN, "ALERT");
    Serial.println("Driver is ALERT!");
  }

  // Delay to avoid frequent updates
  delay(500);
}
