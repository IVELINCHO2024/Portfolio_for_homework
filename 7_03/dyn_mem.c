#include <stdio.h>
#include <stdlib.h>

#define ERROR_EXIT(msg) printf(msg); \
exit(1);\

void printMenu() {
    printf("\nОпции:\n");
    printf("1 - Извеждане на средния успех\n");
    printf("2 - Добавяне на нова оценка\n");
    printf("3 - Изтриване на последната оценка\n");
    printf("4 - Изход\n");
    printf("Изберете опция: ");
}

double calculateAverage(int *grades, int count) {
    if (count == 0) {
        printf("Няма налични оценки.\n");
        return 0.0;
    }
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return (double)sum / count;
}

int main() {
    int *grades = NULL;
    int count = 0;

    printf("Въведете броя на съществуващите оценки: ");
    while (scanf("%d", &count) != 1 || count < 0) {
        printf("Грешен вход. Въведете неотрицателно число: ");
        while (getchar() != '\n'); 
    }

    if (count > 0) {
        grades = (int *)malloc(count * sizeof(int));
        if (grades == NULL) {
            ERROR_EXIT("Грешка при заделянето на памет!\n");
        }

        printf("Въведете %d оценки: ", count);
        for (int i = 0; i < count; i++) {
            while (scanf("%d", &grades[i]) != 1) {
                printf("Грешен вход. Въведете цяло число: ");
                while (getchar() != '\n'); 
            }
        }
    }

    int choice;
    do {
        printMenu();
        while (scanf("%d", &choice) != 1) {
            printf("Грешен вход. Въведете число: ");
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1:
                printf("Среден успех: %.2f\n", calculateAverage(grades, count));
                break;
            case 2: {
                int newGrade;
                printf("Въведете новата оценка: ");
                while (scanf("%d", &newGrade) != 1) {
                    printf("Грешен вход. Въведете цяло число: ");
                    while (getchar() != '\n');
                }

                int *temp = (int *)realloc(grades, (count + 1) * sizeof(int));
                if (temp == NULL) {
                    ERROR_EXIT("Грешка при разширяване на паметта\n");
                }
                grades = temp;
                grades[count++] = newGrade;
                printf("Успешно добавена оценка\n");
                break;
            }
            case 3:
                if (count > 0) {
                    int *temp = (int *)realloc(grades, (count - 1) * sizeof(int));
                    if (temp != NULL || count - 1 == 0) {
                        grades = temp;
                        count--;
                        printf("Последната оценка е изтрита\n");
                    }
                } else {
                    printf("Няма оценки за изтриване\n");
                }
                break;
            case 4:
                free(grades);
                break;
            default:
                printf("Невалидна опция. Опитайте отново.\n");
        }
    } while (choice != 4);

    return 0;
}
