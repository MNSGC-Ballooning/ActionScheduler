/* To create an Action object, a subclass of Action must be defined by the user. This is best done in separate .h/.cpp files
 * This .h file declares what variables and functions the subclass containts. These are then defined separately in the .cpp file
 */

//include guards (needed in all header files)
#ifndef LEDoff_h
#define LEDoff_h

//since turning the LED off is a one-time event, simply make a subclass of Action
#include <Action.h>

//actual class declaration
class LEDoff: public Action {
  public:
    //constructor
    LEDoff(unsigned long waitTime, byte pin);
  private:
    byte pin;       //the pin of the LED to blink
    void execute(); //every Action subclass needs their own definition of execute(), called after the specified number of millis
};

#endif
