#include <stdio.h>


int strlength(const char *str) {
    int length = 0;
    while(str[length]!='\0'){
        length++;
    }
    
    return length;
}


void strconcat(const char *str1, const char *str2, char *result) {
    int i = 0, j = 0;

   
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    
    result[i] = '\0';
}


int strcompare(const char *str1, const char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    
    return str1[i] - str2[i];
}


void printHelpMenu() {
    printf("menu:\n");
    printf("strlength: намира дължината на символен низ.\n");
    printf("strconcat: обединява два символни низа.\n");
    printf("strcompare: сравнява два символни низа.\n");
}

int main() {
    printHelpMenu();
    return 0;
}
