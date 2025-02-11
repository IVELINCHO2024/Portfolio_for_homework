#include <stdio.h>
#include "schoolclass.h"
#include "schoolroom.h"

typedef struct School {
    SchoolClass classes[20]; 
    SchoolRoom rooms[10];    
} ;

int main() {
    School school; 

    
    printf(" %lu класа ; %lu стаи.\n", 
           sizeof(school.classes) / sizeof(school.classes[0]), 
           sizeof(school.rooms) / sizeof(school.rooms[0]));

    return 0;
}
