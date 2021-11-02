#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{

    while (1)
    {
        int rc = fork();
        if (rc == 0)
        {
            char cmd[100];
            scanf("%s", cmd);
        }
        printf("Linux> ");
        wait(NULL);
        printf("pid = %d\n", getpid());
    }

    return 0;
}
