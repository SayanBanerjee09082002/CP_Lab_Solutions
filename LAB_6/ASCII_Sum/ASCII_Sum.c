// NOTE 
// Always use a space before %c while scanning characters
// Otherwise errors like termination of programe without scanning rest of the scanf statements may happen


#include <stdio.h>

int main() {
    char char1, char2;

    printf("Enter the first character:  ");
    scanf(" %c", &char1);
    printf("Enter the second character:  ");
    scanf(" %c", &char2);

    int sum = char1 + char2;
    printf("Sum of ASCII values: %d", sum);

    return 0;
}