#pragma once
#include "Task.h"

class StudyTask : public Task
{
private:
    char* subjectName;
    char* material;
    void copy(const StudyTask& other);
    void setType();
    void destroy();
public:
    StudyTask ();
    StudyTask(const char* _subjectName,const char* material,const char* _event,const char* _description,int startHour,
              int startMinute,int endHour,int endMinute);
    StudyTask(const StudyTask& other);
    StudyTask& operator=(const StudyTask& other);
    StudyTask* clone();
    void print();
    ~StudyTask();
};
