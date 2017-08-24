/* To create an Action object, a subclass of Action must be defined by the user. This is best done in separate .h/.cpp files
 * This .cpp file contains definitions of the class methods declared in the corresponding .h file
 */

//specify the header file being defined
#include "LEDoff.h"

//constructor definition. Note that the blinkTime parameter is simply used in the superclass constructor,
//meaning the user only has to supply code unique to their class
LEDoff::LEDoff(unsigned long waitTime, byte pin):Action(waitTime) {
  this->pin = pin;
}

//define what the Action should do when the waitTime is reached
void LEDoff::execute() {
  digitalWrite(pin, LOW); //in this case, simply turn the LED off
}

