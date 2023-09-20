#include <stdio.h>

int main()
{
    int num;
    int year, month, day;

    printf("Enter the number of days:  ");
    scanf("%d", &num);

    year = num / 365;
    month = (num % 365) / 30;
    day = ((num % 365) % 30);

    printf("%d days = %d years, %d months, %d days", num, year, month, day);

    return 0;
}