/*
#include "StepperMotor.h"

// Stepper Motor 1
#define but_pin1    2          //32        // Limit switch
#define rot_pin1    55        //43   // CW = clockwise and CCW = counterclockwise
#define en_pin1     38        //23        // Turn on or off motor
#define step_pin1   54        //33  // Steps
#define sold_pin1   23        // Turn on or off of solenoid

// Stepper Motor 2
#define but_pin2    18        //34
#define rot_pin2    61          //45
#define en_pin2     56          //25
#define step_pin2   60          //35
#define sold_pin2   24

// Stepper Motor 3
#define but_pin3    19          //36
#define rot_pin3    48          //47
#define en_pin3     62          //27
#define step_pin3   46          //37
#define sold_pin3   26

// Stepper Motor 4
#define but_pin4    15            //38
#define rot_pin4    28           //49
#define en_pin4     24           //29
#define step_pin4   26           //39
#define sold_pin4   28


// Stepper Motor 5
#define but_pin5    14         //40
#define rot_pin5    34          //51
#define en_pin5     30          //31
#define step_pin5   36          //41
#define sold_pin5   30

  //StepperMotor stepMotorA(step_pin1, rot_pin1, en_pin1, sold_pin1, but_pin1);
  StepperMotor stepMotorB(step_pin2, rot_pin2, en_pin2, sold_pin2, but_pin2);
  StepperMotor stepMotorC(step_pin3, rot_pin3, en_pin3, sold_pin3, but_pin3);
  StepperMotor stepMotorD(step_pin4, rot_pin4, en_pin4, sold_pin4, but_pin4);
  StepperMotor stepMotorE(step_pin5, rot_pin5, en_pin5, sold_pin5, but_pin5);
boolean b = false;
boolean ba = false;
boolean bb = false;
boolean bc = false;
void setup(void){

  Serial.begin(9600); 
  dbSerialPrintln("Setup Done");
pinMode(sold_pin2,OUTPUT);
pinMode(sold_pin3,OUTPUT);
pinMode(sold_pin4,OUTPUT);
pinMode(sold_pin5,OUTPUT);
}

void loop(void){

digitalWrite(sold_pin2,HIGH);
}
*/
