#include <stdio.h> //MISSING LIB

int main()
{
    char ch = 'A';
    float flt = 10.234;  //INSERT "=" HERE
    int no = 150; printf("Character is %c \n", ch);  //INSERT ";" BETWEEN "150" AND "printf"
    scanf("%c", &ch); //INSERT %c WITHIN ""
    printf("Character is %c \n", ch);
    printf("Float value is %f \n", flt);
    scanf("%f", &flt); //INSERT & BEFORE flt
    printf("Float value is %f \n", flt);
    printf("Integer value is %d\n", no);
    scanf("%d", &no); //NOT "n" ITS "no"
    printf("Integer value is %d\n", no);
    return 0;
}
