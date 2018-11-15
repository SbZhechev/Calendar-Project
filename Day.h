#pragma once
#include "Task.h"
#include "BusinessTask.h"
#include "StudyTask.h"
#include "RelaxTask.h"

class Day
{
private:
    Task** tasks;
    size_t size,capacity;
    void copy(const Day& other);
    void resize();
    void destroy();
public:
    Day();
    Day(const Day& other);
    Day& operator=(const Day& other); // ---> to finish
    ~Day();
    void printTasks();
    void addBusinessTask(const BusinessTask& bussiness);
    void addStudyTask(const StudyTask& study);
    void addRelaxTask(const RelaxTask& relax);
    void removeTasks();
};
