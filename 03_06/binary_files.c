#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    NO_EDUCATION,
    PRIMARY,
    SECONDARY,
    HIGHER
} Education;

typedef enum {
    UNEMPLOYED,
    EMPLOYED
} Work_status;

typedef enum {
    SINGLE,
    MARRIED
} Marital_status;

typedef struct {
    char EGN[11];
    char name[255];
    Education education;
    Work_status work_status;
    Marital_status marital_status;
    int age;
} Person;


Person input_person() {
    Person p;
    printf("Enter EGN (10 digits): ");
    scanf("%10s", p.EGN);
    getchar();
    printf("Enter full name: ");
    fgets(p.name, 254, stdin);
    char *newline = strchr(p.name, '\n');
    if (newline) *newline = '\0';
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Education (0-None, 1-Primary, 2-Secondary, 3-Higher): ");
    int edu;
    scanf("%d", &edu);
    p.education = (Education)edu;
    printf("Work status (0-Unemployed, 1-Employed): ");
    int ws;
    scanf("%d", &ws);
    p.work_status = (Work_status)ws;
    printf("Marital status (0-Single, 1-Married): ");
    int ms;
    scanf("%d", &ms);
    p.marital_status = (Marital_status)ms;
    getchar();
    return p;
}


void print_person(const Person *p) {
    const char *edu[4] = {"No education", "Primary", "Secondary", "Higher"};
    const char *work[2] = {"Unemployed", "Employed"};
    const char *marital[2] = {"Single", "Married"};
    printf("EGN: %s, Name: %s, Age: %d, Education: %s, Work status: %s, Marital status: %s\n",
           p->EGN, p->name, p->age, edu[p->education], work[p->work_status], marital[p->marital_status]);
}


void add_person(const char *filename) {
    FILE *f = fopen(filename, "ab");
    if (!f) {
        printf("Error opening file!\n");
        return;
    }
    Person p = input_person();
    fwrite(&p, sizeof(Person), 1, f);
    fclose(f);
    printf("Record added.\n");
}


void print_all(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Error opening file!\n");
        return;
    }
    Person p;
    while (fread(&p, sizeof(Person), 1, f) == 1) {
        print_person(&p);
    }
    fclose(f);
}

void delete_by_egn(const char *filename, const char *egn_to_delete) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Error opening file!\n");
        return;
    }
    FILE *tmp = fopen("tmp.bin", "wb");
    if (!tmp) {
        printf("Error creating temporary file!\n");
        fclose(f);
        return;
    }
    Person p;
    int found = 0;
    while (fread(&p, sizeof(Person), 1, f) == 1) {
        if (strcmp(p.EGN, egn_to_delete) != 0) {
            fwrite(&p, sizeof(Person), 1, tmp);
        } else {
            found = 1;
        }
    }
    fclose(f);
    fclose(tmp);
    remove(filename);
    rename("tmp.bin", filename);
    if (found)
        printf("Record deleted.\n");
    else
        printf("No record found with this EGN.\n");
}

int main() {
    char filename[256];
    printf("Enter file name: ");
    scanf("%255s", filename);
    getchar();

    int choice;
    do {
        printf("\n1. Add person\n2. Show all\n3. Delete by EGN\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
            add_person(filename);
        } else if (choice == 2) {
            print_all(filename);
        } else if (choice == 3) {
            char egn[11];
            printf("Enter EGN to delete: ");
            scanf("%10s", egn);
            getchar();
            delete_by_egn(filename, egn);
        }
    } while (choice != 0);

    return 0;
}