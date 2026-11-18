#include "file_io.h"
#include <stdio.h>

int save_records(const char *filename, Transaction list[], int count)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Failed to open file for writing!\n");
        return 0;
    }
    for(int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %.2lf %d\n", list[i].description, list[i].amount, list[i].is_income);
    }
    fclose(fp);
    printf("Saved successfully to %s\n", filename);
    return 1;
}

int load_records(const char *filename, Transaction list[], int *count)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not found, nothing loaded!\n");
        return 0;
    }
    *count = 0;
    while((*count < MAX_RECORDS) && fscanf(fp, "%s %lf %d",
        list[*count].description,
        &list[*count].amount,
        &list[*count].is_income) == 3)
    {
        (*count)++;
    }
    fclose(fp);
    printf("Loaded %d records from %s\n", *count, filename);
    return 1;
}
