#include <stdio.h>

int main() {
    double baseSalary = 1500.00, bonus = 200.00, commission = 0.02;
    int sales;

    printf("Enter the monthly sales of the sales man:  ");
    scanf("%d", &sales);

    printf("Bonus = %lf\n", bonus * sales);
    printf("Commission = %lf\n", commission * bonus * sales);
    printf("Gross Salary = %lf\n", baseSalary + (bonus * sales) + (commission * bonus * sales));

    return 0;
}