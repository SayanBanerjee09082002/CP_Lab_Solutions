#include <stdio.h>

int main()
{
    int n, sum = 0;

    printf("Enter numbers of the first N natural numbers:  ");
    scanf("%d", &n);

    if (n > 0)
        for (int i = n; i <= 2 * n; i++)
            sum += i;
    else if (n < 0)
        for (int i = 3 * n; i <= 2 * n; i++)
            sum += i;
    else
        sum = 0;

    printf("Sum of all odd numbers in N = %d", sum);

    return 0;
}