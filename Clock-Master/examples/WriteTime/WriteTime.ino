#include <Clock.h>

Clock newClock(9); // create a Clock and connect declare the pin to 9

void setup() {
  newClock.SetTime(14, 0, 0); // Set the current time (Hours, Minutes, Seconds)
  newClock.SetDate(27, 4, 2021); // Set the current date (Day, Month, Year)
}

void loop() {
  newClock.GetTime(); // Get the time that was declared before
  newClock.GetDate(); // Get the date that was declared before
  newClock.WriteTime(0, 0, 5); // Writes the declared pin HIGH at 00:00 and 5 seconds and LOW after the declared delayTime
}
