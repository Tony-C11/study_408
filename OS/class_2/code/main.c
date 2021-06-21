/* 读取命令（程序）输入 + 执行命令（程序） */
#include <stdio.h>

int main(int argv, char argc[])
{
    char cmd[20];
    while (1)
    {
        scanf("%s", cmd);
    	if (!fork) {exec(cmd);}
        else {wait();}
    }
}