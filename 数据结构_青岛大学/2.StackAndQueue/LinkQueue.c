
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define STAUS       bool
#define OK          true
#define ERROR       false
#define OVERFLOW    -2

typedef int ElemType;

typedef struct queueNode
{
    ElemType elem;
    struct queueNode * pNext;
} QueueNode, * pQueueNode;

typedef struct queuePtr
{
    pQueueNode front, rear;
} QueuePtr;

QueuePtr * initQueue(void);
STAUS enQueue(QueuePtr * pQueuePtr, ElemType data);
STAUS deQueue(QueuePtr * pQueuePtr, ElemType * data);
void traversePrintQueue(QueuePtr * pQueuePtr);

int main(void)
{
    QueuePtr * pQueuePtr = initQueue();
    enQueue(pQueuePtr, 10);
    traversePrintQueue(pQueuePtr);
    enQueue(pQueuePtr, 20);
    traversePrintQueue(pQueuePtr);
    enQueue(pQueuePtr, 30);
    traversePrintQueue(pQueuePtr);
    enQueue(pQueuePtr, 40);
    traversePrintQueue(pQueuePtr);
    enQueue(pQueuePtr, 50);
    traversePrintQueue(pQueuePtr);

    int data;
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    deQueue(pQueuePtr, &data);
    traversePrintQueue(pQueuePtr);
    return 0;
}

QueuePtr * initQueue(void)
{
    QueuePtr * pQueuePtr = (QueuePtr *)malloc(sizeof(QueuePtr));
    pQueuePtr->rear = pQueuePtr->front = (pQueueNode)malloc(sizeof(QueueNode)); // 创建一个头结点
    if (!pQueuePtr->rear)
    {
        printf("内存不足，创建失败！\n");
        exit(OVERFLOW);
    }
    pQueuePtr->rear->pNext = NULL;

    return pQueuePtr;
} 

STAUS enQueue(QueuePtr * pQueuePtr, ElemType data)
{
    pQueueNode pNewNode = (pQueueNode)malloc(sizeof(QueueNode));
    if (!pNewNode)
    {
        printf("队列已满，无法入队！\n");
        return ERROR;
    }

    pNewNode->elem = data;
    pQueuePtr->rear->pNext = pNewNode;
    pQueuePtr->rear = pNewNode;
    pQueuePtr->rear->pNext = NULL;  // 入队一定要把队尾结点的指针域指向NULL

    return OK;
}

STAUS deQueue(QueuePtr * pQueuePtr, ElemType * data)
{
    if (pQueuePtr->front == pQueuePtr->rear)
    {
        printf("队列为空，无法出队！\n");
        return ERROR;
    }

    pQueueNode pDeQueue = pQueuePtr->front->pNext;
    *data = pDeQueue->elem;
    pQueuePtr->front->pNext = pDeQueue->pNext;
    free(pDeQueue);
    
    // 当最后一个结点出队时，一定要让rear = front
    if (!pQueuePtr->front->pNext)
        pQueuePtr->rear = pQueuePtr->front;
    return OK;
}

void traversePrintQueue(QueuePtr * pQueuePtr)
{
    pQueueNode pTraverse = pQueuePtr->front->pNext;
    printf("队列如下：\n");
    while (pTraverse)
    {
        printf("%d\n", pTraverse->elem);
        pTraverse = pTraverse->pNext;
    }

    return ;
}
