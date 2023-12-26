/*  
 *  This is a proof of concept for "IOT based Home Automation Systems" 
 *  The code is written in the Arduino programming language
 *  The code has only been tested on an Arduino Uno
 *  The corresponding Android application for the control of the items is available online
 *  For any further doubts or inquiries contact at "parthsvas@gmail.com"
 */ 

// Include the LiquidCrystal library to control the LCD Display
#include <LiquidCrystal.h>

// Define pin numbers for various components to increase readability of the code
int r1 = 6; // Relay 1
int r2 = 5; // Relay 2
int spk = 4; // Speaker
int led = 3; // LED
int sensor = 2; // Sensor
char data = 0; // Variable to store incoming serial data

// Define pin numbers for the LCD Display
int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
// Initialize the LCD Display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  // Set the baud rate for serial data transmission
  Serial.begin(9600);
  
  // Set the mode of the pins according to their I/O requirement
  pinMode(sensor, INPUT); // Sensor is an input device
  pinMode(led, OUTPUT); // LED is an output device
  pinMode(spk, OUTPUT); // Speaker is an output device
  pinMode(r2, OUTPUT); // Relay 2 is an output device
  pinMode(r1, OUTPUT); // Relay 1 is an output device
  
  // Print a welcome message on the LCD Display
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("CSE Diploma 6th");
  lcd.setCursor(0, 1);
  lcd.print("Major Project");
}

void loop()
{
  // Check if there is any data available on the serial port
  if (Serial.available() > 0)
  {
    // Read the incoming data and print it on the serial monitor
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    
    // Clear the LCD Display and print a connection status message
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("BT Connected");
  }
  
  // Use a switch-case statement to perform actions based on the incoming data
  // and print a notification on the LCD Display
  switch (data)
  {
    case 'a':
      lcd.setCursor(2, 1);
      lcd.print("Relay 1 Off");
      digitalWrite(r1, LOW); // Turn off Relay 1
      break;
    case 'b':
      lcd.setCursor(2, 1);
      lcd.print("Relay 1 On");
      digitalWrite(r1, HIGH); // Turn on Relay 1
      break;
    case 'c':
      lcd.setCursor(2, 1);
      lcd.print("Relay 2 Off");
      digitalWrite(r2, LOW); // Turn off Relay 2
      break;
    case 'd':
      lcd.setCursor(2, 1);
      lcd.print("Relay 2 On");
      digitalWrite(r2, HIGH); // Turn on Relay 2
      break;
    case 'e':
      lcd.setCursor(2, 1);
      lcd.print("Speaker On");
      digitalWrite(spk, HIGH); // Turn on the speaker
      break;
    case 'f':
      lcd.setCursor(2, 1);
      lcd.print("Speaker Off");
      digitalWrite(spk, LOW); // Turn off the speaker
      break;
  }
  
  // Read the value from the PIR Sensor
  int sensorval = digitalRead(sensor);
  Serial.println(sensorval); // Print the sensor value on the serial monitor

  // Control the LED based on the sensor value
  if (sensorval == HIGH) {
    digitalWrite(led, LOW); // If the sensor detects motion, turn off the LED
  }
  else {
    digitalWrite(led, HIGH); // If the sensor does not detect motion, turn on the LED
  }
}
