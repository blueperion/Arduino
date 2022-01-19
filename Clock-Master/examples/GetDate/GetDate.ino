#include <Clock.h>

Clock newClock(9); // create a Clock

void setup() {
  newClock.SetDate(27, 4, 2021); // Before getting the date you first have to 
  //set the date (Day, Month, Year)
}

void loop() {
  newClock.GetDate(); // Now you can get the date
}
