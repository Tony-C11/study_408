#include <stdio.h>

int test();

int main(void)
{
    printf("%d\n", test(1));
    return 0;
}

int test(int a, int b)
{
    return a + b;
}
