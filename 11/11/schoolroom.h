#ifndef SCHOOLROOM_H
#define SCHOOLROOM_H

#include "person.h"

typedef struct SchoolRoom {
    int roomNumber;        
    Person occupants[50];  
} ;

#endif
