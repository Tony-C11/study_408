#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct ArrayList
{
    int * ptr_addr;
    int index;
    // int count;
} Array;

Array * creatArray(int len);
void get_array_val(Array * ptr_array, int index);
void showArray(Array * ptr_array, int index);


int main(void)
{   
    Array A;
    Array * ptr_array = &A;
    printf("How many array do you want to creat? ");
    scanf("%d", &ptr_array->index);
    ptr_array = creatArray(ptr_array->index);
    get_array_val(ptr_array, ptr_array->index);
    showArray(ptr_array, ptr_array->index);

    return 0;
}

Array * creatArray(int len)
{
    Array * creat_array;
    creat_array->ptr_addr = (int *)malloc(sizeof(int) * len);
    return creat_array;
}

void get_array_val(Array * ptr_array, int index)
{
    for (int count = 0; count < index; ++ count)
    {
        ptr_array->ptr_addr[count] = 1;
    }

    return;
}

void showArray(Array * ptr_array, int index)
{
    for (int count = 0; count < index; ++ count)
    {
        printf("%d\n", ptr_array->ptr_addr[count]);
    }

    return;
}

/*

Array * creatArray(int len)
{
    Array * creat_array = (Array *)malloc(sizeof(Array) * len);
    return creat_array;
}

void get_array_val(Array * ptr_array, int index)
{
    for (int count = 0; count < index; ++ count)
    {
        ptr_array->ptr_addr[count] = 1;
    }

    return;
}

void showArray(Array * ptr_array, int index)
{
    for (int count = 0; count < index; ++ count)
    {
        printf("%d\n", ptr_array->ptr_addr[count]);
    }
    return;
}
*/
