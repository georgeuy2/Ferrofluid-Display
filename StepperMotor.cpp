#include "StepperMotor.h"

/*
 *  Created by: George Uy de Ong II
 *  StepperMotor( step, direction, enable, solenoid, limit switch, default direction = counterclockwise)
 *  Look at StepperMotor.H for information of each function. 
 */
StepperMotor::StepperMotor(byte s_pin, byte r_pin, byte e_pin, byte sld_pin, byte b_pin, boolean d = CCW){
  step_pin = s_pin;
  rot_pin = r_pin;
  en_pin = e_pin;
  but_pin = b_pin;
  sold_pin = sld_pin;
  
  originState = false;
  moveState = false;
  buttonState = false;
  counterState = false;
  reachCurrCell = false;
  pause = false;
  motorState = LOW;
  pauseState = LOW;
  setDirection(d);
  done = true;

  CellState = Start_State;
  RunState = StartR_State;
  prevDelayMillis = 0;
  previousMillis = 0;
  prevRunMillis = 0;
  counter = 0;
  seconds = 0;
  pinMode(step_pin, OUTPUT);
  pinMode(rot_pin, OUTPUT);
  pinMode(en_pin, OUTPUT);
  pinMode(sold_pin, OUTPUT);
  pinMode(but_pin, INPUT);
 
}

boolean StepperMotor::isDone(){
    return done;
}

void StepperMotor::resetCounter(){
  counter = 0;
}

void StepperMotor::solenoidOn(byte port){
  if(port == 30){
    PORTC |= (1<<7);
  }
  else if(port == 28){
    PORTA |= (1<<6);
  }
  else{
    Serial.println("PORT ERROR");
  }
  //digitalWrite(sold_pin, HIGH);
}

void StepperMotor::solenoidOff(byte port){
  if(port == 30){
    PORTC &= ~(1<<7);
  }
  else if(port == 28){
    PORTA &= ~(1<<6);
  }
  else{
    Serial.println("PORT ERROR");
  }
}

void StepperMotor::setCells(boolean cellOne, boolean cellTwo, boolean cellThree, boolean cellFour, boolean cellFive){
  bCellOne = cellOne;
  bCellTwo = cellTwo;
  bCellThree = cellThree;
  bCellFour = cellFour;
  bCellFive = cellFive;
  counterState = true;
}

void StepperMotor::counterPause(){
  counterState = false;
}

void StepperMotor::moveToCell(){
  if(counter < MAX_COUNTER && counterState == true){
      counter++;
    }
    setDirection(CW);
    runSM();   
}
void StepperMotor::restartCellStateMachine(){
  CellState = Start_State;
}


void StepperMotor::goToCellsStateMachine(){
unsigned long currDelayMillis = 0;

  switch(CellState){
    case Start_State:
      Serial.println("@ Start cell");
      CellState = Cell1_State;
      setOriginState(false);
      done = false;  
    break;
    
    case Cell1_State:
     // Serial.println("@ cell 1");
      if ( bCellOne && !reachCurrCell){
        if(counter <= CELL_ONE) {
          moveToCell();
        }
        else{
          reachCurrCell = true;
        }
        CellState = Cell1_State;
      }
      else if(!bCellOne && !reachCurrCell){
        CellState = Cell2_State;
      }
      if( bCellOne && reachCurrCell){
        CellState = Pause_State;
      }    
    break;
    
    case Cell2_State:
    //Serial.println("@ cell 2");
      if ( bCellTwo && !reachCurrCell){
        if(counter <= CELL_TWO) {
          moveToCell();
        }
        else{
          reachCurrCell = true;
        }
        CellState = Cell2_State;
      }
      else if(!bCellTwo && !reachCurrCell){
        CellState = Cell3_State;
      }
      if( bCellTwo && reachCurrCell){
        CellState = Pause_State;
      }
    break;
    
    case Cell3_State:
    //Serial.println("@ cell 3");
      if ( bCellThree && !reachCurrCell){
        if(counter <= CELL_THREE) {
          moveToCell();
        }
        else{
          reachCurrCell = true;
        }
        CellState = Cell3_State;
      }
      else if(!bCellThree && !reachCurrCell){
        CellState = Cell4_State;
      }
      if( bCellThree && reachCurrCell){
        CellState = Pause_State;
      }
    break;
    
    case Cell4_State:
    //Serial.println("@ cell 4");
      if ( bCellFour && !reachCurrCell){
        if(counter <= CELL_FOUR) {
          moveToCell();
        }
        else{
          reachCurrCell = true;
        }
        CellState = Cell4_State;
      }
      else if(!bCellFour && !reachCurrCell){
        CellState = Cell5_State;
      }
      if( bCellFour && reachCurrCell){
        CellState = Pause_State;
      }
    break;
    
    case Cell5_State:
   // Serial.println("@ cell 5");
      if ( bCellFive && !reachCurrCell){
        if(counter <= CELL_FIVE) {
          moveToCell();
        }
        else{
          reachCurrCell = true;
        }
        CellState = Cell5_State;
      }
      else if(!bCellFive && !reachCurrCell){
        CellState = Stop_State;
      }
      if( bCellFive && reachCurrCell){
        CellState = Pause_State;
      }
    break;
    
    case Pause_State:
    Serial.println(counter);
      turnOffSM();
      counterPause();
      CellState = SolenoidOn_State;
    break;
    
    case SolenoidOn_State:
      //Turn On Solenoid
      //solenoidOn(sold_pin);
      CellState = Delay_State;
      // Start  2 timer 
      prevDelayMillis = millis();
    break;
    
    case Delay_State:
      currDelayMillis = millis();
      if( currDelayMillis - prevDelayMillis > DELAY_TIME){
        //digitalWrite(sold_pin,LOW);
        CellState = SolenoidOff_State;
      }
      else {
        CellState = Delay_State;
      }
    break;
    
    case SolenoidOff_State:
      // Turn off solenoid
      //solenoidOff(sold_pin);
     
      //  Serial.println("@ Soleniod off state");
      reachCurrCell = false;
      counterState = true;
//      if(bCellOne == false && bCellTwo == false &&  bCellThree == false && bCellFour == false && bCellFive == false){
//          CellState = Stop_State;
//      }
      if(bCellOne == false && bCellTwo == false &&  bCellThree == false && bCellFour == false && bCellFive == true){
       //   Serial.println("@ done");
          bCellFive = false;
          CellState = Stop_State;
          done = true;
      }
      else if (bCellOne == false && bCellTwo == false &&  bCellThree == false && bCellFour == true  ){ //&& bCellFive == false
          bCellFour = false;
          CellState = Cell5_State;
      }
      else if (bCellOne == false && bCellTwo == false &&  bCellThree == true ){//&& bCellFour == false && bCellFive == false
          bCellThree = false;
          CellState = Cell4_State;
      }
      else if(bCellOne == false && bCellTwo == true ){ //&&  bCellThree == false && bCellFour == false && bCellFive == false
          bCellTwo = false;
          CellState = Cell3_State;
      }
      else if(bCellOne == true){
          bCellOne = false;
          CellState = Cell2_State;
      }      
    break;
    
    case Stop_State:
        CellState = Stop_State;
        counterState = false;
        resetCounter();
        turnOffSM();
        done = true;
    break;

    default: 
      CellState = Start_State;
    break;
    
  }
}

void StepperMotor::goToCells(){
  // If any of the parameters are true it will go to that cell.
  // Starting from first cell to the last.
  //struct boolCell bCellInstance;
  
  if(bCellOne == false && bCellTwo == false &&  bCellThree == false && bCellFour == false && bCellFive == false){
    counterState = false;
    resetCounter();
    turnOffSM();
  }
  else if(bCellOne == false && bCellTwo == false &&  bCellThree == false && bCellFour == false && bCellFive == true){

    if(!pause) {
      if(counter<CELL_FIVE && counterState == true){
        moveToCell();
      }
      else if(counter >=CELL_FIVE){
        pause = true;
        prevDelayMillis = millis();
      }
    } 
    if(pause) {
      if(counter >= CELL_FIVE){ 
        pauseSM(5);
        // trigger solenoid
        //solenoid.trigger();
      } 
    } 
    else {
      bCellFive = false;
    }
  }
  else if (bCellOne == false && bCellTwo == false &&  bCellThree == false && bCellFour == true  ){ //&& bCellFive == false
    if(counter >= CELL_FOUR){
      bCellFour = false;
      pauseSM(5);
      // trigger solenoid
    }  
  }
  else if (bCellOne == false && bCellTwo == false &&  bCellThree == true ){//&& bCellFour == false && bCellFive == false
    if(counter >= CELL_THREE){
      bCellThree = false;
      // trigger solenoid
      pauseSM(5);
    }    
  }
  else if(bCellOne == false && bCellTwo == true ){ //&&  bCellThree == false && bCellFour == false && bCellFive == false
    if(counter >= CELL_TWO){
      bCellTwo = false;
      // trigger solenoid
      pauseSM(5);
    }
  }
  else if(bCellOne == true){ //
    if(counter >= CELL_ONE){
      bCellOne = false;
      //triggerSolenoid();
      
      pauseSM(5);
    }
  }

}


void StepperMotor::gotoOrigin(){
  buttonState = digitalRead(but_pin);
   
   if(buttonState == LOW){
      setDirection(CCW);
      turnOnSM();
      runSM();
      setOriginState(false);
      if(counter < MAX_COUNTER){
        counter++;
      }
   } 
   else{
       Serial.println("button press");

    turnOffSM();
    setDirection(CW);
    setOriginState(true); 
    Serial.println(counter);
    resetCounter();
   }
}

boolean StepperMotor::isAtOrigin(){
  return originState;
}

boolean StepperMotor::isMoving(){
  return moveState;
}

void StepperMotor::setOriginState(boolean state){
  originState = state;
}



void StepperMotor::pauseSM(int sec){
    sec = sec*1000;  
//    turnOffSM();
//    delay(sec);
//    turnOnSM();
  unsigned long currentPauseMillis = millis();
  if( currentPauseMillis - prevDelayMillis > sec){ 
    prevDelayMillis = currentPauseMillis;
    pause = false;
  }
  else {
    turnOffSM();
  }
}

void StepperMotor::setDirection(boolean dir){
  if(dir == CW){
    digitalWrite(rot_pin, LOW);
  }
  else if(dir == CCW){
    digitalWrite(rot_pin, HIGH);
  }
}

int StepperMotor::RunSM(int state){
  turnOnSM();
  unsigned long currRunMillis = 0;

  switch(state){
    case StartR_State:
      state = On_State;
    break;
    
    case On_State:
      digitalWrite(step_pin, HIGH);
      prevRunMillis = millis();
      state = Delay1_State;
    break;
    
    case Delay1_State:
      currRunMillis = millis();
      if(currRunMillis - prevRunMillis > RUN_DELAY_TIME){
        state = Off_State;
      }
      else{
        state = Delay1_State;
      }
    break;
    
    case Off_State:
      digitalWrite(step_pin, LOW);
      prevRunMillis = millis();
      state = Delay2_State;
    break;
    
    case Delay2_State:
      currRunMillis = millis();
      if(currRunMillis - prevRunMillis > RUN_DELAY_TIME){
        state = On_State;
      }
      else{
        state = Delay2_State;
      }
    break;

    default:
      state = StartR_State;
    break;
  }
}
void StepperMotor::runSM(){
  turnOnSM();
  unsigned long currentMillis = millis();
  if( currentMillis - previousMillis > RUN_DELAY_TIME){
    previousMillis = currentMillis;
    
    if (motorState == LOW)
      motorState = HIGH;
    else
      motorState = LOW;
    digitalWrite(step_pin, motorState);
  }
  
}


void StepperMotor::turnOnSM(){
  digitalWrite(en_pin,LOW);
  moveState = true;
}

void StepperMotor::turnOffSM(){
  digitalWrite(en_pin,HIGH);
  moveState = false;
}

