#include "budget_lib.h"
#include "input_utils.h"
#include <stdio.h>
#include <string.h>

void add_record(Transaction list[], int *count)
{
    if (*count >= MAX_RECORDS)
    {
        printf("Record list full, cannot add more!\n");
        return;
    }

    char desc[DESC_LEN];
    double amount;
    int is_income;

    printf("\nEnter description: ");
    read_line(desc, DESC_LEN);

    printf("Enter amount: ");
    if (!read_double(&amount) || amount <= 0)
    {
        printf("Invalid amount, must be positive!\n");
        return;
    }

    printf("1 = Income, 0 = Expense: ");
    if (!read_int(&is_income) || (is_income != 0 && is_income != 1))
    {
        printf("Invalid choice!\n");
        return;
    }

    strncpy(list[*count].description, desc, DESC_LEN-1);
    list[*count].amount = amount;
    list[*count].is_income = is_income;
    (*count)++;
    printf("Record added successfully!\n");
}

void view_records(Transaction list[], int count)
{
    printf("\n==== Record List ====\n");
    if (count == 0)
    {
        printf("No records yet.\n");
        return;
    }
    for(int i = 0; i < count; i++)
    {
        char type[10];
        if (list[i].is_income == 1)
            strcpy(type, "Income");
        else
            strcpy(type, "Expense");
        printf("[%d] %s | %.2f | %s\n", i+1, list[i].description, list[i].amount, type);
    }
    double bal = calculate_balance(list, count);
    printf("Current balance: %.2f\n", bal);
}

double calculate_balance(Transaction list[], int count)
{
    double sum = 0.0;
    for(int i = 0; i < count; i++)
    {
        if (list[i].is_income == 1)
            sum += list[i].amount;
        else
            sum -= list[i].amount;
    }
    return sum;
}
