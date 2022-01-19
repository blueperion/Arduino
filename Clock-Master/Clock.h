#ifndef Clock_h
#define Clock_h

#include "Arduino.h"
class Clock
{
  public:
    Clock(int pin);
    void SetTime(int Hours, int Minutes, int Seconds);
    void SetDate(int Days, int Months, int Years);
    void GetTime();
    void GetDate();
    void WriteTime(int AtHour, int AtMin, int AtSec, int DelayTime);
    void WriteDay(int AtDay, int DelayDate);
    void Write(int Often, int DelayLong);
  private:

    int _Sec;
    int _Min;
    int _Hour;
    double _HowHour;

    int _Day;
    int _Month;
    int _Year;
    int _LeapYear;
    double _HowOften;

    bool _TMonth;

    int _pin;
    int _delayTime = 10000;
};

#endif