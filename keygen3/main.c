#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define KEY_SIZE 16

bool isKeyCharValid(char ch){
    return (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 70);
}

bool isKeyValid(char *key){
    if(strlen(key) != 16){
        return false;
    }

    for(char *p = key; *p != '\00'; p++){
        if(!isKeyCharValid(*p)){
            return false;
        }
    }

    return true;
}

bool lock1(char *key){
    const int MAX_OFFSET = 5;
    const int MIN_OFFSET = 2;
    int offset = MIN_OFFSET;

    for(char *ptr = key; *ptr != '\00'; ptr++){
        if(*ptr % offset != 0){
            return false;
        }

        if(++offset > MAX_OFFSET){
            offset = MIN_OFFSET;
        }
    }

    return true;
}

bool lock2(char *key){
    int valsIndex = 0;
    int x = 0;
    int y = 0;
    int val;

    for(int i = 0; i < 16; i += 2, valsIndex++){
        val = key[i] ^ key[i + 1];

        if(i < 8){
            x += val;
        }
        else{
            y += val;
        }
    }

    return y == x + 5;
}

bool lock3(char *key){
    int sum = 0;

    for(int i = 0; i < 16; i++){
        sum += key[i];
    }

    return sum % 7 == 0;
}

int main(int argc, char **argv){
    if(argc != 2){
        puts("You must provide a key");
        exit(1);
    }

    char *key = argv[1];

    if(!isKeyValid(key)){
        puts("Key is not in the right format");
        exit(1);
    }

    if( lock1(key) && 
        lock2(key) &&
        lock3(key) &&
        true){
            int fd = open("./flag.txt", O_RDONLY);
            char buffer[256];
            read(fd, buffer, 256);

            printf("%s", buffer);
    }
    else{
        puts("Product activation failed");
        exit(1);
    }

    return 0;
}
