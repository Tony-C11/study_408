## 输入/输出字符和文件操作

### 重定位

在Linux中，一切皆是文件，I/O设备是 输入/输出 文件，键盘输入字符，就是在打开输入文件进行操作的过程。

C程序通过**流**来进行文件操作，**流**是对实际文件的映射。

重定位就是用其他文件来代替I/O文件，以达到输入、输出的效果

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
命令行输入有缓冲区，这就导致使用scanf()、getchar()等函数时输入的换行符可能会给程序带来不必要的麻烦，因此，当我们在循环读取单个字符的输入时，需要写一个while()语句来清除多余的输入，**尤其是换行符**。
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

scanf()在输入数值时，不考虑空白符号，但如果用scanf()输入数值后，换行符仍会残留在缓冲区中，接下来如果有用getchar()或者用scanf()（输入字符时会有影响，如果是输入数值，并不会有设么影响，空白符会被忽略），这个换行符会影响程序的结果，这个时候，就需要使用while()来消除这个换行符或者在用scanf()输入字符时在%c之前添加一个空格。

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
2. 对于scanf("%d", num)来说，如果输入值是字符，则会将一个垃圾值赋给num，（如果这个放在while (scanf("%d", &num)) printf("xx")中，输入字符会导致预料外的问题，因为字符一旦没被处理，每次迭代时都会使用这个字符），如果输入的是浮点数，会将小数点前的数据赋给num，将小数点作为字符放置到缓存区，小数点后的数据将被清除。
3. scanf()接收到的键盘输入其实都是字符，但会根据格式化符号将字符转化成相应格式的数据。


## 第九章 函数
> 输入（参数） $\rightarrow$ （函数）处理 $\rightarrow$ 输出返回值
### 为什么需要函数
1. 让程序**模块化**
2. 提高程序的可读性
3. 能重复调用一个功能，并不需要每次使用这个功能时才编写（这样太费事儿）

### 函数的使用
1. 函数声明（函数原型）
2. 函数定义
3. 调用函数

> 注意事项：要想正确地使用函数，在使用前必须知道被调函数的类型（返回值的类型），函数的类型由函数声明来告知编译器，被调函数的声明必须放在使用该函数之前，可以放在主调函数的外面，也可以放在主调函数的里面，例如：
```C
        int main(void)
        {   ...
            int functionA(int, int);
            functionA(1, 2);
            ...
        }
```
    
> 被编译器报警告的例子：
```C
    // #include <stdio.h>
    void print(void)
    {
    //    #include <stdio.h>
        print1();
    }
    void print1(void)
    {
        printf("HelloWorld!\n");
    }
    int main(void)
    {
        #include <stdio.h>
        print();
        return 0;
    }
```

![函数声明的位置](img/函数声明的位置.png)
> [隐式声明](https://blog.csdn.net/smstong/article/details/50523120)



### 声明一个函数
返回值 函数名(参数)

```C
int functionA(int a, int b);
// 定义形式参数时可以省略变量名
// int functionA(int , int );
```

#### 参数
1. 实际参数可以是 变量、常量、表达式（在求值后复制给形式参数）。
2. 如果函数原型中有参数，在声明函数时，并不会为参数分配空间，只有在调用该函数时，才会声明变量并初始化为实际参数的值。
> 实现原理：调用被调函数$B$时，主调函数$A$将实际参数以**函数声明时的数据类型**压入栈中，控制权转交给被调函数。
```C
    #include <stdio.h>
\\
    int test(int a, int b);
\\
    int main(void)
    {
        printf("%d\n", test(1.0333, 2.0333));
        return 0;
    }
\\
    int test(int a, int b)
    {
        return a + b;
    }
```


#### return
1. 向主调函数返回一个值
2. 终止被调函数并把控制权转交给主调函数的下一条语句
3. “return ; ”$\rightarrow$   用于没有返回值为void类型的函数

### 额外的记录
使用函数原型时指定参数与不指定参数：
1. 不指定参数带来的弊端：
```C
#include <stdio.h>
\\
int test();
\\
int main(void)
{
    printf("%d\n", test(1));
    return 0;
}
\\
int test(int a, int b)
{
    return a + b;
}
```
输出一个垃圾值：因为会使用栈中其他位置的数值作为第二个参数进行计算。

2. 指定参数的数量、类型后，编译器能：
    1. 查询实际参数与形式参数的个数是否匹配
    2. 如果实际参数的类型与形式参数不同，那么会将实际参数的类型转换为形式参数的类型并赋给形式参数 
