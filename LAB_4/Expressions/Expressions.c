#include <stdio.h>
#include <math.h>
#define pi 3.142

int main() {
    float x, y;

    printf("Enter the value of x:  ");
    scanf("%f", &x);
    printf("Enter the value of y:  ");
    scanf("%f", &y);

    float expr1 = (exp(x) * sin(60) + (5.6 * pow(10,-5))) /  (3 * cos(30));
    float expr2 = sin(atan(0.33 + pi) / (2*y));

    printf("expr1 = %f\nexpr2 = %f", expr1, expr2);

    return 0;
}