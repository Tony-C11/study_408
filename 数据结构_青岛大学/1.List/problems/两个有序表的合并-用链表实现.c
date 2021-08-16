#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct node
{
    ElemType elem;
    struct node * pNext;
} Node, * pNode;

pNode headInsertCreatList(int amount);
void traversePrintList(pNode pHead);
pNode mergeList(pNode pHeadA, pNode pHeadB);

int main(void)
{
    pNode pHeadA = headInsertCreatList(5);
    traversePrintList(pHeadA);
    pNode pHeadB = headInsertCreatList(5);
    traversePrintList(pHeadB);
    pNode pHeadC = mergeList(pHeadA, pHeadB);
    printf("合并后的链表为：\n");
    traversePrintList(pHeadC);
    return 0;   
}

pNode headInsertCreatList(int amount)
{
    pNode pHead = (pNode)malloc(sizeof(Node));
    pHead->pNext = NULL;

    for (int count = amount; count > 0; --count)
    {
        pNode pNewNode = (pNode)malloc(sizeof(Node));
        printf("请输入第%d个结点的值：", count);
        scanf("%d", &pNewNode->elem);

        pNewNode->pNext = pHead->pNext;
        pHead->pNext = pNewNode;
    }

    return pHead;
}

void traversePrintList(pNode pHead)
{
    pNode p = pHead->pNext;
    int count = 1;
    while (p)
    {
        printf("Node_%d = %d\n", count++, p->elem);
        p = p->pNext;
    }
    return ;
}

pNode mergeList(pNode pHeadA, pNode pHeadB)
{
    pNode pA = pHeadA->pNext; // 让pA指向ListA的首元结点
    pNode pB = pHeadB->pNext; // pB同理
    pNode pHeadC = pHeadA;      // 让pHeadC指向ListA或ListB
    pNode pC = pHeadC;          // pC指针要不断移动 —— 指向新的被挂在ListC后面的结点，以准备挂再下一个新结点

    while (pA && pB)
    {
        if (pA->elem <= pB->elem)
        {
            pC->pNext = pA; // 
            pC = pA;
            pA = pA->pNext;
            /*
             * 让数值较小的结点挂在pC的后面，
             * 接下来让pC指向下一个结点的（刚才确定的较小的结点），已准备再将其他结点挂在链表的后面
             * pA指向ListA的下一个结点，以准备与pB所指向的结点的下一次数值比较
             * 当pA、pB的其中一个指针指向NULL时，代表其中一个表的所有结点都比较完毕了，结束while
             * 接下来在while的下面将另外一个表的剩下的结点挂在ListC后面就行了
             * 最后要释放另外一个表的头结点
             */
        }
        else
        {
            pC->pNext = pB;
            pC = pB;
            pB = pB->pNext;
        }
    }

    // 将剩下的元素接到链表的后面
    if (pA)
    {
        pC->pNext = pA;
    }
    else // if (pB) {}
    {
        pC->pNext = pB;
    }

    // 这两个if语句也可以写成：pC->pNext = pA? pA: pB

    free(pHeadB);

    return pHeadC;
    // 这个算法的时间复杂的和用顺序表实现的算法的时间复杂度相同
    // 空间复杂度为：O(1)。
    // 这个算法不需要在堆区重新开辟新的空间，只需要改变原来结点的指针域的指针的指向，从而构建出一条新的链表
}
