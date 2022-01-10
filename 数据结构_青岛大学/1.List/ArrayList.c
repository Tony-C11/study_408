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

typedef char Elemtype;

typedef struct sqList
{
    Elemtype * elem;
    int len;
} SqList;
// 需要两个参数：1. 数组， 2. 数组实际使用了的长度
// 只是确定了一个复合数据类型，只有在实际定义变量的时候才会占用内存空间

SqList initList(void); // 构建一张空表
void deleteList(SqList * pSqList);
bool locateElem(SqList * pSqList, Elemtype e); // 查找元素的内容，如果查找到，返回该内容所在位置序号
bool insertElem(SqList * pSqList, int position, Elemtype e);
Elemtype deleteElem(SqList * pSqList, int position); // 删除指定位置上的元素，并将该元素（的值）返回
void traversePrintList(SqList * pSqList);

int main(void)
{
    SqList list = initList();

    char i = 'a';
    for (int count = 0; count < 10; ++count)
    {
        list.elem[count] = i;
        ++i;
        ++list.len;
    }

    insertElem(&list, 11, 'w');
    traversePrintList(&list);
    putchar('\n');
    deleteElem(&list, 2);
    traversePrintList(&list);
    putchar('\n');
    deleteList(&list);

    return 0;
}

SqList initList(void)
{
    SqList list;

    list.elem = (Elemtype *)malloc(sizeof(Elemtype) * MAXSIZE);
    if (!list.elem)
    {
        exit(OVERFLOW);
    }

    list.len = 0;

    return list;
}   

void deleteList(SqList * pSqList)
{
    if (pSqList->elem) // 查看表是否存在
    {
        free(pSqList->elem);
        pSqList->elem = NULL;
        pSqList->len = 0;
    }
    else
       printf("List is not exsit!"); 
    return ;
}

bool locateElem(SqList * pSqList, Elemtype e)
{
    for (int index = 0; index < pSqList->len - 1; ++index)
    {
        if (e == pSqList->elem[index])
            return index + 1;
            // 注意为什么是 index + 1
    }
    // 这个查找算法的复杂度如何算？
    // 这里使用顺序查找，一个一个找，符合要求就返回位置序号，不符合就接着找，直到找完整个线性表
    
    printf("该元素不存在\n");
    return ERROR;
}

bool insertElem(SqList * pSqList, int position, Elemtype e)
{
    if ((position < 1) || (position > pSqList->len + 1))
    {
        printf("插入失败，要插入的位置不合法。\n");
        return ERROR; 
    } 

    if (pSqList->len == MAXSIZE)
    {
        printf("线性表已满，无法插入新元素！\n");
        return ERROR;
    }
    // 考虑表满无法插入新元素的情况

    for (int index = pSqList->len; index > position - 1; -- index)
    {
        pSqList->elem[index] = pSqList->elem[index - 1];
    }
    // 该插入算法的时间复杂度计算：https://www.bilibili.com/video/BV1nJ411V7bd?p=19
    pSqList->elem[position - 1] = e;
    pSqList->len ++;
    
    return OK;
}

Elemtype deleteElem(SqList * pSqList, int position)
{
    if ((position < 1) || (position > pSqList->len))
    {
        printf("删除失败，所选位置不合理！\n");
        return '\0';
    }

    Elemtype e = pSqList->elem[position - 1];

    for (int index = position - 1; index < pSqList->len; ++index)
    {
        pSqList->elem[index] = pSqList->elem[index + 1]; 
    }

    pSqList->len --;
    return e;

}

void traversePrintList(SqList * pSqList)
{
    for (int count = 0; count < pSqList->len; ++count)
    {
        printf("%c  ", pSqList->elem[count]);
    }
}
