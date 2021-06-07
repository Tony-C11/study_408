#include <stdio.h>

#define STRING  "Hello, my name is Tony!"
#define INDEX   40
int main(void)
{
    char * ptr_str = "Hello, my name is Tony!";
    char string[] = "Hello, my name is Tony!";  
    printf("         %p\n", "Hello, my name is Tony!"); // “”  中的内容返回一个地址
    printf("%c, %p\n", *("Hello, my name is Tony!" + 1), "Hello, my name is Tony!" + 1);
    printf("         %p\n", STRING);
    printf("ptr =    %p\n", ptr_str);
    printf("string = %p\n", string);


    printf("*string = %c\n", *string);
    printf("*ptr =    %c\n", *ptr_str);

    // *(ptr_str + 1) = 'a';    // ptr_str指向字符串常量，不允许被更改，定义char类型指针指向字符串最好前面加上const限定符号。
    // puts(STRING);
    return 0;
}
