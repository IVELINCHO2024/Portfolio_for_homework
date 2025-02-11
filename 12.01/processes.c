#include "processes.h"
#include <stdio.h>
#include <string.h>

Process processes[MAX_PROCESSES];
int processcount = 0;
static int next_id = 1;

static int nextprocessid() {
    if (next_id > 0) {
        return next_id++;
    }
    return 0;
}

int createnewprocess(const char* name) {
    if (processcount >= MAX_PROCESSES) {
        return 0;
    }

    int id = nextprocessid();
    if (id == 0) {
        return 0;
    }

    processes[processcount].id = id;
    strncpy(processes[processcount].name, name, MAX_NAME_LENGTH);
    processes[processcount].name[MAX_NAME_LENGTH - 1] = '\0';
    processcount++;
    return id;
}

void stopprocess(int id) {
    for (int i = 0; i < processcount; ++i) {
        if (processes[i].id == id) {
            for (int j = i; j < processcount - 1; ++j) {
                processes[j] = processes[j + 1];
            }
            processcount--;
            return;
        }
    }
}

void listprocesses() {
    if (processcount == 0) {
        printf("No processes are running.\n");
        return;
    }

    for (int i = 0; i < processcount; ++i) {
        printf("ID: %d, Name: %s\n", processes[i].id, processes[i].name);
    }
}
