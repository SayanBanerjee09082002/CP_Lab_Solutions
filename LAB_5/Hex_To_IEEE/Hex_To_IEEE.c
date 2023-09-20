#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char hexdec[100] = "40490FDB";
char binarystr[300] = "";

long long int hexToBinary()
{
    int i = (hexdec[1] == 'x' || hexdec[1] == 'X') ? 2 : 0;

    while (hexdec[i])
    {
        switch (hexdec[i])
        {
        case '0':
            strcat(binarystr, "0000");
            break;
        case '1':
            strcat(binarystr, "0001");
            break;
        case '2':
            strcat(binarystr, "0010");
            break;
        case '3':
            strcat(binarystr, "0011");
            break;
        case '4':
            strcat(binarystr, "0100");
            break;
        case '5':
            strcat(binarystr, "0101");
            break;
        case '6':
            strcat(binarystr, "0110");
            break;
        case '7':
            strcat(binarystr, "0111");
            break;
        case '8':
            strcat(binarystr, "1000");
            break;
        case '9':
            strcat(binarystr, "1001");
            break;
        case 'A':
        case 'a':
            strcat(binarystr, "1010");
            break;
        case 'B':
        case 'b':
            strcat(binarystr, "1011");
            break;
        case 'C':
        case 'c':
            strcat(binarystr, "1100");
            break;
        case 'D':
        case 'd':
            strcat(binarystr, "1101");
            break;
        case 'E':
        case 'e':
            strcat(binarystr, "1110");
            break;
        case 'F':
        case 'f':
            strcat(binarystr, "1111");
            break;
        case '.':
            printf(".");
        default:
            printf("\nInvalid hexadecimal digit %c",
                   hexdec[i]);
        }

        i++;
    }

    return strtoll(binarystr, NULL, 2);
}

long double convertToBinary(long double N)
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
    long double m = (mantissa - floorl(mantissa)) * powl(10, 23);

    int e = (int)convertToBinary(127 + exponent);

    printf("IEEE Representation = %d %d %lld", isneg ? 1 : 0, e, (long long int)m);
}

int main()
{

    convertToIEEE(convertToBinary((long double)hexToBinary(hexdec)), 0);

    return 0;
}
