#include <Servo.h> // Include the Servo library

#define SWITCH_ON 3  // Define constant for switch on
#define SWITCH_OFF 2 // Define constant for switch off

#define SWITCH_ON1 1  // Define constant for second switch on
#define SWITCH_OFF1 0 // Define constant for second switch off

byte received_data[4]; // Array to store received data
int switch_pos;        // Variable to store switch position

Servo servo;  // Create Servo object for the first servo motor
Servo servo1; // Create Servo object for the second servo motor

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  Serial.println("ready"); // Print "ready" message to serial monitor
  
  servo.attach(7);  // Attach the first servo motor to pin 7
  servo1.attach(8); // Attach the second servo motor to pin 8

  servo.write(90);  // Set the initial position of the first servo to 90 degrees (center position)
  servo1.write(90); // Set the initial position of the second servo to 90 degrees (center position)
}

void loop() {
  if (Serial.available() > 0) { // Check if there is data available to read from serial port
    switch_control(); // Call switch_control function to process the received data
  }
}

void switch_control() {
  int size = Serial.readBytesUntil('\n', received_data, sizeof(received_data)); // Read the received data until newline character
  switch_pos = received_data[0]; // Extract the first byte which represents switch position
  
  Serial.print("SWITCH: "); // Print "SWITCH: " to serial monitor
  
  if (switch_pos == SWITCH_ON) { // If the received data corresponds to switch on
    Serial.println("ON"); // Print "ON" to serial monitor
    servo.write(0); // Rotate the first servo to 0 degrees (or any desired angle)
    delay(1000); // Wait for servo to move
  } 
  
  else if (switch_pos == SWITCH_OFF) { // If the received data corresponds to switch off
    Serial.println("OFF"); // Print "OFF" to serial monitor
    servo.write(90); // Set the first servo to the center position (90 degrees)
    delay(1000); // Wait for servo to move
  }
  
  else if (switch_pos == SWITCH_ON1) { // If the received data corresponds to second switch on
    Serial.println("ON1"); // Print "ON1" to serial monitor
    servo1.write(0); // Rotate the second servo to 0 degrees (or any desired angle)
    delay(1000); // Wait for servo to move
  } 
  
  else if (switch_pos == SWITCH_OFF1) { // If the received data corresponds to second switch off
    Serial.println("OFF1"); // Print "OFF1" to serial monitor
    servo1.write(90); // Set the second servo to the center position (90 degrees)
    delay(1000); // Wait for servo to move
  }
}
