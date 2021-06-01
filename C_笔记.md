## 输入/输出字符和文件操作

### 重定位

在Linux中，一切皆是文件，I/O设备是 输入/输出 文件，键盘输入字符，就是在打开输入文件进行操作的过程。

C程序通过**流**来进行文件操作，**流**是对实际文件的映射。

重定向就是用其他文件来代替I/O文件，以达到输入、输出的效果

```shell
$ ./prog > 1.txt
----将程序的输出输到1.txt中


$ ./prog < 1.txt
----将1.txt中的文本内容当作对程序的输入


$ ./prog < 1.txt > 2.txt
----将1.txt中的文本内容当作对程序的输入，程序的输出输到2.txt中

```

> 注意事项：
1. 重定向符号只能连接文件和程序
2. 重定向符号不能同时将多个文件输入到一个程序中，也不能把输出重定向到多个文件


### 缓冲区
命令行输入有缓冲区，这就导致使用scnaf()、getchar()等函数时输入的换行符可能会给程序带来不必要的麻烦，因此，当我们在循环读取单个字符的输入时，需要写一个while()语句来清除多余的输入，**尤其是换行符**。
```C
#include <stdio.h>

int main(void)
{
    char ch;
    int guess = 1;
    printf("%d?\n", guess);
    while ((ch = getchar()) != 'y' && guess <= 100)
    {
        while (getchar() != '\n')
            continue;
        if ('n' == ch)
            printf("Is it %d?\n", ++guess);
        else
            printf("Sorry, I can't understand your mean, please input again: ");
    } 
    printf("OK, I'm right!\n");
    return 0;
}
```

scanf()在输入数值时，不考虑空白符号，但如果用scanf()输入数值后，换行符仍会残留在缓冲区中，接下来如果有用getchar()或者用scanf()，这个换行符会影响程序的结果，这个时候，就需要使用while()来消除这个换行符或者在用scanf()输入字符时在%c之前添加一个空格。

示例：
```C
#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);
    char ch;
    scanf(" %c", &ch);
    printf("%d, %c呵呵\n", num, ch);
    return 0;
}
```

### scanf()的一些问题：

1. scanf()在接收到预期的格式化输入后，会返回1（有几个接收就返回多少）。
2. 对于scanf("%d", num)来说，如果输入值是字符，则会将一个垃圾值赋给num，如果输入的是浮点数，会将小数点前的数据赋给num，将小数点作为字符放置到缓存区，小数点后的数据将被清除。
3. scanf()接收到的键盘输入其实都是字符，但会根据格式化符号将字符转化成相应格式的数据。










