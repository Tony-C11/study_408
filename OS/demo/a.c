#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

static char buffer[100];

int main(void)
{
    // while (1)
    {
        int rc = fork();

        if (rc < 0)
        {
        }
        else if (rc == 0)
        {
            while (getchar() != '\n')
                continue;
            scanf("%s", buffer);
            while (getchar() != '\n')
                continue;
        }
        else 
        {
            printf("linux > \n");
        //    wait(NULL);
        }
            
    }


    return 0;
}
