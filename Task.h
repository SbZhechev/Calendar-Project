#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include "Time.h"

using namespace std;
class Task
{
private:
    void copy(const Task& other);
    void destroy();
protected:
    char* event;
    char* description;
    Time startTime;
    Time endTime;
    char* type;
    static size_t numberOfEvents;
    virtual void setType() = 0;
    virtual int calculateDuration();
public:
    Task();
    Task(const char* _event,const char* _description,int startHour,int startMinute,int endHour,int endMinute);
    Task(const Task& other);
    Task& operator=(const Task& other);
    virtual Task* clone() = 0;
    virtual void print() = 0;
    virtual ~Task();
};
