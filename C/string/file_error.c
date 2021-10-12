#include <stdio.h>
#define SIZE    10

int main(void)
{
    fclose(stdin);
    char str[SIZE];
    if (fgets(str, SIZE, stdin) == NULL)
    {
        printf("error!\n");
    }
    else
        printf("OK!!\n");
    return 0;
}