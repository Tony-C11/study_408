#include <stdio.h>

#define STR_SIZE    10

typedef struct string
{
    char elem[STR_SIZE];
    int length;
} String;

int BF(const String * pString1, const String * pString2);
String initString(void);
void getString(String * pString);

int main(void)
{
    String str_1 = initString();    
    printf("请输入主串：");
    getString(&str_1);
    puts(str_1.elem);
    printf("主串长度为：%d\n", str_1.length);
    String str_2 = initString();    
    printf("请输入子串：");
    getString(&str_2);
    puts(str_2.elem);
    printf("子串长度为：%d\n", str_2.length);


    printf("子串的位置是：%d\n", BF(&str_1, &str_2));
    
    

    return 0;
}


String initString(void)
{
    String str;
    str.elem[0] = ' ';
    str.length = 0;
    return str;
}

void getString(String * pString)
{
    int count = 1;
    pString->elem[count] = getchar();
    while ( (pString->elem[count] !='\n') && (count < STR_SIZE - 1) )
    {
        pString->length++;
        count++;
        pString->elem[count] = getchar();
        // 当输入满了的时候，并不会将最后一位计入字符串长度，接下来还会将pString->elem[STR_SIZE]记为'\0'。
    }

    if (pString->elem[count] == '\n')
    {
        pString->elem[count] = '\0';
    }
    else
    {
        while (getchar() != '\n')
            continue;
        pString->elem[count] = '\0';    // 结合puts()联想为什么需要这条语句
    }

    return ;
}

// https://www.bilibili.com/video/BV1nJ411V7bd?p=66 -> 这个算法的时间复杂度计算在最后几分钟。
// 时间复杂度：O(m*n)
int BF(const String * pString1, const String * pString2)
{
    int index_1, index_2; // index_1为主串下标，index_2为子串下标
    index_1 = index_2 = 1;

    // 其实length是最后一个数组元素的下标！！！其实也是数组的长度，因为我们没有使用elem[0]来存储元素
    // 如果我们从下标为0就开始存数了，那么这里我们需要把length换成length-1！！！或者将<=改成<，而且回溯也应改为index_1 = index_1 - index_2 + 1
    while ( (index_1 <= pString1->length) && (index_2 <= pString2->length) )
    {
        if (pString1->elem[index_1] == pString2->elem[index_2])
        {
            index_1++;
            index_2++;
        }
        else    // 发现不相等，就回溯。
        {
            index_1 = index_1 - index_2 + 1 + 1;
            index_2 = 1;
        }
    }

    if (index_2 == (pString2->length + 1))
    {
        printf("匹配成功\n");
        return index_1 - pString2->length;
    }
    else
    {
        printf("匹配不成功\n");
        return -1;
    }
}
