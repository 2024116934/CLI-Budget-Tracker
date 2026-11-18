#ifndef FILE_IO_H
#define FILE_IO_H
#include "budget_lib.h"

int save_records(const char *filename, Transaction list[], int count);
int load_records(const char *filename, Transaction list[], int *count);

#endif
