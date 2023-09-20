#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    double N, frac = 0.0, result = 0.0, fractionalpart = 0.0;
    int r, wholepart, remainders[300], len = 0, trials = 1;

    printf("Enter the decimal number:  ");
    scanf("%lf", &N);
    printf("Enter the radix (<10):  ");
    scanf("%d", &r);

    if (r > 9 || r < 2)
    {
        printf("Expected radix < 10 and > 1");
        return 1;
    }

    wholepart = N;
    fractionalpart = N - wholepart;

    while (wholepart > 0)
    {
        remainders[len] = wholepart % r;
        wholepart = wholepart / r;
        len++;
    }

    while (fractionalpart != 0)
    {
        if (trials > 100)
        {
            printf("Fractional paart not converging.");
            return 1;
        }

        fractionalpart = fractionalpart * r;
        frac = frac + ((int)fractionalpart * pow(10, -trials));
        fractionalpart = (int)fractionalpart - fractionalpart;

        trials++;
    }

    for (int i = len - 1; i >= 0; i--)
        result = (result * 10) + (double)remainders[i];

    printf("Whole number part = %f\n", result);
    printf("Fractional part = %f \n", frac);

    result = result + frac;

    printf("So, %lf base 10 = %lf base %d", N, result, r);

    return 0;
}