#ifndef FILE_IO_H
#define FILE_IO_H
#include "budget_lib.h"

// 保存所有记录到txt文件
int save_records(const char *filename, Transaction list[], int count);
// 从txt加载记录
int load_records(const char *filename, Transaction list[], int *count);

#endif
