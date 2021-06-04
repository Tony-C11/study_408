#include <stdio.h>

#define SIZE    5

void show_arr(const int * ptr);

int main(void)
{
    int arr[SIZE] = {1, 2, 3, 4, 5};
    show_arr(arr);
    const int num = 5;
    const int * ptr1 = &num;
    int * ptr2 = &num;
    printf("%d, %d\n", *ptr2, *ptr1);
    *ptr2 = 1;
    printf("%d, %d\n", *ptr2, *ptr1);
    return 0;
}

void show_arr(const int * ptr)
{
    ptr[3] = 9;
    return ;
}
