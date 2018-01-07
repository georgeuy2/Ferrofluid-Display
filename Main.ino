/* CS179J Senior Project 
 *  Created and designed by: George Uy de Ong II
 *  
 *  Ferrofluid Display
 *  
 *  Parts: 
 *      (5)   Nema 17 stepper motors
 *      (5)   Stepper motor drivers
 *      (5)   24V solenoid
 *      (25)  Round shape neodymium magnets 
 *      (1)   Ferrofluid bottle 250ml
 *      (1)   Power Supply
 *  
*/

#include "StepperMotor.h"
#include <Nextion.h>

// Stepper Motor 1
#define but_pin1    2          //32        // Limit switch
#define rot_pin1    55        //43   // CW = clockwise and CCW = counterclockwise
#define en_pin1     38        //23        // Turn on or off motor
#define step_pin1   54        //33  // Steps
#define sold_pin1   22        // Turn on or off of solenoid

// Stepper Motor 2
#define but_pin2    19         //34    
#define rot_pin2    48          //47
#define en_pin2     62          //27
#define step_pin2   46          //37
#define sold_pin2   26

// Stepper Motor 3
#define but_pin3    18          //36
#define rot_pin3    61          //45
#define en_pin3     56          //25
#define step_pin3   60          //35
#define sold_pin3   24

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

// Stepper Motors
  StepperMotor stepMotor1(step_pin1, rot_pin1, en_pin1, sold_pin1, but_pin1);
  StepperMotor stepMotor2(step_pin2, rot_pin2, en_pin2, sold_pin2, but_pin2);
  StepperMotor stepMotor3(step_pin3, rot_pin3, en_pin3, sold_pin3, but_pin3);
  StepperMotor stepMotor4(step_pin4, rot_pin4, en_pin4, sold_pin4, but_pin4);
  StepperMotor stepMotor5(step_pin5, rot_pin5, en_pin5, sold_pin5, but_pin5);

// Cell Buttons
  NexButton b0 = NexButton(0, 1, "b0");
  NexButton b1 = NexButton(0, 2, "b1");
  NexButton b2 = NexButton(0, 3, "b2");
  NexButton b3 = NexButton(0, 4, "b3");
  NexButton b4 = NexButton(0, 5, "b4");

  NexButton b5 = NexButton(0, 6, "b5");
  NexButton b6 = NexButton(0, 7, "b6");
  NexButton b7 = NexButton(0, 8, "b7");
  NexButton b8 = NexButton(0, 9, "b8");
  NexButton b9 = NexButton(0, 10, "b9");

  NexButton b10 = NexButton(0, 11, "b10");
  NexButton b11 = NexButton(0, 12, "b11");
  NexButton b12 = NexButton(0, 13, "b12");
  NexButton b13 = NexButton(0, 14, "b13");
  NexButton b14 = NexButton(0, 15, "b14");

  NexButton b15 = NexButton(0, 16, "b15");
  NexButton b16 = NexButton(0, 17, "b16");
  NexButton b17 = NexButton(0, 18, "b17");
  NexButton b18 = NexButton(0, 19, "b18");
  NexButton b19 = NexButton(0, 20, "b19");

  NexButton b20 = NexButton(0, 21, "b20");
  NexButton b21 = NexButton(0, 22, "b21");
  NexButton b22 = NexButton(0, 23, "b22");
  NexButton b23 = NexButton(0, 24, "b23");
  NexButton b24 = NexButton(0, 25, "b24");
  
  NexButton b25 = NexButton(0, 26, "b25"); // Draw button

// Cell booealns
  boolean c[25];

 void setAllCellsToFalse(){
  for(byte i = 0; i<25; i++){
    c[i] = false;
  }
}
// 
  NexTouch *nex_listen_list[] = 
  {
    &b0,  &b1,  &b2,  &b3,  &b4, 
    &b5,  &b6,  &b7,  &b8,  &b9, 
    &b10, &b11, &b12, &b13, &b14, 
    &b15, &b16, &b17, &b18, &b19,
    &b20, &b21, &b22, &b23, &b24,  
    &b25,
    NULL
  };
  
 void b0ButtonPress( void *ptr ){
  c[0] = !c[0];
  Serial.println(c[0]);
}

 void b1ButtonPress( void *ptr ){
  c[1] = !c[1];
  Serial.println(c[1]);
}

 void b2ButtonPress( void *ptr ){
  c[2] = !c[2];
  Serial.println(c[2]);
}

 void b3ButtonPress( void *ptr ){
  c[3] = !c[3];
  Serial.println(c[3]);
}

 void b4ButtonPress( void *ptr ){
  c[4] = !c[4];
  Serial.println(c[4]);
}

 void b5ButtonPress( void *ptr ){
  c[5] = !c[5];
  Serial.println(c[5]);
}

 void b6ButtonPress( void *ptr ){
  c[6] = !c[6];
  Serial.println(c[6]);
}

 void b7ButtonPress( void *ptr ){
  c[7] = !c[7];
  Serial.println(c[7]);
}

 void b8ButtonPress( void *ptr ){
  c[8] = !c[8];
  Serial.println(c[8]);
}

 void b9ButtonPress( void *ptr ){
  c[9] = !c[9];
  Serial.println(c[9]);
}

 void b10ButtonPress( void *ptr ){
  c[10] = !c[10];
  Serial.println(c[10]);
}

 void b11ButtonPress( void *ptr ){
  c[11] = !c[11];
  Serial.println(c[11]);
}

 void b12ButtonPress( void *ptr ){
  c[12] = !c[12];
  Serial.println(c[12]);
}

 void b13ButtonPress( void *ptr ){
  c[13] = !c[13];
  Serial.println(c[13]);
}

 void b14ButtonPress( void *ptr ){
  c[14] = !c[14];
  Serial.println(c[14]);
}

 void b15ButtonPress( void *ptr ){
  c[15] = !c[15];
  Serial.println(c[15]);
}

 void b16ButtonPress( void *ptr ){
  c[16] = !c[16];
  Serial.println(c[16]);
}

 void b17ButtonPress( void *ptr ){
  c[17] = !c[17];
  Serial.println(c[17]);
}

 void b18ButtonPress( void *ptr ){
  c[18] = !c[18];
  Serial.println(c[18]);
}

 void b19ButtonPress( void *ptr ){
  c[19] = !c[19];
  Serial.println(c[19]);
}

 void b20ButtonPress( void *ptr ){
  c[20] = !c[20];
  Serial.println(c[20]);
}

 void b21ButtonPress( void *ptr ){
  c[21] = !c[21];
  Serial.println(c[21]);
}

 void b22ButtonPress( void *ptr ){
  c[22] = !c[22];
  Serial.println(c[22]);
}

 void b23ButtonPress( void *ptr ){
  c[23] = !c[23];
  Serial.println(c[23]);
}

 void b24ButtonPress( void *ptr ){
  c[24] = !c[24];
  Serial.println(c[24]);
}
boolean drawButtonState;

void  drawButtonPress( void *ptr){
  drawButtonState = true;
  bottomToTopOrder();
  stepMotor1.setCells(  c[0],   c[1],   c[2],   c[3],   c[4]  );
//  for(int i = 0; i<5; i++){
//    Serial.print(c[i]);
//    Serial.print(" ,");
//  }
//  Serial.println();
  stepMotor2.setCells(  c[5],   c[6],   c[7],   c[8],   c[9]  );
  stepMotor3.setCells(  c[10],  c[11],  c[12],  c[13],  c[14] );
  stepMotor4.setCells(  c[15],  c[16],  c[17],  c[18],  c[19] );
  stepMotor5.setCells(  c[20],  c[21],  c[22],  c[23],  c[24] );
  Serial.println("Draw button Pressed");
}

void bottomToTopOrder(){
  int MAX_HEIGHT = 0;
    for(int i=4; i>0; i--){
    // Serial.println(i+1);
      if(isAnyElementOfRowTrue(i) == true){
        Serial.println(i);
        MAX_HEIGHT = i;
        break;
      }
    }
/*
    for( int j = 0; j < MAX_HEIGHT; j++){
      
    }
*/
}

/* x is the Row starting from 0 to 5. Since I am using a 5X4
 *  
 */
boolean isAnyElementOfRowTrue(int x){
  boolean row = false;  
  int i = 0;
  int endOfArray = 0;
  if(x == 4){
    i = 5;
    endOfArray = 10;
  }
  else if( x ==3){
    i = 10;
    endOfArray = 14;
  }
    else if( x ==2){
    i = 15;
    endOfArray = 20;
  }
    else if( x ==1){
    i = 20;
    endOfArray = 25;
  }
  else{
    Serial.println("Error getting true row");
  }
  for( ; i<endOfArray; i++){
    if( c[i] == true){
      row = true;
      Serial.print(i);
      Serial.print(" ");
      break;
    } 
  }
  return row;
}

void initAllButtons(){
  b0.attachPush(b0ButtonPress);
  b1.attachPush(b1ButtonPress);
  b2.attachPush(b2ButtonPress);
  b3.attachPush(b3ButtonPress);
  b4.attachPush(b4ButtonPress);
  
  b5.attachPush(b5ButtonPress);
  b6.attachPush(b6ButtonPress);
  b7.attachPush(b7ButtonPress);
  b8.attachPush(b8ButtonPress);
  b9.attachPush(b9ButtonPress);
  
  b10.attachPush(b10ButtonPress);
  b11.attachPush(b11ButtonPress);
  b12.attachPush(b12ButtonPress);
  b13.attachPush(b13ButtonPress);
  b14.attachPush(b14ButtonPress);
  
  b15.attachPush(b15ButtonPress);
  b16.attachPush(b16ButtonPress);
  b17.attachPush(b17ButtonPress);
  b18.attachPush(b18ButtonPress);
  b19.attachPush(b19ButtonPress);
  
  b20.attachPush(b20ButtonPress);
  b21.attachPush(b21ButtonPress);
  b22.attachPush(b22ButtonPress);
  b23.attachPush(b23ButtonPress);
  b24.attachPush(b24ButtonPress);
  
  b25.attachPush(drawButtonPress);
}

// Variables
  int input;
  boolean receivedInput;
  boolean allMotorsAtOrigin;
 
  
// State
  enum State{ Start_State, Wait_State, Move_State} state;

// Setup
void setup(){
  nexInit();
  Serial.begin(9600);
  receivedInput = false;
  input = 0;
  allMotorsAtOrigin = false;
  drawButtonState = false;
  setAllCellsToFalse();
  initAllButtons();
  state = Start_State;
  dbSerialPrintln("Setup Done");
}


void allMotorsGoToOrigin(){
//   if( !(stepMotor1.isAtOrigin()) ){
//        stepMotor1.gotoOrigin();
//      }
   if( !(stepMotor2.isAtOrigin()) ){
        stepMotor2.gotoOrigin();
      }
   if( !(stepMotor3.isAtOrigin()) ){
        stepMotor3.gotoOrigin();
      }
//   if( !(stepMotor4.isAtOrigin()) ){
//        stepMotor4.gotoOrigin();
//      }
   if( !(stepMotor5.isAtOrigin()) ){
        stepMotor5.gotoOrigin();
      }
//   if( stepMotor1.isAtOrigin() && stepMotor2.isAtOrigin() && stepMotor3.isAtOrigin() && stepMotor4.isAtOrigin() && stepMotor5.isAtOrigin() ){
//    allMotorsAtOrigin = true;
//   }
   if (stepMotor2.isAtOrigin() == true && stepMotor3.isAtOrigin() ==true &&  stepMotor5.isAtOrigin() == true){
    allMotorsAtOrigin = true;
   }          
}

boolean isAnyOfTheMotorsDone(){
  boolean motorsDone;
     
 //  if( stepMotor1.isDone() == true && stepMotor2.isDone() == true && stepMotor3.isDone() == true && stepMotor4.isDone() == true && stepMotor5.isDone() == true){
//    if( stepMotor4.isDone() == true){
//    Serial.println("true");
//   }
//   else{
//    Serial.println("false");
//   }
   if(stepMotor2.isDone() == true && stepMotor3.isDone() == true &&  stepMotor5.isDone() == true){
    motorsDone = true;
   }
   else{
    motorsDone = false;     
   }
   return motorsDone;
}

boolean isAnyOfTheMotorsMoving(){
  boolean motorsMoving;
     
//   if( stepMotor1.isMoving() || stepMotor2.isMoving() || stepMotor3.isMoving() || stepMotor4.isMoving() || stepMotor5.isMoving() ){

   if( stepMotor2.isMoving() == true || stepMotor3.isMoving() == true   || stepMotor5.isMoving() == true ){
    motorsMoving = true;
   }
   else{
    motorsMoving = false;     
   }
   return motorsMoving;
}


boolean isAllMotorsAtOrigin(){
  return allMotorsAtOrigin;
}

void setAllMotorsAtOrigin(boolean b){
  allMotorsAtOrigin = b;
}


int ferroFluidDisplay(int state){
  
  switch(state){
    case Start_State:
    //Serial.println("@ Start State");
      if( !isAllMotorsAtOrigin() ){
        allMotorsGoToOrigin();
      }
      else{
        state = Wait_State;
        //input = 0; // make sure no user put any input before goign to wait state
      }
    break;

    case Wait_State:
      //Serial.println("@ Wait State");    
        if(drawButtonState == false){
          state = Wait_State;
        }
        else if( (drawButtonState == true) && !isAnyOfTheMotorsMoving() && isAllMotorsAtOrigin()){
         // Serial.println("@ 2 State");
          state = Move_State;
          setAllMotorsAtOrigin(false);
          stepMotor2.restartCellStateMachine();
          stepMotor3.restartCellStateMachine();
        //  stepMotor4.restartCellStateMachine();
          stepMotor5.restartCellStateMachine();
        }
    break;

    case Move_State:
   // Serial.println("@ Move");
        if( (drawButtonState == true) && !isAllMotorsAtOrigin()){
          state = Move_State;
        //  Serial.println("@go");
//          stepMotor1.goToCellsStateMachine();
          stepMotor2.goToCellsStateMachine();
          stepMotor3.goToCellsStateMachine();
       //   stepMotor4.goToCellsStateMachine();
          stepMotor5.goToCellsStateMachine();
          // if stepper finishes going to all cells then set receiveInputState = false 
          if(isAnyOfTheMotorsDone() == true){
           Serial.println("@@@@@@@@@@@@@@@@@@@@@@@@");
            drawButtonState = false; 
          }
        }
        else if( (drawButtonState == false) && isAnyOfTheMotorsDone() && !isAllMotorsAtOrigin()){
          state = Start_State;
          Serial.println("-----------------------");
        }
    break;

    default:
      state = Start_State;
     break;
  }
  //Serial.println(state);

  return state;
}

void loop(){
  nexLoop(nex_listen_list);
  state = ferroFluidDisplay(state);
}


