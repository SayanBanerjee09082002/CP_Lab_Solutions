#include <stdio.h>

int main()
{
    float u, a, t;

    printf("Enter initial velocity:  ");
    scanf("%f", &u);
    printf("Enter acceleration:  ");
    scanf("%f", &a);
    printf("Enter the time passed:  ");
    scanf("%f", &t);

    float s = (u * t) + (0.5 * a * t * t);

    printf("Displacement = %f", s);

    return 0;
}