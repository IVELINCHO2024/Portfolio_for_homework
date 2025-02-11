#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include "person.h"

typedef struct SchoolClass {
    Person students[26]; 
    char classLetter;    
    int classNumber;     
    Person classTeacher; 
};

#endif 
