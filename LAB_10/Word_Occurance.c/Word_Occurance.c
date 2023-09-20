#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int main()
{
    FILE *textFile;
    int count = 0, index;
    char *pos, *word;
    char str[BUFFER_SIZE], ch;

    word = malloc(50 * sizeof(char));
    textFile = fopen("input.txt", "r");

    if (textFile == NULL)
    {
        printf("Unable to read the text text file!");
        return 0;
    }

    printf("Enter the word: ");
    scanf("%s", word);

    printf("\nFile content:\n");
    do
    {
        char ch = fgetc(textFile);
        printf("%c", ch);

        index = 0;

        while ((pos = strstr(str + index, word)) != NULL)
        {
            index = (pos - str) + 1;
            count++;
        }
    } while (ch != EOF);

    printf("\n\nWord found %d times.\n", count);

    fclose(textFile);
    free(word);

    return 0;
}