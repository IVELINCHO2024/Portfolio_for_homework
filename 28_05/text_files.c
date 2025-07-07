#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book{
    char name[100];
    char author[100];
    char genre[100];
    int ISBN;
    int year;
    struct book* next;
}Book;

typedef struct list{
    Book* head;
    int size;
}List;

List innit(){
    List library={
        .head = NULL,
        .size = 0
    };

    return library;
}

Book* createBook(char* name, char* author, char* genre, int ISBN, int year){
    Book* newBook =(Book*)malloc(sizeof(Book));
    if(newBook == NULL){
        exit(1);
    }
    strcpy(newBook->name, name);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
    newBook->ISBN = ISBN;
    newBook->year = year;

    return newBook;
}

void addBook(List* library, Book* book){
    book->next = library->head;
    library->head = book;
    library->size++;
}

void loadBooks(List* library){
    FILE* file = fopen("library.txt", "r");
    if(!file){
        printf("no file");
    }

    char name[100], author[100], genre[100];
    int ISBN, year;
    while(fscanf(file, "%s %s %s %d %d", name, author, genre, &ISBN, &year) == 5){
        Book* book = createBook(name, author, genre, ISBN, year);
        addBook(library, book);

    }

    fclose(file);
}

void addBookUser(List* library){
    char name[100], author[100], genre[100];
    int year, ISBN;
    printf("Name: ");
    scanf("%s", &name);
    printf("Author: ");
    scanf("%s", &author);
    printf("Genre: ");
    scanf("%s", &genre);
    printf("ISBN: ");
    scanf("%d", &ISBN);
    printf("Year: ");
    scanf("%d", &year);

    Book* newBook = createBook(name, author, genre, ISBN, year);
    addBook(library, newBook);

}

void saveBooks(List* library){
    FILE* file = fopen("library.txt", "w");

    Book* currentBook = library->head;
    while(currentBook){
        fprintf(file, "%s %s %s %d %d\n", currentBook->name, currentBook->author, currentBook->genre, currentBook->ISBN, currentBook->year);
        currentBook = currentBook->next;
    }

    fclose(file);
}

void printBooks(List* library){
    Book* currentBook = library->head;
    while(currentBook){
        printf("%s %s %s %d %d\n", currentBook->name, currentBook->author, currentBook->genre, currentBook->year, currentBook->ISBN);
        currentBook = currentBook->next;
    }
}

void deletebyISBN(List* library, int ISBN){
    Book* currentbook = library->head;
    Book* prev = NULL;
    while(currentbook != NULL){
        if(ISBN == currentbook->ISBN){
            if(prev == NULL){
                library->head = currentbook->next;
            }
            else{
                prev->next = currentbook->next;
            }

            free(currentbook);
            library->size--;
            printf("The book is deleted");
            return;
        }
        prev = currentbook;
        currentbook = currentbook->next;
    }
}

void freelibrary(List* library){
    Book* currentbook = library->head;
    Book* temp = NULL;
    while(currentbook){
        temp = currentbook;
        currentbook = currentbook->next;
        free(temp);
    }
    library->head = NULL;
    library->size = 0;

}

int main(){
    List library = innit();
    loadBooks(&library);
    int choice;
    while(1){
        printf("\n--- Електронна библиотека ---\n");
        printf("1. Добави книга\n");
        printf("2. Покажи всички книги\n");
        printf("3. Изтрий книга по ISBN\n");
        printf("4. Запази и изход\n");
        printf("Избор: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addBookUser(&library);break;
            case 2: printBooks(&library);break;
            case 3: int ISBN; 
            printf("Enter ISBN to delete: ");
            scanf("%d", &ISBN);
            deletebyISBN(&library, ISBN);break;
            case 4: saveBooks(&library);
            freelibrary(&library);
            break;
        }
        if(choice == 4){
            break;
        }
    }

    return 0;
}