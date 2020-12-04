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

void generate_file_name_by_user(int userId, char *buffer, int bufferSize){
    snprintf(buffer, bufferSize, "user%d.txt", userId);
}

void escape(void){
    puts("Nice try!\nMy program is unbreachable :D");
    _exit(1);
}

void initialize_database(int *arr, int arrSize, int numOfRegularUsers){
    // initialize guests

    char fileName[32];
    int i;

    for (i = 0; i < numOfRegularUsers; i++)
    {
        generate_file_name_by_user(i + 1, fileName, 32);
        arr[i] = open(fileName, O_RDONLY);
    }
    
    // initialize admin
    arr[i++] = open("admin.txt", O_RDONLY);
}

void check_buffer_valid(char *buffer){
    // Checks that all charecters are alphanumeric or space/newline

    for(char *ptr = buffer; *ptr != '\00'; ptr++){
        if( !(  (*ptr >= 'a' && *ptr <= 'z') ||
                (*ptr >= 'A' && *ptr <= 'Z') ||
                (*ptr >= '0' && *ptr <= '9') ||
                *ptr == ' ' ||
                *ptr == '\n')){
            escape();
        }
    }
}

int count_users(){
    char answer[16];

    FILE *fp = popen("ls user*.txt -1 | wc -l", "r");
    fread(answer, 16, 1, fp);

    int number = atoi(answer);

    return number;
}

int register_new_user(int currentGuests){
    char buffer[32];

    snprintf(buffer, 32, "user%d.txt", currentGuests + 1);

    int fd = open(buffer, O_RDWR | O_CREAT);
    write(fd, "guest", strlen("guest"));
    chmod(buffer, (mode_t)0444);
    close(fd);

    return currentGuests + 1;
}

void register_accounts(int currentUsers){
    char answer[16];

    fgets(answer, 16, stdin);
    int num = atoi(answer);
    
    if(num < 0 || num > 100){
        escape();
    }

    for (int i = 0; i < num; i++)
    {
        currentUsers = register_new_user(currentUsers);
    }
}

int main(int argc, char **argv)
{
    system("rm -f user*.txt");
    register_new_user(0);

    const int MAX_USERS = 100;
    int numOfUsers;
    int fds[MAX_USERS];

    puts("My little notepad 2.0");
    puts("-----------------\n");

    puts("How many new users you want to register? (0 - 100)");
    register_accounts(1);
    puts("");

    // Counter guests and add the Admin
    numOfUsers = count_users() + 1;

    initialize_database(fds, numOfUsers, numOfUsers - 1);

    file f1;

    puts("user1 - Enter note to save:");
    f1.fd = open("user1.txt", O_RDONLY);

    fgets(f1.buf, BUF_SIZE + 2, stdin);

    check_buffer_valid(f1.buf);

    if(f1.fd >= 0 && f1.fd <= 3){
        escape();
    }

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
