// ========
//  链表
// ========

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#define OVERFLOW        -2
#define STAUS           bool
#define OK              true
#define ERROR           false

typedef int DATA;

typedef struct Node 
{
    DATA data;
    struct Node * pNext;
} NODE, * PNODE;

STAUS listEmpty(PNODE pHead); // 查看链表是否为空
void deleteList(PNODE pHead); // 销毁链表
void clearList(PNODE pHead); // 清空链表
int listLen(PNODE pHead); // 计算链表长度
STAUS locateElem(PNODE pHead, int position, DATA * e); // 给结点序号，查看该结点上的数据
STAUS insertElem(PNODE pHead, DATA e, int position); // 插入结点到第position个位置 
STAUS deleteElem(PNODE pHead, int position); // 删除序号位置上的结点
int findByValue(PNODE pHead, DATA e); // 按值查找，返回给定值的结点序号
PNODE headInsertCreatList(int amount);
PNODE tailInsertCreatList(int amount);
void traversePrintList(PNODE pHead);

int main(void)
{
    PNODE pHead = tailInsertCreatList(5);
    traversePrintList(pHead);
    putchar('\n');
    
    insertElem(pHead, 111, 1);
    traversePrintList(pHead);
    putchar('\n');
    insertElem(pHead, 222, 7);
    traversePrintList(pHead);
    putchar('\n');
    insertElem(pHead, 333, 0);
    traversePrintList(pHead);
    putchar('\n');
    insertElem(pHead, 444, 11);
    traversePrintList(pHead);
    putchar('\n');
    return 0;
}

PNODE initLinkList(void)
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    pHead->pNext = NULL;
}

STAUS listEmpty(PNODE pHead)
{
    if (pHead->pNext)
        return 0;
    else
        return 1;
}

void deleteList(PNODE pHead)
{
    PNODE pDelete = NULL; // 指向要被销毁的结点

    while (pHead)
    {
        pDelete = pHead;
        pHead = pHead->pNext; // 在当前结点被销毁前指向下一个结点
        free(pDelete);
    }

    return ;
}

void clearList(PNODE pHead)
{
    PNODE pClear = NULL;
    while (pHead->pNext)
    {
        pClear = pHead->pNext;
        pHead->pNext = pClear->pNext;
        free(pClear);
    }
    return ;
}

int listLen(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int count = 0; // **
    
    while (p)
    {
        ++ count;
        p = p->pNext;
    }

    return count;
}

STAUS locateElem(PNODE pHead, int position, DATA * e)
{
    PNODE pLocate = pHead->pNext;
    int count = 1;
    
    // 通过遍历链表来查找指定位置序号上的元素
    // 跳出循环的原因：1. 找到元素； 2. 遍历完整个链表也没找到目标结点
    while (pLocate && count < position)
    {
        pLocate = pLocate->pNext;
        count ++; 
    }

    // 处理循环结束仍未找到指定序号的结点 或 未参与到循环 的情况
    if (!pLocate || count > position)
    {
        return ERROR;
    }

    // 将找到的值赋给 *e，并返回OK
    *e = pLocate->data;
    return OK;
}

// 
STAUS insertElem(PNODE pHead, DATA e, int position)
{ 
    PNODE pLocate = pHead; 
    int count = 0;
    while (pLocate && count < position - 1)
    {
        pLocate = pLocate->pNext;
        count ++;
    }

    if (!pLocate || count > position - 1)
    {
        printf("插入位置不合理！\n");
        return ERROR;
    }

    PNODE pInsert = (PNODE)malloc(sizeof(NODE));
    pInsert->data = e;

    pInsert->pNext = pLocate->pNext; // ①
    pLocate->pNext = pInsert;   // ②
    // ①和②为什么不能调换？
    return OK;
}

int findByValue(PNODE pHead, DATA e)
{
    int count = 1; // 考虑为什么在计算链表长度的时候计数器设为0，在这里为什么又设置为1 ？
    PNODE pFind = pHead->pNext;

    while (pFind->data != e && pFind)
    {
        count ++;
        pFind = pFind->pNext;
    }

    if (!pFind)
    {
        printf("未找到目标数据\n");
        return ERROR;
    }

    return count;
}

STAUS deleteElem(PNODE pHead, int position)
{
    PNODE pLocate = pHead; 
    int count = 0;
    while (pLocate->pNext && count < position - 1)
    {
        pLocate = pLocate->pNext;
        count ++;
    }

    if (!pLocate->pNext || count > position - 1)
    {
        printf("要删除的结点不存在");
        return ERROR;
    }

    PNODE pDelete = pLocate->pNext;
    pLocate->pNext = pDelete->pNext;
    free(pDelete);

    return OK;
}

PNODE headInsertCreatList(int amount)
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE)); // 创建一个头结点
    pHead->pNext = NULL;

    for (int count = amount; count > 0; -- count)
    {
        PNODE pNewNode = (PNODE)malloc(sizeof(NODE));
        printf("请输入新节点的值：");
        scanf("%d", &pNewNode->data);

        pNewNode->pNext = pHead->pNext;
        pHead->pNext = pNewNode;
        // 头插法的关键两步 
    } 
    return pHead;
} 

PNODE tailInsertCreatList(int amount)
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE)); // 创建一个头结点
    pHead->pNext = NULL;
    PNODE pTail = pHead;

    for (int count = 1; count <= amount; ++ count)
    {
        PNODE pNewNode = (PNODE)malloc(sizeof(NODE));
        printf("请输入新节点的值：");
        scanf("%d", &pNewNode->data);
        
        pTail->pNext = pNewNode;
        pTail = pNewNode; 
    }
    pTail->pNext = NULL; // ** 别忘了
    return pHead;
}

void traversePrintList(PNODE pHead)
{
    PNODE pNode = pHead->pNext;
    while (pNode)
    {
        printf("%d    ", pNode->data);
        pNode = pNode->pNext;
    }
    return ;
}


