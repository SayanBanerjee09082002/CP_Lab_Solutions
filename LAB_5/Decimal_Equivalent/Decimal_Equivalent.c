#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int twosComplementToDecimalConverter(int num, int len)
{
    int temp[100], encounteredOne = 0, decimal = 0;

   for (int i = 0; i <= len - 1; i++) {
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

    for (int i = 0; i <= len - 2; i++) {
        decimal = decimal + (temp[i] * pow(2, i));
    }

    if (temp[len - 1] == 1)
        decimal = -decimal;

    return decimal;
}

int main()
{
    int num1 = atoi("10111"), num2 = atoi("01100"); //CONVERTING STRING TO INT TO PREVENT IT FROM CONSIDERING THE INT AS OCTAL
    printf("\n10111 = %d\n01100 = %d", twosComplementToDecimalConverter(num1, 5), twosComplementToDecimalConverter(num2, 5));
}