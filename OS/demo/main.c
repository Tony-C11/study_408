// 伪代码

/* 读取命令（程序）输入 + 执行命令（程序） */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argv, char argc[])
{
    char cmd[20];
    while (1)
    {
        scanf("%s", cmd);
        // 对键盘进行使用
        
    	if (!fork()) 
        {
            // execl(cmd);
        }
        // 对CPU进行使用
        
        else 
        {
            printf("Linux> ");
            wait(NULL);
        }
    }
}
