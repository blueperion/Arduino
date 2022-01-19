#include <Clock.h>

Clock newClock(9); // create a Clock and connect declare the pin to 9

void setup() {
  newClock.SetTime(14, 0, 0); // Set the current time (Hours, Minutes, Seconds)
  newClock.SetDate(27, 4, 2021); // Set the current date (Day, Month, Year)
}

void loop() {
  newClock.GetTime(); // Get the time that was declared before
  newClock.GetDate(); // Get the date that was declared before
  newClock.WriteTime(0, 0, 5); // Activates the declared pin at 00:00 (12AM) and 5 seconds
  //because it uses european digital time and deactivates it after the declared delayTime
}
