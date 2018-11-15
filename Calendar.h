#pragma once
#include "Month.h"

class Calendar
{
private:
    Month* months[12];
    char* description;
    void copy(const Calendar& other);
    void destroy();
public:
    Calendar();
    Calendar(const Calendar& other);
    Calendar& operator=(const Calendar& other);
    void addBusinessTaskToDate(size_t month,size_t day,const BusinessTask& bussiness);
    void addStudyTaskToDate(size_t month,size_t day,const StudyTask& study);
    void addRelaxTaskToDate(size_t month,size_t day,const RelaxTask& relax);
    void removeTaskFromDate(size_t month,size_t day);
    void checkTasks(size_t month, size_t day);
    void print(size_t month);
    ~Calendar();
};
