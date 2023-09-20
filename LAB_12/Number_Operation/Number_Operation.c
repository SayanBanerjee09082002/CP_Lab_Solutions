#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Invalid argument\n");
        return 1;
    }

    int N1 = atoi(argv[1]);
    int N2 = atoi(argv[2]);
    int t = atoi(argv[3]);

    switch (t)
    {
    case 0:
        printf("Exiting the program.\n");
        break;
    case 1:
        printf("Swapping values of N1 and N2.\n");
        int temp;
        temp = N1;
        N1 = N2;
        N2 = temp;
        printf("N1: %d, N2: %d\n", N1, N2);
        break;
    case 2:
        printf("Computing the sum of N1 and N2.\n");
        int sum = N1 + N2;
        printf("Sum of N1 and N2: %d\n", sum);
        break;
    default:
        printf("Invalid task value. Please use 0, 1, or 2.\n");
        break;
    }

    return 0;
}
