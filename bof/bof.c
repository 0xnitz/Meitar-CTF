#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE (64)

void main()
{
    int winner = 0;
    char buf[BUF_SIZE];

    gets(buf);

    if (winner != 0) {  
        system("cat flag.txt");
    }
}