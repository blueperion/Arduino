#include <Clock.h>

Clock newClock(9); // create a Clock

void setup() {
  newClock.SetTime(14, 0, 0); // Before getting the time you first have to 
  //set the time (Hours, Minutes, Seconds)
}

void loop() {
  newClock.GetTime(); // Now you can get the time
}
