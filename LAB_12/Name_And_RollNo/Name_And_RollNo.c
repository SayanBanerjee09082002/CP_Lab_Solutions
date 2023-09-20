#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    int rollNo;
} Student;

int main()
{
    char option = 'Y';
    char name[50];
    int rollNo;

    while (option == 'Y')
    {
        printf("Enter the Students name: ");
        fflush(stdin);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("Enter the Students roll number: ");
        scanf("%d", &rollNo);

        FILE *file = fopen("output.txt", "a");

        if (file == NULL)
        {
            perror("Error opening file");
            return 1;
        }

        fprintf(file, "Name:    %s\n", name);
        fprintf(file, "Roll No:  %d\n\n", rollNo);

        fclose(file);

        printf("Continue (Y/N)?: ");
        scanf(" %c", &option);
    }

    FILE *file = fopen("output.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("\n\n");

   char  c = fgetc(file);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(file);
    }

    fclose(file);

    return 0;
}
