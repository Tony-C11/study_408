#include <stdio.h>

#define SIZE    5

void show_arr(const int * ptr);

int main(void)
{
    int arr[SIZE] = {1, 2, 3, 4, 5};
    return 0;
}

void show_arr(const int * ptr)
{
    ptr[3] = 9;
    return ;
}
