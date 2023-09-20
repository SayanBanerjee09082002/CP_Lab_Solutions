#include <stdio.h>

int main()
{
    int N;

    printf("Enter numbers of the first N natural numbers:  ");
    scanf("%d", &N);

    printf("All odd numbers in N:  ");

    for (int i = 1; i <= N; i += 2)
        printf("%d  ", i);

    return 0;
}