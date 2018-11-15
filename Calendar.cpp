#include "Calendar.h"

void Calendar::copy(const Calendar& other)
    {
        for(size_t i=0;i<12;i++)
        {
            this->months[i] = other.months[i];
        }
        this->description=new char[strlen(other.description)];
        strcpy(this->description,other.description);
    }
void Calendar::destroy()
    {
        delete[] this->description;
    }
Calendar::Calendar()
    {
        for(size_t i=0;i<12;i++)
        {
            this->months[i] = new Month(i+1);
        }
        this->description=new char[strlen("Task calendar.")];
        strcpy(this->description,"Task calendar.");
    }
Calendar::Calendar(const Calendar& other)
    {
        this->copy(other);
    }
Calendar& Calendar::operator=(const Calendar& other)
    {
        if(this!=&other)
        {
            this->destroy();
            this->copy(other);
        }
        return *this;
    }
void Calendar::addBusinessTaskToDate(size_t month,size_t day,const BusinessTask& bussiness)
    {
        this->months[month-1]->getDay(day-1).addBusinessTask(bussiness);
    }
void Calendar::addStudyTaskToDate(size_t month,size_t day,const StudyTask& study)
    {
        this->months[month-1]->getDay(day-1).addStudyTask(study);
    }
void Calendar::addRelaxTaskToDate(size_t month,size_t day,const RelaxTask& relax)
    {
        this->months[month-1]->getDay(day-1).addRelaxTask(relax);
    }
void Calendar::checkTasks(size_t month, size_t day)
    {
        cout<<"                                          "<<this->description<<endl;
        this->months[month-1]->getDay(day-1).printTasks();
    }
void Calendar::removeTaskFromDate(size_t month,size_t day)
    {
        this->months[month-1]->getDay(day-1).removeTasks();
    }
void Calendar::print(size_t month)
    {
        this->months[month-1]->print();
    }
Calendar::~Calendar()
    {
        this->destroy();
    }
