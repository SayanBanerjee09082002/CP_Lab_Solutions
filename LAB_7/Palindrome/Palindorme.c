#include <stdio.h>

int main()
{
    int num;

    printf("Enter the number:  ");
    scanf("%d", &num);

    num % 10 == num / 1000 ? (num / 100) % 10 == (num / 10) % 10 ? printf("Palindrome") : printf("Not Palindrome") : printf("Not Palindrome");

    return 0;
}