#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define OVERFLOW    -2
#define OK          true
#define ERROR       false
#define STAUS       bool
#define QUEUESIZE   10


typedef int ElemType;

typedef struct circularQueue
{
    ElemType front; // 指向队首 -> 并不是指针，而是用front表示数组队列 队头元素的下标；
    ElemType rear;  // 指向队尾 -> 并不是指针，而是用rear表示数组队列 队尾元素的下标+1；每次入队时，都将新数据放在rear“指向“的位置，然后将rear后移；
    ElemType * base;   // 指向数组队列首元素的指针
} CircularQueue;

CircularQueue initQueue(void);
STAUS clearQueue(CircularQueue * pQueue);
STAUS deleteQueue(CircularQueue * pQueue);
STAUS enQueue(CircularQueue * pQueue, ElemType data);
STAUS dequeue(CircularQueue * p, ElemType * data);  // 队列出队的时候不需要剩下的元素往前移
int queueLength(CircularQueue * pQueue);

int main(void)
{
    CircularQueue queue = initQueue();
    return 0;
}

CircularQueue initQueue(void)
{
    CircularQueue queue;

    queue.base = (ElemType *)malloc(sizeof(ElemType) * QUEUESIZE);
    if (!queue.base)
    {
        printf("队列创建失败！\n");
        exit(OVERFLOW);
    }

    queue.front = queue.rear = 0;
    return queue;
}

STAUS clearQueue(CircularQueue * pQueue)
{
    if (!pQueue->base)
    {
        printf("队列不存在！\n");
        return ERROR;
    }
    pQueue->rear = pQueue->front; 
    return OK;
}

STAUS deleteQueue(CircularQueue * pQueue)
{
    if (!pQueue->base)
    {
        printf("队列不存在！\n");
        return ERROR;
    }

    free(pQueue->base);
    return OK;
}

STAUS enQueue(CircularQueue * pQueue, ElemType data)
{
    if ( (pQueue->rear + 1) % QUEUESIZE == pQueue->front )
    {
        printf("队列已满！无法入队！\n");
        return ERROR;
    }

    pQueue->base[pQueue->rear] = data;  // 注意使用的是pQueue->base[pQueue->rear]，而不是错误的pQueue->base[rear]。
    pQueue->rear = (pQueue->rear + 1) % QUEUESIZE;
    
    return OK;
}

STAUS dequeue(CircularQueue * p, ElemType * data)
{
    if (p->front == p->rear)
    {
        printf("队列为空，出队失败");
        return ERROR;
    }

    * data = p->base[p->front];
    p->front = (p->front + 1) % QUEUESIZE;

    return OK;
}

int queueLength(CircularQueue * pQueue)
{
    if (!pQueue->base)
    {
        printf("队列不存在，返回-1\n");
        return -1;
    }

    return (pQueue->rear - pQueue->front + QUEUESIZE) % QUEUESIZE;
}
