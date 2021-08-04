#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

#define OVERFLOW        -2
#define STAUS           bool
#define OK              true
#define ERROR           false

typedef int Data;

typedef struct Node
{
    Data elem;
    struct Node * pPrior, * pNext;   
} Node, * pNode;

pNode tailInsertCreatList(int amount);
void traversePrintNode(pNode pHead);
STAUS insertNode(pNode pHead, int pos);
STAUS deleteNode(pNode pHead, int pos);

int main(void)
{
    pNode pHead = tailInsertCreatList(5);
    traversePrintNode(pHead);
    putchar('\n');
    insertNode(pHead, 1);
    traversePrintNode(pHead);
    putchar('\n');
    insertNode(pHead, 7);
    traversePrintNode(pHead);
    putchar('\n');
    insertNode(pHead, 0);
    traversePrintNode(pHead);
    putchar('\n');
    insertNode(pHead, 11);
    traversePrintNode(pHead);
    putchar('\n');
    deleteNode(pHead, 7);
    traversePrintNode(pHead);
    putchar('\n');
    deleteNode(pHead, 0);
    traversePrintNode(pHead);
    putchar('\n');
    deleteNode(pHead, 6);
    traversePrintNode(pHead);
    putchar('\n');
    deleteNode(pHead, 2);
    traversePrintNode(pHead);
    putchar('\n');

    return 0;
} 

pNode tailInsertCreatList(int amount)
{
    pNode pHead = (pNode)malloc(sizeof(Node));
    pHead->pPrior = NULL;
    pNode pTail = pHead;
    
    for (int count = 1; count <= amount; ++ count)
    {
        pNode pNewNode = (pNode)malloc(sizeof(Node));
        printf("请输入新结点的值：");
        scanf("%d", &pNewNode->elem);
        
        pTail->pNext = pNewNode;
        pNewNode->pPrior = pTail;
        pTail = pNewNode;
    }
    pTail->pNext = NULL;

    return pHead;
}

void traversePrintNode(pNode pHead)
{
    pNode pTraverse = pHead->pNext;
    while (pTraverse)
    {
        printf("%d    ", pTraverse->elem);
        pTraverse = pTraverse->pNext;
    }

    return ;
}

STAUS insertNode(pNode pHead, int pos)
{
    pNode pLocate = pHead;
    int count = 0;
    while (pLocate && count < pos - 1)
    {
        pLocate = pLocate->pNext;
        count ++;
    }

    if (!pLocate || count > pos - 1)
    {
        printf("要插入的位置不合理！\n");
        return ERROR;
    }

    pNode pNewNode = (pNode)malloc(sizeof(Node));
    printf("请输入你要插入的结点的值：");
    scanf("%d", &pNewNode->elem);
    
    pNewNode->pNext = pLocate->pNext;
    if (pLocate->pNext)
    {
        pLocate->pNext->pPrior = pNewNode;
    }
    // 如果不加入if，当插入位置为最后一个结点的后面时，会发生非法修改内存的情况 Program received signal SIGSEGV, Segmentation fault.
    // 为什么单链表不会这样？

    pNewNode->pPrior = pLocate;
    pLocate->pNext = pNewNode; 

    return OK;
}

STAUS deleteNode(pNode pHead, int pos)
{
    int count = 1;
    pNode pLocate = pHead->pNext;
    
    while (pLocate && count < pos)
    {
        pLocate = pLocate->pNext;
        ++ count;
    }

    if (!pLocate || count > pos)
    {
        printf("要删除的结点不存在\n");
        return ERROR;
    }

    pLocate->pPrior->pNext = pLocate->pNext;
    if (pLocate->pNext)
    {
        pLocate->pNext->pPrior = pLocate->pPrior;   
    }

    free(pLocate);
//    free(pLocate->pPrior); // 有空考虑一下为什么释放了前一个结点，仍能准确定位下一个结点，而值已经是垃圾值了，难道指针没有被释放？那么指针的值什么时候被释放？
    printf("删除完毕！\n");
    return OK;
}


// 如果用来定位的指针指向头结点，就将计数器设置为0；如果指向首元结点，就将计数器设置为1。
// 因为有指向前驱结点的指针，所以双向链表的插入、删除结点的操作和单链表的有所不同，具体表现在：
// 插入：定位结点（要插入位置的前一个结点的定位方式）的方式和单链表的相同，但因为有pPrior的存在，需要注意删除末端结点可能会造成的指针引用不当
// 删除：定位方式和单链表的不同，双链表可以直接定位要删除的那个节点，接下来的操作可以通过pPrior和pNext来实现，但仍需注意删除末端结点时pPrior可能带来的指针引用不当
