#include <stdio.h>

int main(void)
{

    // 看《C primer plus》P323
    char str_1[5] = "abcde";    // 不会自动在末尾添加 '\0'，不是字符串，是字符串数组
    char str_2[5] = "abcd";     // 会自动在末尾添加 '\0'，是字符串，未被使用的空间被初始化为'\0'。
    char str_3[] = "abcde";     // 会自动在末尾添加 '\0'，是字符串
    puts(str_1);                // 不会因为输出完str_1指向的整个数组而停下，而是会一直输出直到找到内存中的'\0'。
    puts(str_2);
    puts(str_3);
    printf("%d, %d, %d\n", sizeof(str_1), sizeof(str_2), sizeof(str_3));

    return 0;
}
