#include <stdio.h>

int main()
{
    char operation;
    int num1, num2;

    printf("Enter the first integer:  ");
    scanf("%d", &num1);
    printf("Enter the second integer:  ");
    scanf("%d", &num2);
    printf("Enter the operation symbol: ");
    scanf(" %c", &operation);

    switch (operation)
    {
        case '+':
            printf("Result = %d", num1 + num2);
            break;
        case '-': 
            printf("Result = %d", num1 - num2);
            break;
        case '*':
            printf("Result = %d", num1 * num2);
            break;
        case '/':
            num2 == 0 ? printf("Undefined") :  printf("Result = %lf", (double)num1 / num2);
            break;
        case '%':
            printf("Result = %d", num1 % num2);
            break;
        default:
            printf("Error!");
    }

    return 0;
}