#include <stdio.h>
int main(void)
{
    int a = 20;
    int * ptrInt = &a;
    double i = 3.1415926;
    ptrInt = &i;
    printf("%p, %p, %d, %d, %lf\n", &i, ptrInt, sizeof(*ptrInt), *ptrInt, *ptrInt);
    return 0;
}
