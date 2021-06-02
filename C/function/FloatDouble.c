#include <stdio.h>

int test(int a, int b);

int main(void)
{
    printf("%d\n", test(1.0333, 2.0333));
    return 0;
}

int test(int a, int b)
{
    return a + b;
}
