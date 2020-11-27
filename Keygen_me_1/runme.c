#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define CHECK_CHAR(INP, IND, CHR) if(INP[IND] != CHR) exitFail(); IND++;

void exitFail(void){
    puts("Wrong flag");
    exit(1);
}

int main(int argc, char **argv){
    if(argc != 2){
        puts("Usage: runme <Flag>");
        exit(1);
    }

    char *input = argv[1];
    int checkIndex = 0;

    CHECK_CHAR(input, checkIndex, 'M');
    CHECK_CHAR(input, checkIndex, 'E');
    CHECK_CHAR(input, checkIndex, 'I');
    CHECK_CHAR(input, checkIndex, 'T');
    CHECK_CHAR(input, checkIndex, 'A');
    CHECK_CHAR(input, checkIndex, 'R');
    CHECK_CHAR(input, checkIndex, '{');
    CHECK_CHAR(input, checkIndex, 'R');
    CHECK_CHAR(input, checkIndex, '3');
    CHECK_CHAR(input, checkIndex, '_');
    CHECK_CHAR(input, checkIndex, '1');
    CHECK_CHAR(input, checkIndex, '3');
    CHECK_CHAR(input, checkIndex, '_');
    CHECK_CHAR(input, checkIndex, 'F');
    CHECK_CHAR(input, checkIndex, 'u');
    CHECK_CHAR(input, checkIndex, 'N');
    CHECK_CHAR(input, checkIndex, '}');

    // Check end of flag
    CHECK_CHAR(input, checkIndex, '\00');
    
    puts("Correct flag");

    return 0;
}
