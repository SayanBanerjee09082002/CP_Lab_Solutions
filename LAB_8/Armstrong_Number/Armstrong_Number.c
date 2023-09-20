#include <stdio.h>
#include <math.h>

int isArmstrong(int num)
{
    int temp = num, sum = 0, digits = 0;

    while (temp > 0)
    {
        temp = temp / 10;
        digits++;
    }

    temp = num;

    while (temp > 0)
    {
        sum += pow(temp % 10, digits);
        temp /= 10;
    }

    return sum == num ? 1 : 0;
}

int main()
{
    int num;
    char option;

    do
    {
        printf("\nEnter the number:  ");
        scanf("%d", &num);
        printf(isArmstrong(num) ? "The given number is Armstrong number" : "The given number is not Armstrong number");
        printf("\nContinue?\n");
        scanf(" %c", &option);
    } while (option == 'Y' || option == 'y');

    return 0;
}