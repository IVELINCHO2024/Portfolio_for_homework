#include <stdio.h>
#include <stdlib.h>

#define NAME 16

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removeNewline(char *str) {
    for (int i = 0; i < NAME; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

void enterSubjects(char ***subjects, int *subjectCount) {
    do {
        printf("Въведете брой предмети: ");
        scanf("%d", subjectCount);
        clearInputBuffer();
    } while (*subjectCount <= 0);

    *subjects = (char **)malloc(*subjectCount * sizeof(char *));

    for (int i = 0; i < *subjectCount; i++) {
        (*subjects)[i] = (char *)malloc(NAME * sizeof(char));
        printf("Въведете име на предмет %d: ", i + 1);
        fgets((*subjects)[i], NAME, stdin);
        removeNewline((*subjects)[i]);
    }
}

void addStudent(char ***students, int *studentCount, int ***grades, int subjectCount) {
    *students = (char **)realloc(*students, (*studentCount + 1) * sizeof(char *));
    (*students)[*studentCount] = (char *)malloc(NAME * sizeof(char));

    printf("Въведете име на ученик: ");
    fgets((*students)[*studentCount], NAME, stdin);
    removeNewline((*students)[*studentCount]);

    *grades = (int **)realloc(*grades, (*studentCount + 1) * sizeof(int *));
    (*grades)[*studentCount] = (int *)malloc(subjectCount * sizeof(int));

    for (int i = 0; i < subjectCount; i++) {
        printf("Въведете оценка по предмет %d: ", i + 1);
        scanf("%d", &(*grades)[*studentCount][i]);
        clearInputBuffer();
    }

    (*studentCount)++;
}

void printDiary(char **students, int studentCount, char **subjects, int subjectCount, int **grades) {
    printf("\n%-15s", "");
    for (int i = 0; i < subjectCount; i++) {
        printf("%-15s", subjects[i]);
    }
    printf("\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%-15s", students[i]);
        for (int j = 0; j < subjectCount; j++) {
            printf("%-15d", grades[i][j]);
        }
        printf("\n");
    }
}

void freeMemory(char **students, int studentCount, char **subjects, int subjectCount, int **grades) {
    for (int i = 0; i < studentCount; i++) {
        free(students[i]);
    }
    free(students);

    for (int i = 0; i < subjectCount; i++) {
        free(subjects[i]);
    }
    free(subjects);

    for (int i = 0; i < studentCount; i++) {
        free(grades[i]);
    }
    free(grades);
}

int main() {
    char **subjects = NULL;
    char **students = NULL;
    int **grades = NULL;

    int studentCount = 0, subjectCount = 0;

    enterSubjects(&subjects, &subjectCount);

    int choice;
    do {
        printf("\nМеню:\n");
        printf("1. Въведи ученик\n");
        printf("2. Принтирай дневник\n");
        printf("3. Изход\n");
        printf("Изберете опция: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent(&students, &studentCount, &grades, subjectCount);
                break;
            case 2:
                printDiary(students, studentCount, subjects, subjectCount, grades);
                break;
            case 3:
                printf("Изход от програмата.\n");
                break;
            default:
                printf("Невалидна опция. Опитайте отново.\n");
        }
    } while (choice != 3);

    freeMemory(students, studentCount, subjects, subjectCount, grades);

    return 0;
}
