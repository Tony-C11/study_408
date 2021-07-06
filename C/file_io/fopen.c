// 拷贝一份文件数据，将参数1拷贝到新文件中（以.c结尾），不覆盖参数2原来的数据
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME    20
#define INFO    1000
int main(int argc, char * argv[])
{
    FILE * fp1;
    FILE * fp2;
    unsigned long count = 0;
    char ch;
    char file[NAME];
    char newFile[INFO];

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "We can't open this %s!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // 做一个副本，以 .c做后缀
    strncpy(file, argv[1], NAME - 3);
    file[NAME - 4] = '\0';
    // 如果源文件名字太长，拷贝到file[NAME-4]的位置也没拷贝完，就在file[NAME-4]的位置添加一个'\0'，因为strcat()从第一个空字符开始拼接。
    if ((fp2 = fopen(strcat(file, ".c"), "a+")) == NULL)
    {
        fprintf(stderr, "We can't creat the new file!\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp1)) != EOF)
    {
        putc(ch, fp2);
        putc(ch, stdout);   
        count++;
    }
    
    printf("%s has %d characters!!!\n", argv[1], count);
    puts("在新文件中的信息是：");
    // while (getc)
    // 此时已经到了源文件和新文件的末尾
    rewind(fp2);   // 重新定位到文件开头
    while (fgets(newFile, INFO, fp2) != NULL)   // 读到文件结尾返回NULL
    {
        fputs(newFile, stdout);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}





