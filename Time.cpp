#pragma once
#include "Time.h"

Time::Time ()
    {
        hour=0;
        minute=0;
    }
Time& Time::operator-(const Time& other)
    {
        this->hour-=other.hour;
        this->minute-=other.minute;
        return *this;
    }
const int Time::getHour() const
    {
        return this->hour;
    }
const int Time::getMinute() const
    {
        return this->minute;
    }
void Time::setTime(size_t _hour,size_t _minute)
    {

        this->hour=_hour;
        this->minute=_minute;
    }
void Time::print()
    {
        cout<<this->hour<<":"<<this->minute<<endl;
    }
