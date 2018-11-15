#pragma once
#include "RelaxTask.h"

void RelaxTask::setType()
    {
        this->type=new char[strlen("Relax")+1];
        strcpy(this->type,"Relax");
    }
void RelaxTask::copy(const RelaxTask& other)
    {
        this->type = new char[strlen(other.type)];
        strcpy(this->type,other.type);
        this->wayToRelax = new char[strlen(other.wayToRelax)];
        strcpy(this->wayToRelax,other.wayToRelax);
        this->location = new char[strlen(other.location)];
        strcpy(this->location,other.location);
        this->startTime=other.startTime;
        this->endTime=other.endTime;
    }
void RelaxTask::destroy()
    {
        delete[] this->wayToRelax;
        delete[] this->location;
        delete[] this->weather;
    }
RelaxTask::RelaxTask() : Task()
    {
        this->setType();
        this->wayToRelax = new char[strlen("Default")];
        strcpy(this->wayToRelax,"Default");
        this->location = new char[strlen("Default")];
        strcpy(this->location,"Default");
    }
RelaxTask::RelaxTask(const char* _wayToRelax,const char* _location,const char* _event,const char* _description,int startHour,
                 int startMinute,int endHour,int endMinute) : Task(_event,_description,startHour,startMinute,endHour,endMinute)
    {
        this->setType();
        this->wayToRelax = new char[strlen(_wayToRelax)];
        strcpy(this->wayToRelax,_wayToRelax);
        this->location = new char[strlen(_location)];
        strcpy(this->location,_location);
    }
RelaxTask::RelaxTask(const RelaxTask& other) : Task(other)
    {
        this->copy(other);
    }
RelaxTask& RelaxTask::operator=(const RelaxTask& other)
    {
        if(this!=&other)
        {
            Task::operator=(other);
            this->destroy();
            this->copy(other);
        }
        return *this;
    }
void RelaxTask::checkWeater()
    {
        this->weather = new char[strlen("\"start Firefox  https://www.sinoptik.bg/search?q={")+strlen(this->location)+3];
        strcpy(weather,"\"start Firefox  https://www.sinoptik.bg/search?q={");
        strcat(weather,this->location);
        strcat(weather,"}\"");
        system(weather);
    }
RelaxTask* RelaxTask::clone()
    {
        return new RelaxTask(*this);
    }
void RelaxTask::print()
    {
        cout<<"---------Task---------"<<endl;
        cout<<"Task type : "<<this->type<<endl;
        cout<<"Relaxing by : "<<this->wayToRelax<<endl;
        cout<<"Location : "<<this->location<<endl;
        cout<<"Event name : "<<this->event<<endl;
        cout<<"Description : "<<this->description<<endl;
        cout<<"Start time : ";
        this->startTime.print();
        cout<<"End time : ";
        this->endTime.print();
        cout<<"Event duration : "<<this->calculateDuration()<<" minutes."<<endl;
        //cout<<"---------Task---------"<<endl;
    }
RelaxTask::~RelaxTask()
    {
        this->destroy();
    }
