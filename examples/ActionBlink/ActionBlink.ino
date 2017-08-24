/* Sample code to replicate the effects of the Blink example sketch using the Action class
 */

//include the new Action subclass written for this sketch
#include "LEDBlink.h"

//create an instance of that class
LEDBlink ledBlink = LEDBlink(1000, LED_BUILTIN);

void setup() {
  //led pin should be set as an output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //instead of using delay() or constantly checking millis(), let the object figure out when it's time to blink
  ledBlink.check();
}
