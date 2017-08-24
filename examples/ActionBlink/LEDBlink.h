/* To create an Action object, a subclass of Action must be defined by the user. This is best done in separate .h/.cpp files
 * This .h file declares what variables and functions the subclass containts. These are then defined separately in the .cpp file
 */

//include guards (needed in all header files)
#ifndef LEDBlink_h
#define LEDBlink_h

//since the LED should blink infinitely, make a subclass of RepeatingAction
#include <RepeatingAction.h>

//actual class declaration
class LEDBlink: public RepeatingAction {
  public:
    //constructor
    LEDBlink(unsigned long blinkTime, byte pin);
  private:
    byte pin; //the pin of the LED to blink
    bool ledOn = false; //keeps track of current LED state; initially off
    void execute(); //every Action subclass needs their own definition of execute(), called after the specified number of millis
};

#endif
