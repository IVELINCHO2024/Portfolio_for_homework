
#include<stdio.h>

#define COMMAND(NAME, TYPE) TYPE##_##NAME##_command



// Дефинираме две функции с помощта на DEFINE_COMMAND
void internal_quit_command() {
    printf("internal quit command.\n");
}

void external_start_command() {
    printf(" external start command.\n");
}

int main() {
    
    COMMAND(quit, internal)();
    COMMAND(start, external)();
    
    return 0;
}
