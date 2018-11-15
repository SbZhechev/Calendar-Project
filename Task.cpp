#pragma once
#include "Task.h"

size_t Task::numberOfEvents = 0;
void Task::copy(const Task& other)
    {
        this->event=new char[strlen(other.event)];
        strcpy(this->event,other.event);
        this->description = new char[strlen(other.description)];
        strcpy(this->description,other.description);
    }
void Task::destroy()
    {
        delete[] this->event;
        delete[] this->description;
        delete[] this->type;
    }
int Task::calculateDuration()
    {
        Time duration = this->endTime-this->startTime;
        return abs(duration.getHour())*60+abs(duration.getMinute());
    }
Task::Task()
    {
       this->numberOfEvents++;
       this->event = new char[strlen("Default")];
       strcpy(this->event,"Default");
       this->description = new char[strlen("Default")];
       strcpy(this->description,"Default");
    }
Task::Task(const char* _event,const char* _description,int startHour,int startMinute,int endHour,int endMinute)
    {
        if(startHour < 0 || startMinute < 0 || endHour < 0 || endMinute < 0)
        {
            cout<<"There is no  negative time"<<endl;
        }
        else
        {
            this->startTime.setTime(startHour,startMinute);
            this->endTime.setTime(endHour,endMinute);
            this->event = new char[strlen(_event)];
            strcpy(this->event,_event);
            this->description = new char[strlen(_description)];
            strcpy(this->description,_description);
        }
    }
Task::Task(const Task& other)
    {
        this->copy(other);
    }
Task& Task::operator=(const Task& other)
    {
        if(this!=&other)
        {
            this->destroy();
            this->copy(other);
        }
        return *this;
    }
Task::~Task()
    {
        this->numberOfEvents--;
        this->destroy();
    }
