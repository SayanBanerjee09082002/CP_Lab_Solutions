#include <stdio.h>
#include <stdlib.h>
#define ROWS 100
#define COLS 100

double findMaxWithdrawl(double data[][COLS], int m, int n)
{
    double sum = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (data[i][j] < 0)
                sum += data[i][j];

    return sum;
}

int computeMaxDeposit(double row[], int n, double *max)
{
    int deposit = 0;

    for (int i = 0; i < n; i++)
        if (row[i] > 0)
            deposit += row[i];

    if (*max < deposit)
        *max = deposit;

    return deposit;
}

int computeMaxTransac(int row[], int size, double *max)
{
    int transaction = 0;

    for (int i = 0; i < size; i++)
        transaction += abs(row[i]);

    if (*max < transaction)
        *max = transaction;

    return transaction;
}

int main()
{
    int m, n, maxDepositBranch = 0, maxTrasactionBranch = 0;
    double maxDeposit = 0, maxTransaction = 0;

    printf("Enter the number of branches: ");
    scanf("%d", &m);
    printf("Enter the maximum number of transaction: ");
    scanf("%d", &n);

    double array[ROWS][COLS];

    for (int i = 0; i < m; i++)
    {
        printf("Enter the transactions of ATM Branch %i:\n", i);
        for (int j = 0; j < n; j++)
            scanf("%lf", &array[i][j]);
    }

    printf("\nMaximum Withdrawl = $%lf\n", findMaxWithdrawl(array, m, n));

    for (int i = 0; i < m; i++)
        if (maxDeposit <= computeMaxDeposit(array[i], n, &maxDeposit))
            maxDepositBranch = i;
    printf("Bank ATM with maximum deposit = %d\n", maxDepositBranch);

    for (int i = 0; i < m; i++)
        if (maxTransaction <= computeMaxTransac(array[i], n, &maxTransaction))
            maxTrasactionBranch = i;
    printf("Bank ATM with maximum transaction = %d", maxTransaction);

    return 0;
}