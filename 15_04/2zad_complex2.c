#include <stdio.h>

typedef struct node{
    char firstname[50];
    struct node *father;
    struct node *mother;
    struct node *marriedto;

} Node;

int main(){
    Node myFamily;
    Node myFather = {
        .firstname = "Valeri",
        .father = NULL,
        .mother = NULL,
        .marriedto = NULL
    };
    Node myMother = {
        .firstname = "Silvia",
        .father = NULL,
        .mother = NULL,
        .marriedto = NULL
    };
    Node grandmother_mother = {
        .firstname = "Ivanka",
        .father = NULL,
        .mother = NULL,
        .marriedto = NULL
    };
    Node grandfather_mother = {
        .firstname = "Qna",
        .father = NULL,
        .mother = NULL,
        .marriedto = NULL
    };
    Node grandmother_father = {
        .firstname = "Ivan",
        .father = NULL,
        .mother = NULL,
        .marriedto = NULL
    };
    Node grandfather_father = {
        .firstname = "Georgi",
        .father = NULL,
        .mother = NULL,
        .marriedto = NULL
    };

    myFather.father = &grandfather_father;
    myFather.mother = &grandmother_father;
    myFather.marriedto = &myMother;
    myMother.father = &grandfather_mother;
    myMother.mother = &grandmother_mother;
    myMother.marriedto = &myFather;
    grandfather_father.marriedto = &grandmother_father;
    grandfather_mother.marriedto = &grandmother_mother;
    grandmother_father.marriedto = &grandfather_father;
    grandmother_mother.marriedto = &grandfather_mother;


    myFamily =(Node) {
        .firstname = "Ivelin",
        .father = &myFather,
        .mother = &myMother,
        .marriedto = NULL
    };

    printf("My name is %s\n", myFamily.firstname);
    printf("My father is %s\n", myFamily.father->firstname);
    printf("My mother is %s\n", myFamily.mother->firstname);
    printf("My father's father is %s\n", myFamily.father->father->firstname);
    printf("My father's mother is %s\n", myFamily.father->mother->firstname);
    printf("My mother's father is %s\n", myFamily.mother->father->firstname);
    printf("My mother's mother is %s\n", myFamily.mother->mother->firstname);

    return 0;
}