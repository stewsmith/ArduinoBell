#include <TimeAlarms.h>
#include <Time.h>
#include <TimeLib.h>
#include <Stepper.h>

//---( Number of steps per revolution of INTERNAL motor in 4-step mode )---
#define STEPS_PER_MOTOR_REVOLUTION 32   

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  

//The pin connections need to be 4 pins connected
// to Motor Driver In1, In2, In3, In4  and then the pins entered
// here in the sequence 1-3-2-4 for proper sequencing
Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);

int Steps2Take;

void setup()
{
  Repeats();
  Alarm.timerRepeat(3600, Repeats);  
}

void Repeats() {
  Steps2Take  =  STEPS_PER_OUTPUT_REVOLUTION ;  // Rotate CW 1 turn
  small_stepper.setSpeed(700);   
  small_stepper.step(Steps2Take);
}

void loop()
{
  // delay required in loop per library
  Alarm.delay(1);
}
