#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE (64)
#define FLAG_SIZE (128)

struct file
{
    char buf[BUF_SIZE];
    char fd;
} typedef file;

void win(void){
    int fd = open("flag.txt", O_RDONLY);
    char buffer[FLAG_SIZE];
    int r = read(fd, buffer, FLAG_SIZE);
    
    *(buffer + r) = 0;

    printf("%s\n", buffer);
}

int main(int argc, char **argv)
{
    puts("My little notepad");
    puts("-----------------\n");

    file f1;

    puts("user1 - Enter note to save:");
    f1.fd = open("user1.txt", O_RDONLY);

    fgets(f1.buf, BUF_SIZE + 2, stdin);

    char verifyBuff[BUF_SIZE];
    read(f1.fd, verifyBuff, BUF_SIZE + 2);

    if (strncmp("admin", verifyBuff, 5) == 0) {
        win();
    }
    else {
        printf("Note saved\n");
    }

    return 0;
}
