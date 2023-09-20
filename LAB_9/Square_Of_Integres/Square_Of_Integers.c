#include <stdio.h>

int main()
{
    int arr[100], index = 0;
    char option;

    do
    {
        printf("\nEnter the number: ");
        scanf("%d", &arr[index]);
        index++;
        printf("Continue (Y/N): ");
        scanf(" %c", &option);
    } while (option == 'Y' || option == 'y');

    printf("\nGiven array:");

    for (int i = 0; i <= index - 1; i++)
        printf(" %d", arr[i]);

    return 0;
}