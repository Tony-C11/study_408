// 接收字符串、拼接、复制、比较（排序字符串）
#include <stdio.h>
#include <string.h>

#define SIZE    50
#define LEN     20

void s_gets(char * str, int len);
void sort_str(char * pStr[], int num);
// 等价于：void sort_str(char ** pStr, int num)

int main(void)
{
    char str1[SIZE];
    char str2[LEN];
    char str3[SIZE];
    printf("请输入一个字符串：");
    s_gets(str1, SIZE);
    printf("你输入的字符串是：%s\n", str1);
    
    printf("请输入一个字符串：");
    s_gets(str2, LEN);
    printf("你输入的字符串是：%s\n", str2);
    
    strncat(str1, str2, SIZE - strlen(str1) - 1); 
    // 留一个字符空间来存储 '\0'
    printf("拼接完的字符串为：");
    puts(str1);
    
    //puts(&str1[30]);
    printf("向str3中放一份str1的拷贝，str3中的数据为：");
    puts(strncpy(str3, str1, SIZE));

    char * pStr[5] = {str1, str2, str3, "asdsds", "sdssdfggf"};
    puts("排序字符串：");
    
    sort_str(pStr, 5);
    // 排序的是指针，不是字符串数组
    int count;
    for (count = 0; count < 5; ++count)
    {
        puts(pStr[count]);
    }

    char str_finally[100];
    sprintf(str_finally, "%s, %s, %s: %d, %f", pStr[0], pStr[3], pStr[4], 5, 5.5555);
    puts(str_finally);
    return 0;
}


/*
 * 接受字符串输入
 *
 * */
void s_gets(char * str, int len)
{
    int count = 0;
    fgets(str, len, stdin);
    while (str[count] != '\n' && str[count] != '\0')
        count++;
    if (str[count] == '\n')
        str[count] = '\0';
    // 为达到最大输入就换行，将换行符转换为'\0'
    else
        while (getchar() != '\n')
            continue;
        // 接收到最大输入，仍然没有结束输入，消除'\0'后的所有字符，防止这些字符残留在缓冲区内，影响下一次输入

    return ;
}

void sort_str(char * pStr[], int num)
{
    char * temp;
    int i, j;
    
    // 选择排序算法
    for (i = 0; i < num - 1; ++i)
        for (j = i + 1; j < num; ++j)
        {
            if (strcmp(pStr[i], pStr[j]) > 0)
            {
                temp = pStr[i];
                pStr[i] = pStr[j];
                pStr[j] = temp;
            }
        }
    return ;
}
