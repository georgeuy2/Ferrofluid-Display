#ifndef StepperMotor_h
#define StepperMotor_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define CW 0
#define CCW 1


class StepperMotor {
  public:
    // Constructor
    StepperMotor(byte step_pin, byte rot_pin, byte en_pin, byte sld_pin, byte but_pin, boolean dir = CCW);

    // Datatypes
    
    
    // Methods
    
    // Stops the stepper motor for s seconds
    void pauseSM(int s);
    
    // Turns on stepper motor
    void turnOnSM();

    // Turns off stepper motor
    void turnOffSM();

    // Stepper moves
    void runSM();

    // Stepper goes to the cell from cell 1 to cell 5. (MAX 5 CELLS!)    
    void goToCellsStateMachine();

    // Set CW or CCW
    void setDirection(boolean dir);
    
    // Goes to starting point
    void gotoOrigin();

    // set if stepper is in the origin
    void setOriginState(boolean state);

    // Set the stepper motor which cell to go. Go to the cell if it is true else false
    void setCells(boolean cellOne, boolean cellTwo, boolean cellThree, boolean cellFour, boolean cellFive);
    
   
    void restartCellStateMachine();
   
    
    boolean isAtOrigin();
    boolean isMoving();
    boolean isDone();
    
  private:
    // Data types
    enum CellSM{ Start_State, Cell1_State, Cell2_State, Cell3_State, Cell4_State, Cell5_State, Pause_State, SolenoidOn_State, Delay_State, SolenoidOff_State, Stop_State} CellState;
    enum RunSM{ StartR_State, On_State, Delay1_State, Off_State, Delay2_State} RunState;
    
    // This can vary. Ideal range is about 50000-55000
    const unsigned long WIDTH_NUM = 50000;
    
    const unsigned long CELL_FIVE = WIDTH_NUM;
    const unsigned long CELL_FOUR = (CELL_FIVE/5)*4;
    const unsigned long CELL_THREE = (CELL_FIVE/5)*3;
    const unsigned long CELL_TWO = (CELL_FIVE/5)*2;
    const unsigned long CELL_ONE = (CELL_FIVE/5);
    const unsigned long CELL_ZERO = 0;
    
    // Set max counter to avoid overflow
    const unsigned long MAX_COUNTER = 500000;

    const unsigned int RUN_DELAY_TIME = 0.5;
    const unsigned int DELAY_TIME = 2000;

    // Pins
    byte step_pin;
    byte rot_pin;
    byte en_pin;
    byte but_pin;
    byte sold_pin;
    
    boolean dir;
    boolean buttonState;
    boolean originState;
    boolean moveState;
    boolean counterState;
    boolean bCellOne;
    boolean bCellTwo;
    boolean bCellThree;
    boolean bCellFour;
    boolean bCellFive;
    boolean reachCurrCell;
    boolean pause;
    boolean done;
    int seconds;
    unsigned long counter;
    int motorState;
    int pauseState;
    unsigned long previousMillis;
    unsigned long prevDelayMillis;
    unsigned long prevRunMillis;

    // Methods
    void startTimer();
    void resetCounter();
    void moveToCell();
    void counterPause();
    void goToCells();
    int RunSM(int state);
    void solenoidOn(byte port);
    void solenoidOff(byte port);
    
};

#endif
