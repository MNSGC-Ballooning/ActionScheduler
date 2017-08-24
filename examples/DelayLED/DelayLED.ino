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
LEDoff myLEDoff = LEDoff(0, LED_BUILTIN); //create variable and assign temporary dummy object

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     //LED pin should be set as output
  pinMode(buttonPin, INPUT_PULLUP); //buttonn pin will be an input that defaults to HIGH unless connected to ground
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { //button is pressed
    if (!buttonPressed) { //button was just pressed, rather than held down
      buttonPressed = true; //save button state
      digitalWrite(LED_BUILTIN, HIGH);  //turn on LED
    }
  }
  else {  //buton is not pressed
    if (buttonPressed) {  //button was just released
      buttonPressed = false;  //save button state
      myLEDoff = LEDoff(1000, LED_BUILTIN);  //schedule LED to turn off in 1000ms (1 second)
    }
    myLEDoff.check(); //only attempt to turn off if button is not currently pressed
  }
}