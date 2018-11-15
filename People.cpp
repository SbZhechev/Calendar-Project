#pragma once
#include "People.h"

using namespace std;

void People::copy(const People& other)
    {
        Human* temp = other.first;
        for(size_t i = 0 ;i < other.size; i++)
        {
            pushBack(temp->firstname,temp->familyName);
            temp = temp->next;
        }
        this->size=other.size;
    }
void People::destroy()
    {
        while(this->size>0)
        {
            this->popFront();
        }
    }
People::People()
    {
        this->first=nullptr;
        this->last=nullptr;
        this->size=0;
    }
People::People(const People& other)
    {
        this->copy(other);
    }
People& People::operator=(const People& other)
    {
        if(this!=&other)
        {
            this->destroy();
            this->copy(other);
        }
        return *this;
    }
void People::pushBack(const char* _firstName,const char* _familyName)
    {
        Human* temp = new Human(_firstName,_familyName,nullptr);
         if(temp)
        {
            if(this->size==0)
            {
                this->first=temp;
                this->last=temp;
            }
            else
            {
                this->last->next=temp;
                this->last=temp;
            }
            this->size++;
        }
    }
bool People::isEmpty()
    {
        return this->size==0;
    }
void People::popFront()
    {
        if(!this->isEmpty())
        {
            Human* temp =this->first;
            this->first=this->first->next;
            if(this->size == 1)
            {
                this->first=nullptr;
                this->last=nullptr;

            }
            delete temp;
            this->size--;
        }
        else cout<<"The list is already empty!"<<endl;
    }
People::~People()
    {
        this->destroy();
    }
void People::print()
    {
        cout<<"Number of people on the event : "<<this->size<<endl;
        Human* temp=this->first;
        for(size_t i=0;i<this->size;i++)
        {
            cout<<"Person "<<i+1<<": "<<temp->firstname<<" "<<temp->familyName<<endl;
            temp=temp->next;
        }
    }
