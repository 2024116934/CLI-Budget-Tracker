#include "input_utils.h"
#include <string.h>

void read_line(char *buf, int buf_len)
{
    fgets(buf, buf_len, stdin);
    // 去掉末尾换行 \n
    size_t len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n')
    {
        buf[len-1] = '\0';
    }
}

int read_double(double *out_val)
{
    char temp[64];
    read_line(temp, sizeof(temp));
    if (sscanf(temp, "%lf", out_val) == 1)
    {
        return 1;
    }
    return 0;
}

int read_int(int *out_val)
{
    char temp[64];
    read_line(temp, sizeof(temp));
    if (sscanf(temp, "%d", out_val) == 1)
    {
        return 1;
    }
    return 0;
}
