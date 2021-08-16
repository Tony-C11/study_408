// A = {1, 2, 4, 5};        B = {3, 4, 7, 8, 9}   
// A, B为两张有序表
// 按非递减原则合并两个集合
// C = {1, 2, 3, 4, 5, 7, 8, 9}

#include <stdio.h>
#include <malloc.h>

#define MAXSIZE     20

typedef int ElemType;

typedef struct sqList
{
    ElemType * elem;
    int len;
} SqList;

SqList creatSqList(void);
void mergeList(SqList * pListA, SqList * pListB, SqList * pListC);
void traversePrintList(SqList * pList);
int main(void)
{
    SqList listA = creatSqList();
    listA.elem[0] = 1;
    listA.elem[1] = 2;
    listA.elem[2] = 4;
    listA.elem[3] = 5;
    listA.len = 4;

    SqList listB = creatSqList();
    listB.elem[0] = 3;
    listB.elem[1] = 4;
    listB.elem[2] = 7;
    listB.elem[3] = 8;
    listB.elem[4] = 9;
    listB.len = 5;

    SqList listC = creatSqList();
    // listC.len = listA.len + listB.len;
    
    mergeList(&listA, &listB, &listC);

    traversePrintList(&listC);
    return 0;
}

SqList creatSqList(void)
{
    SqList list;
    list.elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    list.len = 0;

    return list;
}

void mergeList(SqList * pListA, SqList * pListB, SqList * pListC)
{
    ElemType * pA = pListA->elem;
    ElemType * pTailA = pListA->elem + (pListA->len - 1);
    ElemType * pB = pListB->elem;
    ElemType * pTailB = pListB->elem + (pListB->len - 1);
    ElemType * pC = pListC->elem;
    /*
     *  声明3个指针，分别指向3个顺序表的第一个数据元素的位置，通过指针的移动来比较、传递数据
     *  注意指针类型
     *  */


    while ( pA <= pTailA && pB <= pTailB)   // 什么时候结束循环？当其中一张表的所有元素都复制到listC中后，另一张表剩下的元素不用比较了，通过下面某个while循环将剩下的元素复制到listC中
    {
        if (*pA <= *pB)
        {
            *pC = *pA;
            pC ++;
            pA ++; // 如果是listA中的元素符合条件、被放入listC中，就让指针指向listA的下一个元素，让listA的下一个元素参与到下一轮迭代中，同样也让指向listC的元素的指针指向listC的下一个元素，以准备放下一个元素；listB的元素同理；
        }
        else 
        {
            *pC = *pB;
            pC ++;
            pB ++;
        }
    }


    /*
     *  通过下面几个步骤将表中剩下的元素复制到listC中
     *
     *  */

    while (pA <= pTailA) // listA有数据未拷贝到listC中
    {
        *pC = *pA;
        pC ++;
        pA ++;
    }

    while (pB <= pTailB) // listA有数据未拷贝到listC中
    {
        *pC++ = *pB++;
    }

    pListC->len = pListA->len + pListB->len;

    return ;
}
// 时间复杂度 = O(listA.len + listB.len);
// 空间复杂度 = O(listA.len + listB.len);

void traversePrintList(SqList * pList)
{
    for (int count = 0; count < pList->len; ++count)
    {
        printf("arr[%d] = %d\n", count, pList->elem[count]);
    }
    return ;
}
