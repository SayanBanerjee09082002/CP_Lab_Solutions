#include <stdio.h>

int main()
{
    int month;

    printf("Enter the index of month:  ");
    scanf("%d", &month);

    switch (month)
    {
    case 1:
    case 2:
    case 12:
        printf("Winter");
        break;
    case 3:
    case 4:
    case 5:
        printf("Spring");
        break;
    case 6:
    case 7:
    case 8:
        printf("Summer");
        break;
    case 9:
    case 10:
    case 11:
        printf("Autumn");
        break;
    default:
        printf("Invalid Index");
    }

    return 0;
}