
/*
 * 顺序存储的线性表 —— 数组
 **/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE     100
#define OVERFLOW    -2
#define OK          true 
#define ERROR       false

typedef char ElemType;

typedef struct sqList
{
    ElemType * elem;
    int len;
} SqList;
// 需要两个参数：1. 数组， 2. 数组实际使用了的长度
// 只是确定了一个复合数据类型，只有在实际定义变量的时候才会占用内存空间

SqList initList(void); // 构建一张空表
void traversePrintList(SqList * pSqList);


int main(void)
{
    SqList listA = initList();
    SqList listB = initList();
    
    return 0;
}

SqList initList(void)
{
    SqList list;

    list.elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    if (!list.elem)
    {
        exit(OVERFLOW);
    }

    list.len = 0;

    return list;
}   

void traversePrintList(SqList * pSqList)
{
    for (int count = 0; count < pSqList->len; ++ count)
    {
        printf("%c  ", pSqList->elem[count]);
    }
}
