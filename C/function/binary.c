#include <stdio.h>

void translate_binary(int num);

int main(void)
{
    int num;
    printf("请输入你想打印的数字的十进制表示：");
    scanf("%d", &num);
    translate_binary(num);
    putchar('\n');
    return 0;
}

void translate_binary(int num)
{
    if (num >= 2)
    {
        translate_binary(num / 2);
    }
    /*
     *  5 -> 5/2 == 2 余 1
     *  2 -> 2/2 == 1 余 0
     *  1 -> 1/2 == 0 余 1
     * */

    printf("%d", num % 2);
}
