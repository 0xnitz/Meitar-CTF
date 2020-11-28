#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define FLAG_LEN (20)

#define VALIDATE_COND(x)    \
        if (!(x))           \
            access_denied() \

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

    VALIDATE_COND(strncmp(flag, "MEITAR{", 7) == 0 && flag[19] == '}');

    VALIDATE_COND((flag[7] ^ 5) == 'g');
    VALIDATE_COND((flag[8] + 3 ^ 3) == '7');
    VALIDATE_COND((flag[9] ^ 20) == 'z');
    VALIDATE_COND(~flag[10] == -53);
    VALIDATE_COND((flag[11] * 3) == 342);
    VALIDATE_COND((flag[12] + 35) == 0x9c);
    VALIDATE_COND((flag[13] - 2) == 0135);
    VALIDATE_COND((flag[14] + 3 - 15) == 0b100101);
    VALIDATE_COND((flag[15] << 3) == 920);
    VALIDATE_COND(ror(flag[16], 3) == 235);
    VALIDATE_COND(~(ror(flag[17], 5) ^ 3 & 5) == -43);
    VALIDATE_COND((uint8_t)(~(ror(flag[18], 5) ^ 3 & 5)) == 45);

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
