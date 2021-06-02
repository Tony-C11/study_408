#include <stdio.h>

long Factorial(int num);

int main(void)
{
    printf("%ld\n", Factorial(6));
    return 0;
}

long Factorial(int num)
{
    long result;
    if (num > 0)
    {
        result = num * Factorial(num - 1);
    }
    else
    {
        result = 1;
    }

    return result;
}
