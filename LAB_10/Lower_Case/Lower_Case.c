#include <stdio.h>
#include <ctype.h>
#include <string.h>

void convertToLowerASCII(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  
        }
    }
}

void convertToLowerLibrary(char *str) {
    for (int i = 0; str[i] != '\0'; i++) 
        str[i] = tolower(str[i]);
}

int main() {
    char inputStr[100];

    printf("Enter a string: ");
    fgets(inputStr, sizeof(inputStr), stdin);

    convertToLowerASCII(inputStr);
    printf("Lowercase (ASCII): %s", inputStr);

    convertToLowerLibrary(inputStr);
    printf("Lowercase (tolower()): %s\n", inputStr);

    return 0;
}
