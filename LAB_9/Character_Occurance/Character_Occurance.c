#include <stdio.h>

int main()
{
    char arr[20], c;
    int index = 0, charCount[26] = {0};

    printf("Enter a string of characters (<= 20): ");

    while ((c = getchar()) != '\n' && index < 20)
    {
        arr[index] = c;
        index++;
    }
    arr[index] = '\0';

    printf("String stored in the array: ");

    for (int j = 0; arr[j] != '\0'; j++)
        printf("%c", arr[j]);

    printf("\n");

    for (int j = 0; arr[j] != '\0'; j++)
        if (isalpha(arr[j]))
            charCount[toupper(arr[j]) - 'A']++;

    printf("String stored in the array: %s\n", arr);

    for (int j = 0; j < 26; j++)
        if (charCount[j] > 0)
            printf("'%c' occurs %d times\n", 'A' + j, charCount[j]);

    return 0;
}