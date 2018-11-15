#pragma once
#include "Human.h"

using namespace std;

class People
{
private:
    Human* first;
    Human* last;
    size_t size;
    void copy(const People& other);
    void destroy();
public:
    People();
    People(const People& other);
    People& operator=(const People& other);
    void pushBack(const char* _firstName,const char* _familyName);
    bool isEmpty();
    void popFront();
    ~People();
    void print();
};
