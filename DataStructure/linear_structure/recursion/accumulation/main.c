#include <stdio.h>

int accumulation(int i)
{
    if (1==i)
        return 1;
    else
        return i + accumulation(i - 1);
}

int main(void)
{
    printf("%d\n", accumulation(100000));
    return 0;
}