#include <stdio.h>

int main()
{
    int month;

    printf("Enter the index of month:  ");
    scanf("%d", &month);

    if (month <= 0 || month > 12)
        printf("Invalid index");
    else if (month <= 2 || month == 12)
        printf("Winter");
    else if (month <= 5 || month > 2)
        printf("Spring");
    else if (month <= 8 || month > 5)
        printf("Summer");
    else if (month <= 11 || month > 8)
        printf("Autumn");
    else
        printf("Error");

    return 0;
}