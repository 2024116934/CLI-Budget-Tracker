#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <stdio.h>

// 读取一行字符串，清除换行符
void read_line(char *buf, int buf_len);
// 读取合法数字，失败返回0
int read_double(double *out_val);
// 读取整数选择
int read_int(int *out_val);

#endif
