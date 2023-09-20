#include <stdio.h>
#include <math.h>

long long int convertToBinary(int N)
{
    int remainders[300], len = 0;
    long long int result = 0;

    while (N > 0)
    {
        remainders[len] = N % 2;
        N = N / 2;
        len++;
    }

    for (int i = len - 1; i >= 0; i--)
        result = (result * 10) + (long long int)remainders[i];

    return result;
}

long long int twosCompliment(int num, int len)
{
    int temp[100], encounteredOne = 0, twoC = 0;

    for (int i = 0; i <= len - 1; i++)
    {
        temp[i] = num % 10;
        num = num / 10;
    }

    for (int i = 0; i <= len - 2; i++)
    {
        if (encounteredOne == 1)
        {
            if (temp[i] == 1)
                temp[i] = 0;
            else
                temp[i] = 1;
        }

        if (temp[i] == 1)
            encounteredOne = 1;
    }

    for (int i = len - 1; i >= 0; i--)
        twoC = (twoC * 10) + (long long int)temp[i];

    return twoC;
}

int sumUnequalLength(int num1, int num2)
{
    int bint1[300], bint2[300], temp[300], add = 0, carry = 0, result = 0, len = 0, len1 = 0, len2 = 0;

    while (num1 != 0)
    {
        bint1[len1] = num1 % 10;
        num1 = num1 / 10;
        len1++;
    }

    while (num2 != 0)
    {
        bint2[len2] = num2 % 10;
        num2 = num2 / 10;
        len2++;
    }

    if (len1 > len2)
        len = len1;
    else
        len = len2;

    for (int i = 0; i <= len - 1; i++)
    {
        if (i == len - 1)
        {
            add = bint1[i] + bint2[i] + carry;
            if (add <= 1)
            {
                temp[i] = add;
                carry = 0;
            }
            else
            {
                if (add == 2)
                {
                    temp[i] = 0;
                    temp[i + 1] = 1;
                }
                else if (add == 3)
                {
                    temp[i] = 1;
                    temp[i + 1] = 1;
                }
                else
                {
                    printf("\nERROR!\n");
                    return 1;
                }
            }
        }
        else
        {
            add = bint1[i] + bint2[i] + carry;
            if (add <= 1)
            {
                temp[i] = add;
                carry = 0;
            }
            else
            {
                if (add == 2)
                {
                    temp[i] = 0;
                    carry = 1;
                }
                else if (add == 3)
                {
                    temp[i] = 1;
                    carry = 1;
                }
                else
                {
                    printf("\nERROR!\n");
                    return 1;
                }
            }
        }
    }

    for (int i = len; i >= 0; i--)
        result = (result * 10) + temp[i];

    return result;
}

int main()
{
    int dec = 5002;
    printf("Binary = %lld \nOctal = %o\nHexadecimal = %X\nOnes Compliment = %lld\nTwos Compliment = %lld", convertToBinary(dec), dec, dec, sumUnequalLength(twosCompliment(convertToBinary(dec), floor(log10(abs(convertToBinary(dec)))) + 1), 11), twosCompliment(convertToBinary(dec), floor(log10(abs(convertToBinary(dec)))) + 1));
}