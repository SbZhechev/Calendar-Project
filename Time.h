#pragma once
#include <iostream>

using namespace std;
class Time
{
private:
    int hour;
    int minute;
public:
    Time ();
    Time& operator-(const Time& other);
    const int getHour() const;
    const int getMinute() const;
    void setTime(size_t _hour,size_t _minute);
    void print();
};
