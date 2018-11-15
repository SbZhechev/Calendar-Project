#pragma once
#include "Task.h"
#include "People.h"

class BusinessTask : public Task
{
private:
    char* location;
    People people;
    char* hostName;
    void setType();
    void copy(const BusinessTask& other);
    void destroy();
public:
    BusinessTask ();
    BusinessTask(const char* _location,const char* _hostName,const char* _event,const char* _description,int startHour,
                 int startMinute,int endHour,int endMinute);
    BusinessTask(const BusinessTask& other);
    BusinessTask& operator=(const BusinessTask& other);
    BusinessTask* clone();
    void setPeople(const char* _firstName,const char* _familyName);
    void print();
    ~BusinessTask();
};
