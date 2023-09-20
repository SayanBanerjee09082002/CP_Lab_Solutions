#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int arrayLength = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrayLength / 2; i++)
    {
        arr[i] = arr[i] + arr[arrayLength - 1 - i];
        arr[arrayLength - 1 - i] = arr[i] - arr[arrayLength - 1 - i];
        arr[i] = arr[i] - arr[arrayLength - 1 - i];
    }

    printf("Reversed array: ");

    for (int i = 0; i < arrayLength; i++)
        printf("%d ", arr[i]);

    return 0;
}