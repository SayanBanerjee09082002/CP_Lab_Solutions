#include <stdio.h>
#include <math.h>

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

void convertToIEEE(long double bnum, int isneg)
{
    int exponent = (int)log10(fabs(bnum));
    long double mantissa = bnum / pow(10, exponent);
    printf("%.23Lf\n", mantissa);
    long double m = (mantissa - floorl(mantissa)) * powl(10, 23);

    int e = (int)convertToBinary(127+exponent);

    printf("IEEE Representation = %d %d %lld", isneg ? 1 : 0, e, (long long int)m);
}

int main() {
    double x = 263.125;

    convertToIEEE(convertToBinary(x), x < 0 ? 1 : 0);

    return 0;
}