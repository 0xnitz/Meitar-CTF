#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE (64)

int main(int argc, char **argv)
{   
    if (argc != 2) {
        printf("Usage: %s number", argv[0]);
        exit(1);
    }

    char buf[BUF_SIZE];

    printf("Can you get the hang of this?\n");

    int num = atoi(argv[1]) - (0xc0de ^ 5);
    printf("%d\n", num);
    read(num, buf, BUF_SIZE);

    if (strncmp("EZPEEZY", buf, 7) == 0) {
        printf("Congratz! now you can use num as your flag!\n");
    }
    else {
        printf("Sorry!\n");
    }

    return 0;
}
