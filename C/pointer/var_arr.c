#include <stdio.h>

int main(void)
{
    int row;
    int col;
    int rows;
    int cols;
    printf("请输入你想创建的数组的“行数”和“列数”：");
    scanf("%d%d", &rows, &cols);
    int arr[rows][cols];
    // 变长数组
    cols = 1000000;
    for (row = 0; row < rows; ++row)
        for(col = 0; col < cols; ++col)
        {
            arr[row][col] = 100;        
        }

    for (row = 0; row < rows; ++row)
    {    
        for(col = 0; col < cols; ++col)
        {
            printf("%d  ", arr[row][col]);
        }
        putchar('\n');
    }


    return 0;    
}
