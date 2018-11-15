#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include <stdlib.h>

struct Human
{
    char* firstname;
    char* familyName;
    Human* next;
    void copy(const Human& other);
    void destroy();
    Human();
    Human(const char* _firstName,const char* _familyName,Human* _next);
    Human(const Human& other);
    Human& operator=(const Human& other);
    ~Human();
};
