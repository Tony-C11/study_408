#include <stdio.h> 

static int x = 0;
static int y = 0;

void thread_1(void)
{
    x = 100;
    printf("y = %d\n", y);
    return ;
}

void thread_2(void)
{
    y = 10;
    printf("x = %d\n", x);
    return ;
}

int main(void)
{
    thread_1();
    thread_2();
    return 0;
}
