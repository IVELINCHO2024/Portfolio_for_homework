#include <stdio.h>
#include <limits.h>
#include <stdint.h>


#define PRINT_INT_TYPE_INFO(type, format, uformat,max,min,unmax) \
    printf("| %-15s | %-10s | %-5zu | %-20d | %-20d | %-10s | %-20u |\n", \
           #type, #format, sizeof(type), max, min, #uformat, unmax); \

int main() {
   
    printf("| Type            | Format     | Size  | Signed Max          | Signed Min          | Unsigned Format | Unsigned Max      |\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    

    PRINT_INT_TYPE_INFO(char, %d, %u, CHAR_MAX, CHAR_MIN, UCHAR_MAX);
    PRINT_INT_TYPE_INFO(short, %hd, %hu, SHRT_MAX, SHRT_MIN, USHRT_MAX);
    PRINT_INT_TYPE_INFO(int, %d, %u, INT_MAX, INT_MIN, UINT_MAX);
    PRINT_INT_TYPE_INFO(long, %ld, %lu, LONG_MAX, LONG_MIN, ULONG_MAX);
    PRINT_INT_TYPE_INFO(long long, %lld, %llu, LLONG_MAX, LLONG_MIN, ULLONG_MAX);

  

    return 0;
}
