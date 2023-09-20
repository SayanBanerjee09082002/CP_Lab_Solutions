#include <stdio.h>

int main()
{
    int option;
    double temp;

    while (option != 3)
    {
        printf("\nChoose the option:\nOption-1: Convert from degree Celsius to deg. Fahrenheit\nOption-2: Convert from deg. Fahrenheit to deg. Celsius\nOption-3: Quit the program execution\n");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("\nEnter the temperature to Celsius:  ");
            scanf("%lf", &temp);
            if (temp < -273.15)
                printf("Temperature less than absolute zero.\n");
            else
                printf("Enter the in Fahrenheit = %lf\n", (temp * 9 / 5) + 32);
        }

        if (option == 2)
        {
            printf("\nEnter the temperature to Fahrenheit:  ");
            scanf("%lf", &temp);
            if (temp < -459.67)
                printf("Temperature less than absolute zero.\n");
            else
            
                printf("Enter the in Celsius = %lf\n", (temp - 32) * 5 / 9);
        }
    }

    return 0;
}