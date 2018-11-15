#pragma once
#include "Month.h"

void Month::copy(const Month& other)
    {
        this->days=new Day[other.numberOfDays];
        this->numberOfDays=other.numberOfDays;
    }
void Month::destroy()
    {
        delete[] this->days;
    }
Month::Month()
    {
        this->numberOfDays=0;
        this->days=new Day[this->numberOfDays];
    }
Month::Month(size_t number)
    {

        switch(number)
        {
            case 1 : this->numberOfDays=31; break;
            case 2 : this->numberOfDays=28; break;
            case 3 : this->numberOfDays=31; break;
            case 4 : this->numberOfDays=30; break;
            case 5 : this->numberOfDays=31; break;
            case 6 : this->numberOfDays=30; break;
            case 7 : this->numberOfDays=31; break;
            case 8 : this->numberOfDays=31; break;
            case 9 : this->numberOfDays=30; break;
            case 10 : this->numberOfDays=31; break;
            case 11 : this->numberOfDays=30; break;
            case 12 : this->numberOfDays=31; break;
            default :
            cout << "Invalid input" << endl;
        }
        this->days = new Day[this->numberOfDays];
    }
Month::Month(const Month& other)
    {
        this->copy(other);
    }
Month::~Month()
    {
    delete[] this->days;
    }
Month& Month::operator=(const Month& other)
    {
        if(this!=&other)
        {
            this->destroy();
            this->copy(other);
        }
        return *this;
    }
Day& Month::getDay(size_t day) const
    {
        return this->days[day];
    }
void Month::print()
    {
        cout<<this->numberOfDays<<endl;
    }
