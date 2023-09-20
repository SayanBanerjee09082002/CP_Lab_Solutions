#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("raggedarray.txt", "r");

    if (file == NULL)
    {
        printf("File open failed.\n");
        return 1;
    }

    int numRows;
    fscanf(file, "%d", &numRows);

    int **matrix = (int **)malloc(numRows * sizeof(int *));

    for (int i = 0; i < numRows; i++)
    {
        int numCols;
        fscanf(file, "%d", &numCols);

        matrix[i] = (int *)malloc(numCols * sizeof(int));

        printf("Row %d (%d columns): ", i + 1, numCols);
        for (int j = 0; j < numCols; j++)
        {
            fscanf(file, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numRows; i++)
        free(matrix[i]);

    free(matrix);

    fclose(file);

    return 0;
}
