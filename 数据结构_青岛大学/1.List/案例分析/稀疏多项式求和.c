// 稀疏多项式如果像普通多项式一样，用数组下标来存储x的指数，就太浪费空间了（如：3x^2 + 6x^14）

/*
 * x ^ 2 + 9 * x ^ 5 + 3 * x ^ 9 
 * 1        9           3
 * 2        5           9
 *
 */

/*
 * 计算两个稀疏多项式(a, b)相加所得的多项式
 * 1. 创建一个新数组c用于存储最终的多项式
 * 2. 分别遍历多项式a、b
 *      1，指数相同的项，对应稀疏相加，相加结果存储在数组c中
 *      2，指数不相同，则将指数较小的一项存储在数组c中
 *  3. 如果有一个多项式遍历完毕，就将另外一个多项式的剩下几项依次复制到数组c中即可
 *
 *  两个稀疏多项式求和其实就是 用顺序存储合并两个有序表 的延伸。
 * */

#include <stdio.h>
#include <malloc.h>

#define MAXSIZE     10
typedef int IndexType;
typedef int CoefficientType;

typedef struct termType
{
    CoefficientType coefficient;
    IndexType index;
} TermType;

typedef struct polynome
{
    TermType * term;
    int len;
} Polynome;

Polynome creatPolynome(void);
void printPolynome(Polynome * p);
void getValue(Polynome * p, int amount);
Polynome add(Polynome * pFormA, Polynome * pFormB);

int main(void)
{
    Polynome formA = creatPolynome();
    getValue(&formA, 5);
    printPolynome(&formA);
    Polynome formB = creatPolynome();
    getValue(&formB, 5);
    printPolynome(&formB);
    Polynome formC = add(&formA, &formB);
    printPolynome(&formC);
    return 0;    
}

void printPolynome(Polynome * p)
{
    for (int count = 0; count < p->len; ++count)
    {
        printf("%d * x ^ %d", p->term[count].coefficient, p->term[count].index);
        if (count != p->len - 1)
            printf("    +   ");
    }
    putchar('\n');
    return ;
}

void getValue(Polynome * p, int amount)
{
    int count = 0;
    printf("请输入系数和指数的值：");
    while (scanf("%d %d", &p->term[count].coefficient, &p->term[count].index) == 2)
    {
        p->len++;
        count++;
        if (count == amount)  break;
        printf("请输入系数和指数的值：");
    }
    return ;
}

Polynome creatPolynome(void)
{
    Polynome form;
    form.term = (TermType *)malloc(sizeof(TermType) * MAXSIZE);
    form.len = 0;
    return form;
}

Polynome add(Polynome * pFormA, Polynome * pFormB)
{
    Polynome formC = creatPolynome();

    TermType * pC = formC.term;

    TermType * pA = pFormA->term;
    TermType * pATail = pFormA->term + pFormA->len - 1;
    // 设置指针，让指针分别指向式子A的首项和尾项
    // 特别要注意指针的类型必须和项的类型相同

    TermType * pB = pFormB->term;
    TermType * pBTail = pFormB->term + pFormB->len - 1;

    while ( (pA <= pATail) && (pB <= pBTail) )
    {
        if (pA->index <= pB->index)
        {
            if (pA->index == pB->index) // 不能写成 =
            {
                pA->coefficient = pA->coefficient + pB->coefficient;
                if (pA->coefficient) // 处理对应项相加为0的情况 —— 不进入if语句的块，直接让pA、pB指向下一个项，pC不变
                {
                    pC->coefficient = pA->coefficient;
                    pC->index = pA->index;
                    pC++;
                    formC.len++;
                }
                pA++;
                pB++;
            }
            else    // 处理 pA的指数<pB的指数 的情况
            {
                pC->coefficient = pA->coefficient;
                pC->index = pA->index;
                pC++;
                formC.len++;
                pA++;
            }
        }
        else
        {
            pC->coefficient = pB->coefficient;
            pC->index = pB->index;
            pC++;
            formC.len++;
            pB++;
        }
    }

    // 将剩下的项依次放入式子C中
    while ( (pA <= pATail) || (pB <= pBTail) )
    {
        if (pA <= pATail)
        {
            pC->coefficient = pA->coefficient;
            pC->index = pA->index;
            pC++;
            formC.len++;
            pA++;
        }
        else
        {
            pC->coefficient = pB->coefficient;
            pC->index = pB->index;
            pC++;
            formC.len++;
            pB++;
            
        }
    }


    return formC;
}
