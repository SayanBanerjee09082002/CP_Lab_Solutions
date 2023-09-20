#include <stdio.h>
#define MAX 20

int count_lin_search = 0;
int count_ternary_search = 0;

int linear_search(int arr[], int n, int x, int index)
{
    if (arr[index] == x)
    {
        count_lin_search++;
        return index;
    }
    else if (index < n)
    {
        count_lin_search++;
        linear_search(arr, n, x, index + 1);
    }
    else
        return -1;
}

int ternary_search(int arr[], int n, int x, int index)
{
    int div1 = n / 3, div2 = (2 * n) / 3;

    if (x <= arr[div1 - 1])
    {
        if (arr[index] == x)
        {
            count_ternary_search++;
            return index;
        }
        else if (index <= div1 - 1)
        {
            count_ternary_search++;
            ternary_search(arr, n, x, index + 1);
        }
        else
            return -1;
    }
    else if (x <= arr[div2 - 1] && x > arr[div1 - 1])
    {
        if (count_ternary_search == 0)
            index = div1;

        if (arr[index] == x)
        {
            count_ternary_search++;
            return index;
        }
        else if (index <= div2 - 1)
        {
            count_ternary_search++;
            ternary_search(arr, n, x, index + 1);
        }
        else
            return -1;
    }
    else if (x <= arr[n - 1] && x > arr[div2 - 1])
    {
        if (count_ternary_search == 0)
            index = div2;
        if (arr[index] == x)
        {
            count_ternary_search++;
            return index;
        }
        else if (index <= n - 1)
        {
            count_ternary_search++;
            ternary_search(arr, n, x, index + 1);
        }
        else
            return -1;
    }
    else
    {
        count_ternary_search++;
        return -1;
    }
}

int main()
{
    int array[MAX], n, x;

    printf("Enter the number of elements n: ");
    scanf("%d", &n);

    printf("Enter the sorted array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Enter the number to be searched: ");
    scanf("%d", &x);

    printf("\nLINEAR SEARCH\n");
    int op1 = linear_search(array, n, x, 0);
    op1 == -1 ? printf("%d is not present\n", x) : printf("%d is present at position %d\n", x, op1);
    printf("Function is called %d time\n", count_lin_search);

    printf("\nTERNARY SEARCH\n");
    int op2 = ternary_search(array, n, x, 0);
    op2 == -1 ? printf("%d is not present\n", x) : printf("%d is present at position %d\n", x, op2);
    printf("Function is called %d time\n", count_ternary_search);
}