#include <stdio.h>

int main()
{
    int N, sum = 0;

    printf("Enter numbers of the first N natural numbers:  ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i += 2)
        sum += i;

    printf("Sum of all odd numbers in N = %d", sum);

    return 0;
}