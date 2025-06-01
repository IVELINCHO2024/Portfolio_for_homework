#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum priority{
    SPECIAL,
    NORMAL
}Priority;

typedef struct patient{
    char name[100];
    Priority priority;
    struct patient* next;
}Patient;

typedef struct patientlist{
    Patient* head;
    int size;
}PatientList;

PatientList innit(){
    PatientList list = {
        .head = NULL,
        .size = 0 
    };

    return list;
}

Patient* createPatient(char* name, Priority priority){
    Patient* newPatient = malloc(sizeof(Patient));
    if(newPatient == NULL){
        exit(1);
    }
    strcpy(newPatient->name, name);
    newPatient->priority = priority;

    return newPatient;
}

void SpecialPatientAdd(PatientList* list, char* name, Priority priority){
   Patient* newPatient = createPatient(name, priority);
   newPatient->next = list->head;
   list->head = newPatient;
   list->size++;

}

Patient* getIndex(PatientList* list, int index){
    Patient* CurrentPatient = list->head;
    for(int i = 0; i<index; i++){
        CurrentPatient = CurrentPatient->next; 
    }

    return CurrentPatient;

}

void NormalPatientAdd(PatientList* list, char* name, Priority priority){
    Patient* newPatient = createPatient(name, priority);
    if(list->head == NULL){
        list->head = newPatient;
    }
    else{
     Patient* lastPatient = getIndex(list, list->size-1);
     lastPatient->next = newPatient;
     
    }
    list->size++;
}

void PrintPatients(PatientList* list){
    Patient* currentPatient = list->head;
    printf("Patient list:\n");
    while(currentPatient != NULL){
        printf("Name: %s, Priority: ", currentPatient->name);
        switch(currentPatient->priority){
            case SPECIAL: printf("SPECIAL");break;
            case NORMAL: printf("NORMAL");break;
            default: printf("Uknown");break;
        }
        currentPatient = currentPatient->next;
    }
}


void release(PatientList* list){
Patient* current = list->head;
while (current != NULL) {
    Patient* temp = current;
    current = current->next;
    free(temp);
}
}

int main(){
    PatientList list = innit();
    
    char name[100] = "Sebastion";
    SpecialPatientAdd(&list, &name, SPECIAL);
    PrintPatients(&list);
    release(&list);
    return 0;
}