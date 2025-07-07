#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char name[101];
    int sub_count;
    struct Employee **subordinates; 
} Employee;

Employee* create_employee(const char* name, int sub_count) {
    Employee* emp = malloc(sizeof(Employee));
    strncpy(emp->name, name, 100);
    emp->name[100] = '\0';
    emp->sub_count = sub_count;
    if (sub_count > 0) {
        emp->subordinates = malloc(sub_count * sizeof(Employee*));
    } else {
        emp->subordinates = NULL;
    }
    return emp;
}


void serialize_employee(FILE* file, Employee* emp) {
    int name_len = strlen(emp->name);
    fwrite(&name_len, sizeof(int), 1, file);
    fwrite(emp->name, sizeof(char), name_len, file);
    fwrite(&emp->sub_count, sizeof(int), 1, file);
    for (int i = 0; i < emp->sub_count; i++) {
        serialize_employee(file, emp->subordinates[i]);
    }
}

void free_employee(Employee* emp) {
    for (int i = 0; i < emp->sub_count; i++) {
        free_employee(emp->subordinates[i]);
    }
    free(emp->subordinates);
    free(emp);
}


Employee* create_example_hierarchy() {
    Employee* w1 = create_employee("Worker 1", 0);
    Employee* w2 = create_employee("Worker 2", 0);
    Employee* w3 = create_employee("Worker 3", 0);
    Employee* manager1 = create_employee("Manager 1", 3);
    manager1->subordinates[0] = w1;
    manager1->subordinates[1] = w2;
    manager1->subordinates[2] = w3;

    Employee* w4 = create_employee("Worker 4", 0);
    Employee* w5 = create_employee("Worker 5", 0);
    Employee* w6 = create_employee("Worker 6", 0);
    Employee* manager2 = create_employee("Manager 2", 3);
    manager2->subordinates[0] = w4;
    manager2->subordinates[1] = w5;
    manager2->subordinates[2] = w6;

    Employee* director = create_employee("Director", 2);
    director->subordinates[0] = manager1;
    director->subordinates[1] = manager2;

    return director;
}

int main() {
    Employee* director = create_example_hierarchy();
    FILE* file = fopen("employees.bin", "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    serialize_employee(file, director);
    fclose(file);
    free_employee(director);
}