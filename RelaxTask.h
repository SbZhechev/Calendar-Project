#pragma once
#include "Task.h"

class RelaxTask : public Task
{
private:
    char* wayToRelax;
    char* location;
    char* weather;
    void setType();
    void copy(const RelaxTask& other);
    void destroy();
public:
    RelaxTask ();
    RelaxTask(const char* _wayToRelax,const char* _location,const char* _event,const char* _description,int startHour,
              int startMinute,int endHour,int endMinute);
    RelaxTask(const RelaxTask& other);
    RelaxTask& operator=(const RelaxTask& other);
    void checkWeater();
    RelaxTask* clone();
    void print();
    ~RelaxTask();

};
