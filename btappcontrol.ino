/*
  Project: Remote Control Robot using App
  Author: Craig Ratchford
  Description:
    This Arduino program controls a two-motor robot via commands received over Serial1.
    The robot can move forward, backward, turn left, turn right, and stop. 
    Commands are single-character inputs sent from an app:
      - 'f' : move forward
      - 'b' : move backward
      - 'r' : turn right
      - 'z' : turn left
      - 's' : stop
*/

#include "Arduino.h"

// Motor driver pins (L298N)
const int motor1A = 11;    // IN1
const int motor1B = 7;     // IN2
const int motor2A = 8;     // IN3
const int motor2B = 9;     // IN4
const int enA = 10;        // Enable motor 1
const int enB = 11;        // Enable motor 2

// Function prototypes
void turnRight();
void moveForward();
void stopMotors();
void back();
void turnLeft();

void setup() {
  // Initialize built-in LED pin
  pinMode(13, OUTPUT);

  // Initialize Serial ports
  Serial1.begin(9600); // For receiving commands from app (e.g., Bluetooth)
  Serial.begin(9600);  // For debugging on Serial Monitor

  // Set motor pins as outputs
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);

  // Enable pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

// Buffers to store incoming commands
String messageBuffer = "";
String message = "";

void loop() {
  // Check if there is data available from Serial1 (app input)
  while (Serial1.available() > 0) {
    char data = (char) Serial1.read(); // Read a single character command

    // Forward command
    if (data == 'f') {
      message = data;
      Serial.print(message);
      moveForward();
      message = "";
    }
    // Stop command
    else if (data == 's') {
      message = data;
      Serial.print(message);
      stopMotors();
      message = "";
    }
    // Turn right command
    else if (data == 'r') {
      message = data;
      Serial.print(message);
      turnRight();
      message = "";
    }
    // Backward command
    else if (data == 'b') {
      message = data;
      Serial.print(message);
      back();
      message = "";
    }
    // Turn left command
    else if (data == 'z') {
      message = data;
      Serial.print(message);
      turnLeft();
      message = "";
    }
  }
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);

  // Set motor speeds for turning
  analogWrite(enA, 5);
  analogWrite(enB, 5);
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);

  // Set motor speeds
  analogWrite(enA, 140);
  analogWrite(enB, 130);
}

// Function to stop the robot
void stopMotors() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);

  // Set motor speeds for turning
  analogWrite(enA, 5);
  analogWrite(enB, 5);
}

// Function to move the robot backward
void back() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);

  // Set motor speeds for reverse
  analogWrite(enA, 140);
  analogWrite(enB, 130);
}
