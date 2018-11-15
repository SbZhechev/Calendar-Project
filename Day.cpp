#pragma once
#include "Day.h"

void Day::resize()
    {
        this->capacity=this->capacity*2+1;
        Task** temp = new Task*[this->capacity];
        for(size_t i=0;i<this->size;i++)
        {
            temp[i]=this->tasks[i];
        }
        this->destroy();
        this->tasks=temp;
    }
void Day::copy(const Day& other)
    {
        for(size_t i=0;i<this->size;i++)
        {
            this->tasks[i]= other.tasks[i]->clone();
        }
    }
void Day::destroy()
    {
        for(size_t i=0;i<this->size;i++)
        {
            delete this->tasks[i];
        }
        delete[] this->tasks;
    }
Day::Day()
    {
        this->size=0;
        this->capacity=5;
        this->tasks=new Task*[this->capacity];
    }
Day::Day(const Day& other)
    {
        this->copy(other);
    }
Day& Day::operator=(const Day& other)
    {
        if(this!=&other)
        {
            this->destroy();
            this->copy(other);
        }
        return *this;
    }
Day::~Day()
    {
        this->destroy();
    }
void Day::addBusinessTask(const BusinessTask& bussiness)
    {
        if(this->size>=this->capacity)
        {
            this->resize();
        }
        this->tasks[this->size] = new BusinessTask(bussiness);
        this->size++;
    }
void Day::addStudyTask(const StudyTask& study)
    {
        if(this->size>=this->capacity)
        {
            this->resize();
        }
        this->tasks[this->size] = new StudyTask(study);
        this->size++;
    }
void Day::addRelaxTask(const RelaxTask& relax)
    {
        if(this->size>=this->capacity)
        {
            this->resize();
        }
        this->tasks[this->size] = new RelaxTask(relax);
        this->size++;
    }
void Day::removeTasks()
    {
        delete this->tasks[this->size];
        size--;
    }
void Day::printTasks()
{
    cout<<"Number of tasks on this day : "<<this->size<<endl;
    for(size_t i=0;i<this->size;i++)
    {
        this->tasks[i]->print();
    }
}
