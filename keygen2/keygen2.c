#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define FLAG_LEN (20)

void access_denied();
uint8_t ror(int8_t num, int8_t x);

void main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <flag, %d chars>\n", argv[0], FLAG_LEN);
        exit(1);
    }
    else if (strlen(argv[1]) != FLAG_LEN) {
        printf("Usage: %s <flag, %d chars>\n", argv[0], FLAG_LEN);
        exit(1);
    }

    char *flag = argv[1];

    if (strncmp(flag, "MEITAR{", 7) != 0) {
        access_denied();
    }
    
    if ((flag[7] ^ 5) != 'g') {
        access_denied();
    }

    if ((flag[8] | 3) != '3') {
        access_denied();
    }

    if ((flag[9] & 13) != 12) {
        access_denied();
    }

    if (~flag[10] != -53) {
        access_denied();
    }

    if ((flag[11] * 3) != 342) {
        access_denied();
    }

    if ((flag[12] + 35) != 0x9c) {
        access_denied();
    }

    if ((flag[13] - 2) != 0135) {
        access_denied();
    }

    if ((flag[14] + 3 - 15) != 0b100101) {
        access_denied();
    }

    if ((flag[15] << 3) != 920) {
        access_denied();
    }

    if (ror(flag[16], 3) != 235) {
        access_denied();
    }

    if (~(ror(flag[17], 5) ^ 3 & 5) != -43) {
        access_denied();
    }

    if ((uint8_t)(~(ror(flag[18], 5) ^ 3 & 5)) != 45) {
        access_denied();
    }

    printf("Access Granted!\n");
    exit(0);
}

void access_denied()
{
    printf("Acess Denied!\n");
    exit(1);
}

uint8_t ror(int8_t num, int8_t x) 
{
    return (num >> x)|(num << (8 - x));
}
