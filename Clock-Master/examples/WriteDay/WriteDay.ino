#include <Clock.h>

Clock newClock(9); // create a Clock and connect declare the pin to 9

void setup() {
  newClock.SetTime(13, 59, 50); // Set the current time (Hours, Minutes, Seconds)
  newClock.SetDate(27, 4, 2021); // Set the current date (Day, Month, Year)
}

void loop() {
  newClock.GetTime(); // Get the time that was declared before
  newClock.GetDate(); // Get the date that was declared before
  newClock.WriteDay(2, 10); // Writes the declared pin HIGH 2 times a Day (Write(*2*, 10))
  //and LOW after the declared Time in seconds (Write(2, *10*))
}
