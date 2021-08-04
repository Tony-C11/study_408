#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int VAL; 

typedef struct Node
{
    VAL val;
    struct Node * pNext;
} NODE, *PNODE;
 
PNODE creat_list(void); // 创建链表
void traverse_list(PNODE pHead);
bool is_empty(PNODE pNode);
int len_list(PNODE pHead);
void sort_list(PNODE pHead);
bool insert_elem(PNODE pHead);
bool delete_elem(PNODE pHead, VAL * delete_val);

int main(void)
{
    int len;    // 存储链表的长度
    VAL delete_val;
    PNODE pList = creat_list();
    if (1 == is_empty(pList))
        return 0;
    printf("链表如下：\n");
    traverse_list(pList);
    insert_elem(pList);
    printf("链表如下：\n");

    traverse_list(pList);
    delete_elem(pList, &delete_val);
    sort_list(pList);
    return 0;
}

PNODE creat_list(void)
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE));    // 头指针指向头结点
    PNODE pTail = pHead;
    pTail->pNext = NULL;        // 考虑空链表的情况
    
    int len;
    printf("请输入你想创建的链表的结点的个数：");
    int i = scanf("%d", &len);
    if ( (len < 0) || (1 != i) )
    {
        printf("输入不合法\n");
        exit(-1);
    }

    int count = 0;

    while (count < len)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("未分配成功");
            exit(-1);
        }
        printf("请输入第%d个结点的值：", count + 1);
        scanf("%d", &pNew->val);
        pNew->pNext = NULL;
        pTail->pNext = pNew;    // 把新结点“挂”到上一个结点的后面
        pTail = pNew;   // 让指针指向新结点
        ++count;
    }
    printf("创建完毕！！！\n");
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE pNode = pHead->pNext;  // 创建一个指针指向第一个有效结点
    while (NULL != pNode)
    {
        printf("\t%d\n", pNode->val);
        pNode = pNode->pNext;
    }
    // printf("\n");
    return ;
}

bool is_empty(PNODE pNode)
{
    if (NULL == pNode->pNext)
    {
        printf("链表为空！！！\n");
        return true;
    }
    return false;
}

bool insert_elem(PNODE pHead)
{
    int elem = 0;

    int insert_pos;
    int insert_val;
    printf("请输入你想插入的结点的位置：");
    scanf("%d", &insert_pos);
    printf("请输入你想插入的值：");
    scanf("%d", &insert_val);

    PNODE pNode = pHead;
    // 插入结点需要判断要插入的位置的前一个结点是否存在
    while (NULL != pNode && elem < (insert_pos - 1))
    {
        pNode = pNode->pNext;
        ++elem;
    }

    if ( (elem > (insert_pos - 1)) || (NULL == pNode) )
    {
        return false;
    }

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("未分配成功");
        exit(-1);
    }

    // 插入结点
    pNew->val = insert_val;
    pNew->pNext = pNode->pNext;
    pNode->pNext = pNew;
    
    return true;
}

bool delete_elem(PNODE pHead, VAL * delete_val)
{
    int delete_pos;
    printf("请输入你想删除的结点的位置：");
    scanf("%d", &delete_pos);
    PNODE p = pHead;
    int i = 0;
    // 删除结点需要判断要删除的位置的上是否存在结点
    while (NULL != p->pNext && i < delete_pos - 1)
    {
        p = p->pNext;
        ++i;    
    }
    /*
        head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6;
        
        delete_pos = 5

        1. i = 0; i < 4;
            p->1;
            i = 1;
        2. i = 1; i < 4
            p->2;
            i = 2;
        3. i = 2; i < 4;
            p->3;
            i = 3;
        4. i = 3; i < 4;
            p->4;
            i = 4;
        5. i = 4 ; break;
    */

    /*
        处理位置不合理的情况
        1. 要删除的位置为空结点
        2. 输入的位置不是正整数
   */
   if (NULL == p->pNext || i > delete_pos - 1)
   {
       return false;
   } 

    //已经遍历到要删除的位置（让指针指向指定位置前面的结点），执行删除操作
    PNODE pDelete = p->pNext;
    *delete_val = p->pNext->val;
    p->pNext = pDelete->pNext;
    free(pDelete);
    pDelete = NULL;
    printf("新链表如下：\n");
    traverse_list(pHead);   
}

void sort_list(PNODE pHead)
{
    int len = len_list(pHead);
    printf("链表有%d个结点\n", len);
    int i, j;
    PNODE pI = pHead->pNext;
    PNODE pJ = NULL;
    VAL mid_val;
    for (i = 0; i < len - 1; ++i, pI = pI->pNext)
    {
        for (j = i + 1, pJ = pI->pNext; j < len; ++j, pJ = pJ->pNext)
        {
            /*
            ---------逻辑上类似于：---------
                if (a[i] < a[j])
                {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            */
           if (pI->val > pJ->val)
           {
               mid_val = pI->val;
               pI->val = pJ->val;
               pJ->val = mid_val;
           }
        }
    }
    // 这个算法涉及“泛型”的理念
    printf("排序完的链表如下：\n");
    traverse_list(pHead);
}

int len_list(PNODE pHead)
{
    PNODE p = pHead;
    int count = 0;
    while (p->pNext)
    {
        p = p->pNext;
        ++count;
    }    
    /*
        5个结点
        指向1 count = 1；
        指向2 count = 2；
        ...
        指向5 count = 5；
        p->pNext = NULL;    break;
    */
    return count;
}
