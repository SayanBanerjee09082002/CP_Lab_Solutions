#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter the first integer:  ");
    scanf("%d", &num1);
    printf("Enter the second intger:  ");
    scanf("%d", &num2);

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    printf("After swaping\nInteger1 = %d\nInteger2 = %d", num1, num2);

    return 0;
}