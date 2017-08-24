/* To create an Action object, a subclass of Action must be defined by the user. This is best done in separate .h/.cpp files
 * This .cpp file contains definitions of the class methods declared in the corresponding .h file
 */

 //specify the header file being defined
#include "LEDBlink.h"

//constructor definition. Note that the blinkTime parameter is simply used in the superclass constructor,
//meaning the user only has to supply code unique to their class
LEDBlink::LEDBlink(unsigned long blinkTime, byte pin):RepeatingAction(blinkTime) {
  this->pin = pin;
}

//define what the Action should do when the blinkTime is reached
void LEDBlink::execute() {
  if (ledOn) digitalWrite(pin, LOW);  //if the LED is on, turn it off
  else digitalWrite(pin, HIGH);       //if it's off, turn it on
  ledOn = !ledOn;                     //record the change
}

