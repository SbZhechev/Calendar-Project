#pragma once
#include "Day.h"
class Month
{
private:
    Day* days;
    size_t numberOfDays;
    void copy(const Month& other);
    void destroy();
public:
    Month();
    Month(size_t number);
    Month(const Month& other);
    Month& operator=(const Month& other);
    Day& getDay(size_t day) const;
    size_t getNumberOfDays() const;
    void print();
    ~Month();
};
