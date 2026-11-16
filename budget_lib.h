#ifndef BUDGET_LIB_H
#define BUDGET_LIB_H

#define MAX_RECORDS 20
#define DESC_LEN 32

// 账单结构体
typedef struct {
    char desc[DESC_LEN];
    float amount;
    int is_income; // 1=收入，0=支出
} Record_t;

// 业务库：全部无printf/scanf，支持单元测试
// 添加一条记录；返回1成功，0数组已满
int budget_add_record(Record_t records[], int *count, const char *desc, float amount, int is_income);

// 获取统计结果：总收入、总支出、结余
void budget_get_summary(const Record_t records[], int count, float *total_income, float *total_expense, float *balance);

#endif

