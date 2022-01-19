#include <Clock.h>

Clock newClock(9); // create a Clock and connect declare the pin to 9

void setup() {
  newClock.SetTime(23, 59, 50); // Set the current time (Hours, Minutes, Seconds)
  newClock.SetDate(1, 4, 2021); // Set the current date (Day, Month, Year)
}

void loop() {
  newClock.GetTime(); // Get the time that was declared before
  newClock.GetDate(); // Get the date that was declared before
  newClock.Write(10, 10); // Writes the declared pin HIGH 10 times a month (Write(*10*, 10))
  //and LOW after the declared Time in seconds (Write(10, *10*))
}
