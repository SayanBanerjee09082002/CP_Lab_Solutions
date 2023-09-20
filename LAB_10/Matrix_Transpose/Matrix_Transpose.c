#include <stdio.h>
int rows, columns;

void function1 (int matrix[rows][columns], int rows, int columns){
    for (int i = 1; i <=columns; i++) {
        for (int j = 1; j<=rows; j++)
            printf("%d   ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int matrix[rows][columns];

    printf("Enter the components of matrix:\n");

    for (int i = 1; i<=rows; i++) 
        for (int j = 1; j<= columns; j++)
            scanf("%d", &matrix[i][j]);


    printf("\n");

    for (int i = 0; i <=columns - 1; i++) {
        for (int j = 0; j<=rows - 1; j++)
            printf("%d   ", matrix[i][j]);
        printf("\n");
    }
    function1(matrix, rows, columns);

    return 0;
}