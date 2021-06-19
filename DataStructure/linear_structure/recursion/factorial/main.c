#include <stdio.h>

long factorial(long i)
{
    if (1==i)
        return 1;
    else
        return i * factorial(i-1);
}

int main(void)
{
    printf("%lu\n", factorial(20));
    return 0;
}