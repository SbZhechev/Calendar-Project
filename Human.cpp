#pragma once
#include "Human.h"

void Human::copy(const Human& other)
    {
        this->firstname=new char[strlen(other.firstname)];
        strcpy(this->firstname,other.firstname);
        this->familyName=new char[strlen(other.familyName)];
        strcpy(this->familyName,other.familyName);
        this->next=other.next;
    }
void Human::destroy()
    {
        delete this->firstname;
        delete this->familyName;
    }
Human::Human()
    {
        this->firstname=new char[strlen("Default")];
        strcpy(this->firstname,"Default");
        this->familyName=new char[strlen("Default")];
        strcpy(this->familyName,"Default");
        this->next=nullptr;
    }
Human::Human(const char* _firstName,const char* _familyName,Human* _next)
    {
        this->firstname=new char[strlen(_firstName)];
        strcpy(this->firstname,_firstName);
        this->familyName=new char[strlen(_familyName)];
        strcpy(this->familyName,_familyName);
        this->next=_next;
    }
Human::Human(const Human& other)
    {
        this->copy(other);
    }
Human& Human::operator=(const Human& other)
    {
        if(this!=&other)
        {
            this->destroy();
            this->copy(other);
        }
        return *this;
    }
Human::~Human()
    {
        this->destroy();
    }
