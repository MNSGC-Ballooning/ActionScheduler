/* Sample code to drive an LED that turns on when a button is pressed, and turns off 1 second after the button is released
 * Requires a push button between GND and D2. (Alternately, a wire could be connected and disconnected between the pins.)
 */

//include the new Action subclass written for this sketch
#include "LEDoff.h"
//include the Scheduler, a class for handling checking actions and removing them once completed
#include <Scheduler.h>

//pin to which push button should be conected
#define buttonPin 2

bool buttonPressed = false; //tracks whether button has been pressed
Scheduler scheduler;        //create instance of Scheduler

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     //LED pin should be set as output
  pinMode(buttonPin, INPUT_PULLUP); //buttonn pin will be an input that defaults to HIGH unless connected to ground
}

void loop() {
  //when button is first pressed...
  if (!buttonPressed && digitalRead(buttonPin) == LOW) {
    scheduler.clear();                //...remove any previously scheduled actions so that the LED doesn't turn off early
    digitalWrite(LED_BUILTIN, HIGH);  //immediately set the LED to HIGH
    buttonPressed = true;             //record that the button has been pressed
  }
  //when button is first released...
  if (buttonPressed && digitalRead(buttonPin) == HIGH) {
    scheduler.schedule(new LEDoff(1000, LED_BUILTIN));  //...schedule the LED to turn off in 1000ms (1 second)
    buttonPressed = false;                              //record that the button has been released
  }
  scheduler.checkActions(); //check to see if the scheduled action should occur and turn the LED off.
}
