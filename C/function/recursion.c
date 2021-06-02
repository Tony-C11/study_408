#include <stdio.h>

void recursionTest(int num)
{
    printf("Level %d\n", num);
    if (num < 4)
        recursionTest(num + 1);
    printf("Level %d\n", num);
    return ;
}

int main(void)
{
    recursionTest(1);
    return 0;
}
