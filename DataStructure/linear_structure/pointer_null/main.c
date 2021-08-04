#include <stdio.h>
#include <malloc.h>

void free_pointer(void);

int main(void)
{
    int i = 0;
    free_pointer();
    ++i;    // break
    --i;
    return 0;
}

void free_pointer(void)
{
    int * p = (int *)malloc(sizeof(int));

    free(p);    // break
    p = NULL;
    return ;    // break
}
