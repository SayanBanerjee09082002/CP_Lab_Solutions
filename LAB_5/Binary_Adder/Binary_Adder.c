#include <stdio.h>

int sumEqualLength(int num1, int num2)
{
    int bint1[300], bint2[300], temp[300], add = 0, carry = 0, result = 0, len = 0;

    while (num1 != 0)
    {
        bint1[len] = num1 % 10;
        bint2[len] = num2 % 10;

        num1 = num1 / 10;
        num2 = num2 / 10;

        len++;
    }

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
    int num1, num2, option;

    printf("Enter the first binary number:  ");
    scanf("%d", &num1);
    printf("Enter the second binary number:  ");
    scanf("%d", &num2);

    printf("Choose the option:\n");
    printf("1. Input binary numbers of equal length\n");
    printf("2. Input binary numbers of unequal length\n");
    scanf("%d", &option);

    if (option == 1)
        printf("The sum is = %d", sumEqualLength(num1, num2));
    else
        printf("The sum is = %d", sumUnequalLength(num1, num2));
    return 0;
}