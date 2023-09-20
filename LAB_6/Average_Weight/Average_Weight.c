#include <stdio.h>

int main()
{
    double weight1, weight2;
    int quantity1, quatity2;

    printf("Enter the weight of item1:    ");
    scanf("%lf", &weight1);
    printf("Enter the quantity of item1:  ");
    scanf("%d", &quantity1);
    printf("Enter the weight of item2:    ");
    scanf("%lf", &weight2);
    printf("Enter thr quantity of item2:  ");
    scanf("%d", &quatity2);

    printf("Average weight:  %lf", ((weight1 * quantity1) + (weight2 * quatity2)) / 2);

    return 0;
}