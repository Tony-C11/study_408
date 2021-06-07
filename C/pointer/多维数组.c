#include <stdio.h>

int main(void)
{
    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int (* ptr)[3] = arr;
    
    int rows, cols;
    for (rows = 0; rows < 2; ++rows)
    {
        for (cols = 0; cols < 3; ++cols)
        {
            printf("%d  ", ptr[rows][cols]);
        }
        putchar('\n');
    }
    
    scanf("%d", arr);

    printf("**arr = %d\n &arr[0][0] = \t%p\n *arr = \t%p\n arr = \t\t%p\n", **arr, &arr[0][0], *arr, arr);

    return 0;
}
