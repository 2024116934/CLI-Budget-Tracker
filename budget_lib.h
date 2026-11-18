#ifndef BUDGET_LIB_H
#define BUDGET_LIB_H

#define MAX_RECORDS 20
#define DESC_LEN 64

typedef enum {
    STATE_MENU,
    STATE_ADD_RECORD,
    STATE_VIEW_RECORDS,
    STATE_SAVE,
    STATE_LOAD,
    STATE_EXIT
} AppState;

typedef struct {
    char description[DESC_LEN];
    double amount;
    int is_income; // 1 = income, 0 = expense
} Transaction;

void add_record(Transaction list[], int *count);
void view_records(Transaction list[], int count);
double calculate_balance(Transaction list[], int count);

#include "file_io.h"

#endif
