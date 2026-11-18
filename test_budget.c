#include <stdio.h>
#include <math.h>
#include "budget_lib.h"

// 测试余额计算
void test_calculate_balance()
{
    Transaction test_data[4] = {
        {"Salary", 2000, 1},
        {"Rent", 800, 0},
        {"Food", 300, 0},
        {"Bonus", 500, 1}
    };
    double res = calculate_balance(test_data, 4);
    if(fabs(res - 1400.0) < 0.01)
        printf("PASS: test_calculate_balance\n");
    else
        printf("FAIL: test_calculate_balance, got %.2f\n", res);
}

// 测试空列表余额
void test_empty_balance()
{
    Transaction empty[10];
    double res = calculate_balance(empty, 0);
    if(fabs(res - 0.0) < 0.01)
        printf("PASS: test_empty_balance\n");
    else
        printf("FAIL: test_empty_balance, got %.2f\n", res);
}

int main()
{
    printf("==== Running Unit Tests ====\n");
    test_calculate_balance();
    test_empty_balance();
    printf("==== Test finished ====\n");
    return 0;
}
