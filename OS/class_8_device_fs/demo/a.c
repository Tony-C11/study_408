#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char test[100];

    close(1);
    close(2);
    close(3);
    scanf("%s", test);
    printf("%s", test);
    return 0;
}
