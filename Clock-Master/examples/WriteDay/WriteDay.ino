#include <Clock.h>

Clock newClock(9); // Create a Clock and set the connected pin to 9

void setup() {
  newClock.SetTime(13, 59, 50); // Set the current time (Hours, Minutes, Seconds)
  newClock.SetDate(27, 4, 2021); // Set the current date (Day, Month, Year)
}

void loop() {
  newClock.GetTime(); // Get the time that was declared before
  newClock.GetDate(); // Get the date that was declared before
  newClock.WriteDay(2, 10); // Activates the before declared pin 2 times a Day (Write(*2*, 10))
  //and deactivates it after the declared Time in seconds (Write(2, *10*))
}