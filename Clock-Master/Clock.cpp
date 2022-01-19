#include "Arduino.h"
#include "Clock.h"

Clock::Clock(int pin)
{
  int Sec;
  int Min;
  int Hour;
  double HowHour;

  int Day;
  int Month;
  int Year;
  int LeapYear;
  double HowOften;

  bool TMonth; // stands for 30 day month or 31 day month
  // if it's true that means it is a 31 day month

  int delayTime;
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  _pin = pin;
  _Sec = Sec;
  _Min = Min;
  _Hour = Hour;
  _HowHour = HowHour;

  _Day = Day;
  _Month = Month;
  _Year = Year;
  _LeapYear = LeapYear;
  _HowOften = HowOften;

  _TMonth = TMonth;
  
  _delayTime = delayTime;
}

void Clock::SetTime(int Hours, int Minutes, int Seconds)
{
  _Sec = Seconds;
  _Min = Minutes;
  _Hour = Hours;
}

void Clock::SetDate(int Days, int Months, int Years)
{
  _Day = Days;
  _Month = Months;
  _Year = Years;
}

void Clock::GetTime()
{
  _Sec += 1;
  delay(1000);
  Serial.println("Time: " + String(_Hour) + ":" + String(_Min) + ":" + String(_Sec));

  if (_Sec == 60)
  {
    _Min += 1;
    _Sec = 0;
  }

  if (_Min == 60)
  {
    _Hour += 1;
    _Min = 0;
  }

  if (_Hour == 24)
  {
    _Day += 1;
    _Hour = 0;
  }
}

void Clock::GetDate()
{
  Serial.println("Date: " + String(_Day) + "." + String(_Month) + "." + String(_Year));
  if (_Day == 30 && _TMonth == false)
  {
    _Month += 1;
    _Day = 0;
    _TMonth = true;
  }
  
  if (_Day == 31 && _TMonth == true)
  {
    _Month += 1;
    _Day = 0;
    _TMonth = false;
  }

  if (_LeapYear != 4 && _Month == 2 && _Day == 28)
  {
    _Month += 1;
    _Day = 0;
  }

  if (_Month == 12)
  {
    _Year += 1;
    _Month = 0;
  }

  if (_LeapYear == 4)
  {
    _Day += 1;
    _LeapYear = 0;
    if (_Month == 2 && _Day == 29)
    {
      _Month += 1;
      _Day = 0;
    }
  }
}

void Clock::WriteTime(int AtHour, int AtMin, int AtSec, int DelayTime)
{
  if (_Hour == AtHour && _Min == AtMin && _Sec == AtSec)
  {
    digitalWrite(_pin, HIGH);
  }

  if (_Hour == AtHour && _Min == AtMin && _Sec == DelayTime)
  {
    digitalWrite(_pin, LOW);
  }
}

void Clock::WriteDay(int AtDay, int DelayDate)
{
  _HowHour = 24 / AtDay;

  if (AtDay > 24)
    {
      Serial.println(String(AtDay) + " is higher than 24 but the maximum is 24");
      AtDay = 24;
    }

    if (AtDay < 1)
    {
      Serial.println(String(AtDay) + " is lower than 1 but the minimum is 1");
      AtDay = 1;
    }
  for (int H = 0; H < 24; H += _HowHour)
      {
        double WeekArray[AtDay] = {H};

        if (_Hour == H && _Sec == 0)
        {
          digitalWrite(_pin, HIGH);
        }

        if (_Hour == H && _Sec == DelayDate)
        {
          digitalWrite(_pin, LOW);
        }
      }
}

void Clock::Write(int Often, int DelayLong)
{
  if (_TMonth == false)
  {
    _HowOften = 30 / Often;

    if (Often > 30)
    {
      Serial.println(String(Often) + " is higher than 30 but the maximum is 30");
      Often = 30;
    }

    if (Often < 1)
    {
      Serial.println(String(Often) + " is lower than 1 but the minimum is 1");
      Often = 1;
    }

    for (int i = 0; i < 31; i += _HowOften)
      {
        double OftenArray[Often] = {i};

        if (_Day == i && _Sec == 0)
        {
          digitalWrite(_pin, HIGH);
        }

        if (_Day == i && _Sec == DelayLong)
        {
          digitalWrite(_pin, LOW);
        }
      }

  }

  if (_TMonth == true)
  {
    _HowOften = 31 / Often;

    if (Often > 31)
    {
      Serial.println(String(Often) + " is higher than 30 but the maximum is 30");
    }

    if (Often < 0)
    {
      Serial.println(String(Often) + " is lower than 0 but the minimum is 0");
    }

    for (int j = 0; j < 32; j += _HowOften)
      {
        double OftenArrayTM[Often] = {j};

        if (_Day == j && _Sec == 0)
        {
          digitalWrite(_pin, HIGH);
        }

        if (_Day == j && _Sec == DelayLong)
        {
          digitalWrite(_pin, LOW);
        }
      }
  }
  
}