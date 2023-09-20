#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;

    FILE *file = fopen("dyn_arrays.txt", "r");

    if (file == NULL)
    {
        printf("File open failed.\n");
        return 1;
    }

    fscanf(file, "%d %d", &m, &n);

    int **matrix = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fscanf(file, "%d", &matrix[i][j]);

    fclose(file);

    printf("Matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }

    for (int i = 0; i < m; i++)
        free(matrix[i]);

    free(matrix);

    return 0;
}
