#include <stdio.h>
#include <stdint.h> 
#include <string.h> 

int main() {
    uint8_t state = 0; 
    char input[10];    
    int room;

    printf("Smart Home\n");
    printf("Enter 'on (room) to turn on the light, 'off (room)' to turn off the light, 'status' to check the status of the lights, or 'exit' you exit.\n");

    while (1) {
        printf("\nEnter: ");
        scanf("%s", input); 

        if (strcmp(input, "on") == 0) { 
            scanf("%d", &room); 

            if (room >= 1 && room <= 8) {
                state |= (1 << (room - 1)); 
                printf("Turn on the light in the room %d.\n", room);
            } else {
                printf("Not a valid number\n");
            }
        } else if (strcmp(input, "off") == 0) { 
            scanf("%d", &room); 

            if (room >= 1 && room <= 8) {
                state &= ~(1 << (room - 1)); 
                printf("Turned off light in the room %d.\n", room);
            } else {
                printf("Not a valid number.\n");
            }
        } else if (strcmp(input, "status") == 0) {
            printf("THe lights are turned on: ");
            for (int i = 0; i < 8; i++) {
                if (state & (1 << i)) { 
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
        } else if (strcmp(input, "exit") == 0) {
            printf("bye bye\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}