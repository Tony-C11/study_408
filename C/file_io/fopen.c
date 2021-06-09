#include <stdio.h>

int main(int argc, char * argv[])
{
    printf("There're %d arguments!\n", argc - 1);
    int count = 1;
    if (argc - 1 == 0)
        printf("No argument!!!\n");
    else
        while (count < argc)
        {
            puts(argv[count]);
            count++;
        }
    
    return 0;
}
