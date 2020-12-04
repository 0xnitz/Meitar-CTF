# input_output

```c
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
```

We need to somehow enter some input to get the right num, the flag.

Reading about read() tells us it takes in something called a file descriptor.
Linux works with file descriptors to handle open files, the default file descriptor for input, stdin is 0, lets try that

0xc0de ^ 5 = 49371

```bash
./fd 49371
EZPEEZY
```

**MEITAR{49371}**