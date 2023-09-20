#include <stdio.h>
#include <string.h>

int main() {
    char S1[100], S2[100], S3[200];

    printf("Enter the first string (S1): ");
    scanf("%s", S1);

    printf("Enter the second string (S2): ");
    scanf("%s", S2);

    int cmp = strcmp(S1, S2);

    if (cmp < 0) {
        strcpy(S3, S1);
        strcat(S3, " ");
        strcat(S3, S2);
    } else if (cmp > 0) {
        strcpy(S3, S2);
        strcat(S3, " ");
        strcat(S3, S1);
    } else 
        strcpy(S3, S1);

    printf("S3 = %s\n", S3);

    return 0;
}
