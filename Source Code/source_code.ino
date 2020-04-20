/*  This is a proof of concept for "IOT based Home Automation Systems" 
 *  The code is written in the Aurdrino programming language
 *  The code has only been tested on a Aurduino Uno
 *  The corrosponding Android appilication for the control of the items is available online
 *  For any further doubts or inquiries contact at "parthsvas@gmail.com"
 */ 

  // Loading the library needed to run the LCD Display
#include <LiquidCrystal.h>

  // Creating variables for pin numbers to increse understanding of the code
int r1 = 6;
int r2 = 5;
int spk = 4;
int led = 3;
int sensor = 2;
char data = 0;
  // Assigning different pins of the LCD Display to different pins for output
int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    // Seting the baud rate for serial data transmission
  Serial.begin(9600);
    // Setting the pins according to their I/O requirement
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
    // Printing a message on the LCD Display
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("CSE Diploma 6th");
  lcd.setCursor(0, 1);
  lcd.print("Major Project");
}

void loop()
{
  if (Serial.available() > 0)
  {
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("BT Connected");
  }
    // Setting up a Switch-Case statement for the various inputs to their actions and printing a notification on the LCD Display
  switch (data)
  {
    case 'a':
      lcd.setCursor(2, 1);
      lcd.print("Relay 1 Off");
      digitalWrite(r1, LOW);
      break;
    case 'b':
      lcd.setCursor(2, 1);
      lcd.print("Relay 1 On");
      digitalWrite(r1, HIGH);
      break;
    case 'c':
      lcd.setCursor(2, 1);
      lcd.print("Relay 2 Off");
      digitalWrite(r2, LOW);
      break;
    case 'd':
      lcd.setCursor(2, 1);
      lcd.print("Relay 2 On");
      digitalWrite(r2, HIGH);
      break;
    case 'e':
      lcd.setCursor(2, 1);
      lcd.print("Speaker On");
      digitalWrite(spk, HIGH);
      break;
    case 'f':
      lcd.setCursor(2, 1);
      lcd.print("Speaker Off");
      digitalWrite(spk, LOW);
      break;
  }
    // Setting up the PIR Sensor to respond to any motion
  int sensorval = digitalRead(sensor);
  Serial.println(sensorval);

  if (sensorval == HIGH) {
    digitalWrite(led, LOW);
  }
  else {
    digitalWrite(led, HIGH);
  }
}
