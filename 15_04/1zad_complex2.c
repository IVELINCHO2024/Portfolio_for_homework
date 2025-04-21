#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct time{
    int hour;
    int minute;
} Time;

typedef struct participant{
    char firstName[30];
    char secondName[30];
    char lastName[30];
    char email[50];
    char telephone[50];
} Participant;

typedef struct answer{
    bool will_participate;
    Participant participant;

} Answer;

typedef struct cause{
    char headline[100];
    char description[1000];
    struct {
        int day;
        int month;
        int year;
        Time time;
    } Data;
    Answer answers[100];
} Cause;

void print_participants(Cause causes){
    printf("Participant: \n");
    printf("  First Name: %s\n", causes.answers[0].participant.firstName);
    printf("  Second name: %s\n", causes.answers[0].participant.secondName);
    printf("  Last name: %s\n", causes.answers[0].participant.lastName);
    printf("  Email: %s\n", causes.answers[0].participant.email);
    printf("  Tel: %s\n", causes.answers[0].participant.telephone);
    if(causes.answers->will_participate == true){
        printf("  Will the person participate: Yes\n");
    }
    else{
        printf("  Will the person participate: No\n");
    }

}

void print_causes(Cause causes){
    printf("--------------------------------------\n");
    printf("Headline: %s\n", causes.headline);
    printf("Description: %s\n", causes.description);
    printf("Day: %d\n", causes.Data.day);
    printf("Month: %d\n", causes.Data.month);
    printf("Year: %d\n", causes.Data.year);
    printf("Time: %d : %d\n\n", causes.Data.time.hour, causes.Data.time.minute);
    printf("Answers:\n");
    print_participants(causes);


}

int main(void){
    Cause causes[2];

    causes[0] =(Cause){
        .headline = "Giving to the poor",
        .description = "We are collecting money for the poor people in our city.",
        .Data = {
            .day = 15,
            .month = 11,
            .year = 2025,
            .time = {
                .hour = 10,
                .minute = 30
            }
        },
        .answers = {
            [0] = {
               .will_participate = true,
               .participant = {
                    .email = "something@gmail.com",
                    .firstName = "Ivan",
                    .secondName = "Petrov",
                    .lastName = "Ivanov",
                    .telephone = "0888888888"
               }
            }
        }
    };
    print_causes(causes[0]);

    printf("------------------------------------------------\n\n");

    causes[1] =(Cause){
        .headline = "Cleaning the city",
        .description = "We are collecting garbage in the city.",

        .Data = {
            .day = 11,
            .month = 12,
            .year = 2025,
            .time = {
                .hour = 9,
                .minute = 30
            }
        },
        .answers = {
            [0] = {
                .will_participate = true,
                .participant = {
                    .email = "random@gmail.com",
                    .firstName = "Maria",
                    .secondName = "Petrova",
                    .lastName = "Ivanova",
                    .telephone = "00008888888"
                }
            }
        }

    };

    print_causes(causes[1]);

    return 0;
}