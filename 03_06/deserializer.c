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

Employee* deserialize_employee(FILE* file) {
    int name_len;
    if (fread(&name_len, sizeof(int), 1, file) != 1) return NULL;
    char name[101];
    if (fread(name, sizeof(char), name_len, file) != (size_t)name_len) return NULL;
    name[name_len] = '\0';
    int sub_count;
    if (fread(&sub_count, sizeof(int), 1, file) != 1) return NULL;
    Employee* emp = create_employee(name, sub_count);
    for (int i = 0; i < sub_count; i++) {
        emp->subordinates[i] = deserialize_employee(file);
    }
    return emp;
}

void print_employee(Employee* emp, int indent) {
    for (int i = 0; i < indent; i++) printf("    ");
    printf("%s\n", emp->name);
    for (int i = 0; i < emp->sub_count; i++) {
        print_employee(emp->subordinates[i], indent + 1);
    }
}

void free_employee(Employee* emp) {
    for (int i = 0; i < emp->sub_count; i++) {
        free_employee(emp->subordinates[i]);
    }
    free(emp->subordinates);
    free(emp);
}

int main() {
    FILE* file = fopen("employees.bin", "rb");
    if (!file) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    Employee* root = deserialize_employee(file);
    fclose(file);

    printf("Employee hierarchy:\n");
    print_employee(root, 0);
    free_employee(root);

    return 0;
}