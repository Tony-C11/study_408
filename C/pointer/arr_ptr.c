#include <stdio.h>
#define WIDTH   5
int sum(int arr[], int n);

int main(void)
{
    int array[WIDTH] = {1, 2, 3, 4, 5};
    int answer = sum(array, WIDTH);
    printf("The size of array is %zd.\n", sizeof array);
    // sizeof array 输出数组的长度
    printf("The total number of array is %d.\n", answer);

    return 0;
}

int sum(int arr[], int n)
{
    int count;
    int num = 0;
    for (count = 0; count < n; ++count)
    {
        num = num + arr[count];
    }

    printf("The size of arr in function sum() is %zd, so the arr is a pointer, not a array!\n", sizeof arr);

    return num;
}
