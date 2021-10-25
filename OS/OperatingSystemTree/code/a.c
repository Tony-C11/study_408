#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    if (!fork())    // fork_A
    {
        while (1)
        {
            printf("A");
        }
    }

    if (!fork())    // fork_B
    {
        while (1)
        {
            printf("B");
        }
            
    }
    wait();

    return 0;
}
