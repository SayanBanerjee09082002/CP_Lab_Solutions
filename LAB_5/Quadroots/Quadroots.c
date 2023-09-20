#include <stdio.h>
#include <math.h>

int main () {
    float a, b, c;
    
    printf("Enter a:  ");
    scanf("%f", &a);
    printf("Enter b:  ");
    scanf("%f", &b);
    printf("Enter c:  ");
    scanf("%f", &c);

    float x1 = (-b + sqrt((b*b) - (4 * a * c))) / (2 * a);
    float x2 = (-b - sqrt((b*b) - (4 * a * c))) / (2 * a);

    printf("Roots are %f and %f", x1, x2);

    return 0;
}