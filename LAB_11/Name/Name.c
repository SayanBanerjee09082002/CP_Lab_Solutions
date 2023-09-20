#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct
{
    char fname[70];
    int freq;
    int len;
} NAME;

void getData(NAME arr[])
{
    FILE *file = fopen("names.txt", "r");

    if (file == NULL)
    {
        printf("\nError: File is missing or not being abled to open\n");
        return;
    }

    int index = 0;

    while (fscanf(file, "%[^ ] %d\n",
                  arr[index].fname,
                  &arr[index].freq) != EOF)
    {
        arr[index].len = strlen(arr[index].fname);
        index++;
    }

    fclose(file);
}

float findPercent(NAME arr[], int threshold)
{
    int totalNames = 0, index = 0, thesholdName = 0;

    while (arr[index].freq > 0)
    {
        if (threshold >= arr[index].len)
            thesholdName += arr[index].freq;
        totalNames += arr[index].freq;
        index++;
    }

    return ((float)thesholdName / totalNames) * 100;
}

int main()
{
    NAME nameData[MAX];
    int threshold;

    getData(nameData);

    printf("Enter the threshold: ");
    scanf("%d", &threshold);

    printf("Percentage of people under the threshold = %f", findPercent(nameData, threshold));

    return 0;
}