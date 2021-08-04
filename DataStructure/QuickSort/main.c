#include <stdio.h>

void QuickSort(int * pArr, int low, int high);
int FindPos(int * pArr, int low, int high);

int main(void)
{
    int array[10] = {12, 3, 4, 45, 6, 8, 9, 23, 1, 0}; 
    QuickSort(array, 0, 9);
    for (int index = 0; index < 10; ++index)
    {
        printf("%d  ", array[index]);
    }

    printf("\n");
    
    return 0;
}

void QuickSort(int * pArr, int low, int high)
{
    if (low < high)
    {
        int pos = FindPos(pArr, low, high);
        QuickSort(pArr, low, pos - 1);
        QuickSort(pArr, pos + 1, high);
    }
    return ;
}

int FindPos(int * pArr, int low, int high)
{
    int val = pArr[low];
    while (low < high)
    {
        while (pArr[high] >= val && low < high)
            high--;
        pArr[low] = pArr[high];

        while (pArr[low] <= val && low < high)
            low++;
        pArr[high] = pArr[low];
    }
    /* while ()
    {
        ...
    } 结束后，low == high;
    */
    pArr[low] = val;
    return high;
}





