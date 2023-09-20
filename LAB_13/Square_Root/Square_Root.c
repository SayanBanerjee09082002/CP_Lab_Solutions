#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int size;

    printf("Enter the size of the integer array: ");
    scanf("%d", &size);

    int *intArray = (int *)malloc(size * sizeof(int));

    printf("Enter the elements of the integer array:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &intArray[i]);

    printf("Square roots of non-negative elements:\n");
    for (int i = 0; i < size; i++)
    {
        if (intArray[i] >= 0)
        {
            double squareRoot = sqrt((double)intArray[i]);
            printf("Element %d: %lf\n", intArray[i], squareRoot);
        }
    }

    free(intArray);

    return 0;
}