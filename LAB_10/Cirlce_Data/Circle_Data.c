#include <stdio.h>
#define PI 3.14159265359

void cirlceData(double radius, double *area, double *circumference) {
    if (radius < 0) {
        printf("Only an idiot will provide negative radius.\n");
        return;
    }

    *area = PI * radius * radius;
    *circumference = 2 * PI * radius;
}

int main() {
    double radius, area, circumference;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    cirlceData(radius, &area, &circumference);

    printf("Area of circle = %lf\nCircumference of cirlce = %lf", area, circumference);

    return 0;
}