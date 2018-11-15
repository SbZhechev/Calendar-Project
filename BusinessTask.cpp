#include "Task.h"
#include "BusinessTask.h"

void BusinessTask::setType()
    {
        this->type = new char[strlen("Business")];
        strcpy(this->type,"Business");
    }
void BusinessTask::copy(const BusinessTask& other)
    {
        this->type = new char[strlen(other.type)];
        strcpy(this->type,other.type);
        this->location = new char[strlen(other.location)];
        strcpy(this->location,other.location);
        this->hostName = new char[strlen(other.hostName)];
        strcpy(this->hostName,other.hostName);
        this->startTime=other.startTime;
        this->endTime=other.endTime;
        this->people=other.people;
    }
void BusinessTask::destroy()
    {
        delete[] this->location;
        delete[] this->hostName;
    }
BusinessTask::BusinessTask() : Task()
    {
        this->setType();
        //this->nubmerOfEvents ++;
        this->location = new char[strlen("Default")];
        strcpy(this->location,"Default");
        this->hostName = new char[strlen("Default")];
        strcpy(hostName,"Default");
    }
BusinessTask::BusinessTask(const char* _location,const char* _hostName,const char* _event,const char* _description,int startHour,int startMinute,int endHour,int endMinute) : Task(_event,_description,startHour,startMinute,endHour,endMinute)
    {

        this->location = new char[strlen(_location)];
        strcpy(this->location,_location);
        this->hostName = new char[strlen(_hostName)];
        strcpy(this->hostName,_hostName);
        this->setType();
    }
BusinessTask::BusinessTask(const BusinessTask& other) : Task(other)
    {
        this->copy(other);
    }
BusinessTask& BusinessTask::operator=(const BusinessTask& other)
    {
        if(this != &other)
        {
            Task::operator=(other);
            this->destroy();
            this->copy(other);
        }
        return *this;
    }
void BusinessTask::setPeople(const char* _firstName,const char* _familyName)
    {
        people.pushBack(_firstName,_familyName);
    }
BusinessTask* BusinessTask::clone()
    {
        return new BusinessTask(*this);
    }
void BusinessTask::print()
    {
        cout<<"---------Task---------"<<endl;
        cout<<"Task type : "<<this->type<<endl;
        cout<<"Location : "<<this->location<<endl;
        cout<<"Host name : "<<this->hostName<<endl;
        cout<<"Event name : "<<this->event<<endl;
        cout<<"Description : "<<this->description<<endl;
        cout<<"Start time : ";
        this->startTime.print();
        cout<<"End time : ";
        this->endTime.print();
        cout<<"Event duration : "<<this->calculateDuration()<<" minutes."<<endl;
        people.print();
    }
BusinessTask::~BusinessTask()
    {
        this->destroy();
    }
