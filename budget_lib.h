#ifndef BUDGET_LIB_H
#define BUDGET_LIB_H

#define MAX_RECORDS 20
#define DESC_LEN 32

// FSM 状态枚举
typedef enum {
    STATE_MENU,
    STATE_ADD_RECORD,
    STATE_VIEW_RECORDS,
    STATE_SAVE,
    STATE_LOAD,
    STATE_EXIT
} AppState;

// 交易结构体
typedef struct {
    char description[DESC_LEN];
    double amount;
    int is_income; // 1=收入，0=支出
} Transaction;

// 函数声明（空壳，Entry2再补实现）
void add_record(Transaction list[], int *count);
void view_records(Transaction list[], int count);
double calculate_balance(Transaction list[], int count);

#endif
