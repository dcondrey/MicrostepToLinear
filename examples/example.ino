#include "MicrostepToLinear.h"

// Initialize with default values
MicrostepToLinear converter;

void setup() {
  // Begin serial communication
  Serial.begin(9600);

  // Custom initialization with step angle of 1.8 degrees, 16 microsteps, and pitch of 2.0 mm
  converter = MicrostepToLinear(1.8, 16, 2.0);

  // Alternatively, set parameters individually
  converter.setStepAngle(1.8);
  converter.setMicrosteps(16);
  converter.setPitch(2.0);
}

void loop() {
  // Simulate a stepper motor moving 3200 microsteps
  int microstepCount = 3200;

  // Convert microsteps to linear distance
  float linearDistance = converter.convert(microstepCount);

  // Output the result to the serial monitor
  Serial.print("Linear Distance: ");
  Serial.print(linearDistance);
  Serial.println(" mm");

  // Wait 5 seconds before the next loop iteration
  delay(5000);
}
  