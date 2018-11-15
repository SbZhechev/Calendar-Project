#pragma once
#include "StudyTask.h"

void StudyTask::copy(const StudyTask& other)
    {
        this->type = new char[strlen(other.type)];
        strcpy(this->type,other.type);
        this->subjectName = new char[strlen(other.subjectName)];
        strcpy(this->subjectName,other.subjectName);
        this->material=new char[strlen(other.material)];
        strcpy(this->material,other.material);
        this->startTime=other.startTime;
        this->endTime=other.endTime;
    }
void StudyTask::setType()
    {
        this->type = new char[strlen("Study")];
        strcpy(this->type,"Study");
    }
void StudyTask::destroy()
    {
        delete[] this->subjectName;
        delete[] this->material;
    }
StudyTask::StudyTask () : Task ()
    {
        this->setType();
        this->subjectName = new char[strlen("Default")];
        strcpy(this->subjectName,"Default");
        this->material=new char[strlen("Default")];
        strcpy(this->material,"Default");
    }
StudyTask::StudyTask(const char* _subjectName,const char* material,const char* _event,const char* _description,int startHour,int startMinute,int endHour,int endMinute) : Task(_event,_description,startHour,startMinute,endHour,endMinute)
    {
        this->setType();
        this->subjectName = new char[strlen(_subjectName)];
        strcpy(this->subjectName,_subjectName);
        this->material=new char[strlen(material)];
        strcpy(this->material,material);
    }
StudyTask::StudyTask(const StudyTask& other) : Task(other)
    {
        this->copy(other);
    }
StudyTask& StudyTask::operator=(const StudyTask& other)
    {
        if(this!=&other)
        {
            Task::operator=(other);
            this->destroy();
            this->copy(other);
        }
        return *this;
    }
StudyTask* StudyTask::clone()
    {
        return new StudyTask(*this);
    }
void StudyTask::print()
    {
        cout<<"---------Task---------"<<endl;
        cout<<"Task type : "<<this->type<<endl;
        cout<<"Subject : "<<this->subjectName<<endl;
        cout<<"Material : "<<this->material<<endl;
        cout<<"Event name : "<<this->event<<endl;
        cout<<"Description : "<<this->description<<endl;
        cout<<"Start time : ";
        this->startTime.print();
        cout<<"End time : ";
        this->endTime.print();
        cout<<"Event duration : "<<this->calculateDuration()<<" minutes."<<endl;
        //cout<<"---------Task---------"<<endl;
    }
StudyTask::~StudyTask()
    {
        this->destroy();
    }
