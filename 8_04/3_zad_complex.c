#include <stdio.h>
#include <stdlib.h>


struct student{
    char name[15];
    int number;
    double average_grade;
};

void add_student(struct student **students, int *count){
    *count = *count + 1;
    *students = realloc(*students, sizeof(struct student) * (*count)); 
    if (*students == NULL) {
        printf("Error\n");
        exit(0);
    }
    scanf("%s", (*students)[*count - 1].name);
    scanf("%d", &(*students)[*count - 1].number);
    scanf("%lf", &(*students)[*count - 1].average_grade);
}

void print_students(struct student *students, int count){
    for (int i = 0; i < count; i++){
        printf("-------------------------------------------------\n");
        printf("Name: %s\n", students[i].name);
        printf("Number: %d\n", students[i].number);
        printf("Average grade: %.2lf\n", students[i].average_grade);
    }
}


int main(){
    struct student *students = NULL;
    int count = 0;
    while(1){
        printf("Menu:\n");
        printf("1. Add student\n");
        printf("2. Show students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: add_student(&students, &count);
            break;
        case 2: print_students(students, count);
            break;
        case 3:
            free(students);
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}