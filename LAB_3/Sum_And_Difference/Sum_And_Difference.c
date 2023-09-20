#include <stdio.h>

int main()
{
    int a, b;

    printf("Enter first integer:  ");
    scanf("%d", &a);
    printf("Enter second integer:  ");
    scanf("%d", &b);

    printf("Sum = %d\nDifference = %d", a + b, a - b);

    return 0;
}