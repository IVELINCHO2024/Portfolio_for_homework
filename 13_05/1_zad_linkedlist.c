#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NEW,
    IN_PROGRESS,
    COMPLETED
} TaskStatus;

typedef struct Task {
    int priority;
    char name[100];
    TaskStatus status;
    struct Task* next;
} Task;

Task* createTask(int priority, const char* name) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    newTask->priority = priority;
    strcpy(newTask->name, name);
    newTask->status = NEW;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task** head, const char* name, int priority) {
    Task* newTask = createTask(priority, name);
    if (*head == NULL || priority == 1) {
        newTask->next = *head;
        *head = newTask;
        return;
    }

    Task* current = *head;
    int currentPriority = 1;
    while (current->next != NULL && currentPriority < priority - 1) {
        current = current->next;
        currentPriority++;
    }

    newTask->next = current->next;
    current->next = newTask;
}

void changeTaskStatus(Task* head, int priority, TaskStatus newStatus) {
    Task* current = head;
    int currentPriority = 1;
    while (current != NULL && currentPriority < priority) {
        current = current->next;
        currentPriority++;
    }

    if (current != NULL) {
        current->status = newStatus;
    } else {
        printf("Uknown task\n", priority);
    }
}

void deleteTask(Task** head, int priority) {
    if (*head == NULL) {
        printf(" Empty\n");
        return;
    }

    Task* temp = *head;
    if (priority == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    Task* prev = NULL;
    int currentPriority = 1;
    while (temp != NULL && currentPriority < priority) {
        prev = temp;
        temp = temp->next;
        currentPriority++;
    }

    if (temp == NULL) {
        printf("Uknown task\n", priority);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printTasks(Task* head) {
    Task* current = head;
    while (current != NULL) {
        printf("Priority: %d, Name: %s, Status: ", current->priority, current->name);
        switch (current->status) {
            case NEW: 
             printf("New\n"); break;
            case IN_PROGRESS: 
             printf("In progress\n"); break;
            case COMPLETED: 
             printf("Completed\n"); break;
            default:
             printf("Unknown status\n");break;
        }
        current = current->next;
    }
}

int main() {
    Task* taskList = NULL;

    addTask(&taskList, "To go shopping", 1);
    addTask(&taskList, "To study", 2);
    addTask(&taskList, "To go workout", 1);

    printf("Tasks:\n");
    printTasks(taskList);

    printf("\n");
    changeTaskStatus(taskList, 2, IN_PROGRESS);
    printTasks(taskList);

    printf("\n");
    deleteTask(&taskList, 1);
    printTasks(taskList);

    return 0;
}