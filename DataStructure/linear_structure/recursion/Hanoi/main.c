#include <stdio.h>
#include <stdlib.h>

typedef char column;

void Hanoi(int n, column A, column B, column C);

int main(void)
{
    column A = 'A', B = 'B', C = 'C';
    int n;
    printf("请输入盘子的数量：");
    scanf("%d", &n);
    Hanoi(n, A, B, C);
    return 0;
}

void Hanoi(int n, column A, column B, column C)
{
    if (0 == n)
    {
        printf("盘子数量不能为空！！！\n");
        exit(-1);
    }
    else if (1 == n)
    {
        printf("直接将编号为%d的盘子从柱子%c移动到柱子%c\n", n, A, C);
    }
    else
    {
        Hanoi(n - 1, A, C, B);
        printf("直接将编号为%d的盘子从柱子%c移动到柱子%c\n", n, A, C);
        Hanoi(n - 1, B, A, C);
    }

    return ;
}

// Hanoi递归的关键：柱子会“改变”，最初的柱子B在递归时可能会变成A。