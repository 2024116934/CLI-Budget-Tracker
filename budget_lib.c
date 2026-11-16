#include "budget_lib.h"
#include <string.h>

int budget_add_record(Record_t records[], int *count, const char *desc, float amount, int is_income)
{
    if (*count >= MAX_RECORDS)
    {
        return 0;
    }
    strncpy(records[*count].desc, desc, DESC_LEN -1);
    records[*count].desc[DESC_LEN-1] = '\0';
    records[*count].amount = amount;
    records[*count].is_income = is_income;
    (*count)++;
    return 1;
}

void budget_get_summary(const Record_t records[], int count, float *total_income, float *total_expense, float *balance)
{
    *total_income = 0.0f;
    *total_expense = 0.0f;
    for(int i = 0; i < count; i++)
    {
        if(records[i].is_income == 1)
        {
            *total_income += records[i].amount;
        }
        else
        {
            *total_expense += records[i].amount;
        }
    }
    *balance = *total_income - *total_expense;
}
