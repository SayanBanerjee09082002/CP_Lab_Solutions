#include <stdio.h>
#include <math.h>

double convertToDecimal(long double binary)
{
    double decimal = 0.0, fractionalpart, gnum;
    long int wholepart, temp = 0;
    int i = 0, j = -1;

    wholepart = (long int)binary;
    fractionalpart = binary - wholepart;
    
    while (modf(fractionalpart, &gnum) != 0)
        fractionalpart = fractionalpart * 10;
    
    while (fractionalpart != 0)
    {
        temp = temp * 10 + ((int)fractionalpart % 10);
        fractionalpart /= 10;
    }

    while (wholepart > 0)
    {
        decimal = decimal + ((wholepart % 10) * pow(2, i));
        i++;
        wholepart = wholepart / 10;
    }

    while (temp > 0)
    {
        decimal = decimal + ((temp % 10) * pow(2, j));
        j--;
        temp = temp / 10;
    }

    return decimal;
}

long double convertToBinary(double N)
{
    double frac = 0.0, fractionalpart = 0.0;
    int wholepart, remainders[300], len = 0, trials = 1;
    long double result = 0.0;

    wholepart = N;
    fractionalpart = N - wholepart;

    while (wholepart > 0)
    {
        remainders[len] = wholepart % 2;
        wholepart = wholepart / 2;
        len++;
    }

    while (fractionalpart != 0)
    {
        if (trials > 100)
        {
            printf("Fractional paart not converging.");
            return 1;
        }

        fractionalpart = fractionalpart * 2;
        frac = frac + ((int)fractionalpart * pow(10, -trials));
        fractionalpart = (int)fractionalpart - fractionalpart;

        trials++;
    }

    for (int i = len - 1; i >= 0; i--)
        result = (result * 10) + (long double)remainders[i];

    result = result + frac;

    return result;
}

int main()
{
    char option;
    long double binary;
    double decimal;

    while (option != 'x')
    {
        printf("\n\nEnter option:  ");
        scanf(" %c", &option);

        if (option == 'b')
        {
            printf("\nEnter the binary number:  ");
            scanf("%Lf", &binary);
            printf("Decimal equivalent of %Lf is = %lf", binary, convertToDecimal(binary));
        }
        else if (option == 'd')
        {
            printf("\nEnter the decimal number:  ");
            scanf("%lf", &decimal);
            printf("Binary equivalent of %lf is = %Lf", decimal, convertToBinary(decimal));
        }
        else
            printf("\nEnter the a valid input");
    }

    return 0;
}