#include <stdio.h>

int main(void)
{
    int num1 = 0;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num2 = 10;

    array[-1] = -1;
    array[11] = 100;
    printf("num1 = %d, &num1 = %p\n", num1, &num1);
    printf("num2 = %d, &num2 = %p\n", num2, &num2);
    printf("&array[-1] = %p\n", &array[-1]);
    printf("&array[10] = %p\n", &array[10]);
    
    return 0;
}
