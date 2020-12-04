#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE (64)

int main()
{
    FILE *file = fopen("flag.txt", "r");
    char flag[BUF_SIZE];
    fgets(flag, BUF_SIZE, (FILE*)file);

    char a[BUF_SIZE] = "";
    read(0, a, BUF_SIZE);

    printf(a);

    return 0;
}