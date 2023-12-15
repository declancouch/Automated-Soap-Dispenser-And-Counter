#include <Arduino.h>
#include <Servo.h>
#define Servo2_Pin A2 //left servo
#define infared_pin A0
#define green A5
#define yellow A4
Servo servo2 ;
// Pin definitions for segments
int pinA = 11; int pinB = 7; int pinC = 4; int pinD = 2;
int pinE = 13; int pinF = 10; int pinG = 5;
int pinDP = 3; 
// Pin definitions for digit selection
int D1 = 12; int D2 = 9; int D3 = 8; int D4 = 6;
const int pin2 =  Servo2_Pin;
const int green_pin =  green;
const int yellow_pin =  yellow;
static int count = 0;
void setup() {
  // Bellow is just me setting all the segments, LEDS, Digits and servos as outputs in their correct pin spot
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
 pinMode(green_pin, OUTPUT);
pinMode(yellow_pin, OUTPUT);
  // turning off all digits off in the begining once compiles
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
    // setup
  servo2.attach(pin2); //left
    pinMode(infared_pin, INPUT_PULLUP);


  Serial.begin(9600);
  delay(50);
}


bool handWasDetected = false; // variable to track hand presence


void loop() {
   int infraredSensorState = digitalRead(infared_pin); // initiallize the infrared sensor
      servo2.write(0);//0 degrees starting point
   if (infraredSensorState == LOW && !handWasDetected) {// Check if hand is detected and wasn't already detected in the previous loop
      // Turn on yellow light and turn off green light
    digitalWrite(green_pin, LOW);
      digitalWrite(yellow_pin, HIGH);


      // Activate the servo 


    servo2.write(90);//90 degrees rotate
      delay(1000); // Wait for the dispensing action to complete
      servo2.write(0);//reset 
      count++;
      if (count > 9999) {
         count = 0;
      }
//      displayNumber(count);
      handWasDetected = true; // update the state to indicate that hand was detected and stay here until it moves
   } else if (infraredSensorState == HIGH && handWasDetected) {
      // Turn off yellow light and turn on green light
      digitalWrite(green_pin, HIGH);
      digitalWrite(yellow_pin, LOW);
      handWasDetected = false; // Reset the state when no hand is detected
   }
   displayNumber(count); // Continuously update the display by calling the for/if loop function
   delayMicroseconds(2500); //small delay here to avoid burning out the HEX display.
}
void displayNumber(unsigned int number) {
   int digitValues[4];
  digitValues[0] = number / 1000;          // Thousands place calculation for D1
  digitValues[1] = (number / 100) % 10;    // Hundreds place calculation for D2
  digitValues[2] = (number / 10) % 10;     // Tens place calculation for D3
  digitValues[3] = number % 10;            //Ones Place Calculation for D4
 int pinactivation_number;
for(int i = 0; i < 4; i++){
  if(i == 0)
  {
pinactivation_number = 12;
    
  }
    else if(i == 1)
  {
pinactivation_number = 9;
    
  }
    else if(i == 2)
  {
pinactivation_number = 8;
    
  }
    else if(i == 3)
  {
pinactivation_number = 6;
    
  }


digitalWrite(pinactivation_number, LOW); //turn on LED digit correlated within the loop. Then call the specific display function based on what the number is
  switch(digitValues[i])
  {
    case 0:
    display0();
    
    break;


    case 1:
    display1();
    break;


    case 2:
    display2();
    break;


    case 3:
    display3();
    break;


    case 4:
    display4();
    break;


    case 5:
    display5();
    break;
    
    case 6:
    display6();
    break;


    case 7:
    display7();
    break;


    case 8:
    display8();
    break;


    case 9:
    display9();
    break;
  }


  delay(100); //this delay is here for how long the number will be display, before it moves to the next number. The goal here was to get a mutliplexing effect which makes it look like its up the entire time by going through each number fast


digitalWrite(pinactivation_number, HIGH); //turn off LED digit

}   
    
}


//Bellow are just all the functions for displaying specific numbers, using the segment logic I learned from EECE 229
void display0() {
digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, HIGH);
}


void display1() {
digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW);
}


void display2() {
digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}
void display3() {
digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}
void display4() {
digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}
void display5() {
digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}
void display6() {
digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}
void display7() {
digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW);
}
void display8() {
digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}
void display9() {
digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}
