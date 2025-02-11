#include "processes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showmenu() {
    printf("\nTask Manager\n");
    printf("1. Create Process\n");
    printf("2. List Processes\n");
    printf("3. Stop Process\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int id;

    while (1) {
        showmenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process name: ");
                scanf("%s", name);
                id = createnewprocess(name);
                if (id == 0) {
                    printf("Error: Maximum number of processes reached.\n");
                } else {
                    printf("Process created with ID: %d\n", id);
                }
                break;
            case 2:
                listprocesses();
                break;
            case 3:
                printf("Enter process ID to stop: ");
                scanf("%d", &id);
                stopprocess(id);
                break;
            case 4:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid option.Try again.\n");
        }
    }
    return 0;
}
