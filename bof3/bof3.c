#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE (64)

void winner();
void bof();

int main(int argc, char **argv)
{
    bof();

    return 0;
}

void winner()
{
    system("cat flag.txt");
}

void bof()
{
    char buf[BUF_SIZE];
    gets(buf);
}
