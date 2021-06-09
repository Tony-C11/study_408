// 接收字符串、拼接、复制、比较（排序字符串）
#include <stdio.h>
#include <string.h>

#define SIZE    50
#define LEN     20

void s_gets(char * str, int len);

int main(void)
{
    char str1[SIZE];
    char str2[LEN];
    printf("请输入一个字符串：");
    s_gets(str1, SIZE);
    printf("你输入的字符串是：%s", str1);
    
    printf("请输入一个字符串：");
    s_gets(str2, LEN);
    printf("你输入的字符串是：%s", str2);
    
    return 0;
}

void s_gets(char * str, int len)
{
    int count = 0;
    fgets(str, len - 1, stdin);
    while (str[count] != '\n' && str[count] != '\0')
        count++;
    if (str[count] == '\n')
        count = '\0';
    else
        while (getchar() != '\n')
            continue;

    return ;
}
