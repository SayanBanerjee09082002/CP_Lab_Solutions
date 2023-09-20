#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

struct Student_Record
{
    char id[13];
    char name[50];
    char gender;
    int age;
    char residential_status;
    double cgpa;
    char email[100];
};

void populateRecords(struct Student_Record studarr[MAX], int *no_studs)
{
    FILE *file = fopen("data.txt", "r");

    if (file == NULL)
    {
        printf("\nError: File is missing or not being abled to open\n");
        return;
    }

    while (fscanf(file, " %[^,],%[^,],%c,%d,%c,%lf\n",
                  studarr[*no_studs].id,
                  studarr[*no_studs].name,
                  &studarr[*no_studs].gender,
                  &studarr[*no_studs].age,
                  &studarr[*no_studs].residential_status,
                  &studarr[*no_studs].cgpa) != EOF)
    {
        (*no_studs)++;
    }

    fclose(file);
}

void generateEmailAddress(char idno[], char *email[])
{
    char year[5], srl[5];
    strncpy(year, idno + 0, 4);
    year[4] = '\0';
    strncpy(srl, idno + 8, 4);
    srl[4] = '\0';
    strcat(email, year);
    strcat(email, srl);
    strcat(email, "@pilani.bits-pilani.ac.in");
}

void storeEmailAddresses(struct Student_Record studarr[MAX], int *no_studs)
{
    for (int i = 0; i < *no_studs; i++)
    {
        studarr[i].email[0] = 'f';
        generateEmailAddress(studarr[i].id, &studarr[i].email);
    }
}

void printRecord(struct Student_Record studarr[MAX], int *no_studs)
{
    printf("\n\nStudent Records:\n\n");

    for (int i = 0; i < *no_studs; i++)
    {
        printf("ID: %s\n", studarr[i].id);
        printf("Name: %s\n", studarr[i].name);
        printf("Gender: %c\n", studarr[i].gender);
        printf("Age: %d\n", studarr[i].age);
        printf("Residential Status: %s\n", studarr[i].residential_status == 'H' ? "Hostel" : "Day Scholer");
        printf("CGPA: %.2f\n", studarr[i].cgpa);
        printf("Emaisl %s\n", studarr[i].email);
        printf("\n");
    }
}

double calculateAvgCGPA(struct Student_Record studarr[MAX], int *no_studs)
{
    double avgCGPA = 0;

    for (int i = 0; i < *no_studs; i++)
        avgCGPA += studarr[i].cgpa;

    return avgCGPA / (*no_studs);
}

int main()
{
    struct Student_Record studarr[MAX];

    int no_studs = 0;

    populateRecords(studarr, &no_studs);
    storeEmailAddresses(studarr, &no_studs);
    printRecord(studarr, &no_studs);
    printf("\nAvergae CGPA = %.2lf\n\n", calculateAvgCGPA(studarr, &no_studs));

    return 0;
}
