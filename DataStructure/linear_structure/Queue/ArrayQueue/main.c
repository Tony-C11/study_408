#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue
{
    int * pBase;
    int front;  // 存储队首元素
    int rear;   // 存储队尾元素
} QUEUE, *PQUEUE;

void init_queue(PQUEUE pQueue, int len);
bool en_queue(PQUEUE pQueue, int val, int len);
bool out_queue(PQUEUE pQueue, int * out_val, int len);
bool full_queue(PQUEUE pQueue, int len);
bool emput_queue(PQUEUE pQueue);
void traverse_queue(PQUEUE pQueue, int len);

int main(void)
{
    int out_val;
    QUEUE queue;
    init_queue(&queue, 10);
    en_queue(&queue, 1, 10);
    en_queue(&queue, 2, 10);
    en_queue(&queue, 3, 10);
    en_queue(&queue, 4, 10);
    en_queue(&queue, 5, 10);
    en_queue(&queue, 6, 10);
    en_queue(&queue, 7, 10);
    en_queue(&queue, 8, 10);
    en_queue(&queue, 9, 10);
    traverse_queue(&queue, 10);
    // en_queue(&queue, 10, 10);
    // en_queue(&queue, 10, 10);
    // en_queue(&queue, 10, 10);
    if (out_queue(&queue, &out_val, 10))
        printf("出队的值为：%d\n", out_val);
    else
        printf("出队失败!!!\n");
    traverse_queue(&queue, 10);
    return 0;
}

void init_queue(PQUEUE pQueue, int len)
{
    pQueue->pBase = (int * )malloc(sizeof(int) * len);
    pQueue->front = 0;
    pQueue->rear = 0;
}

bool en_queue(PQUEUE pQueue, int val, int len)
{
    if (full_queue(pQueue, len))
    {
        printf("队列已满！！！无法插入元素！！！\n");
        return false;
    }
    else
    {
        pQueue->pBase[pQueue->rear] = val;
        pQueue->rear = (pQueue->rear + 1) % len;
        return true;
    }
}

bool full_queue(PQUEUE pQueue, int len)
{
    if ((pQueue->rear + 1) % len == pQueue->front)
        return true;
    else
        return false;
}

bool out_queue(PQUEUE pQueue, int * out_val, int len)
{
    if (emput_queue(pQueue)) // 记得给函数一个(参数) QAQ
    {
        printf("队列为空，无法删除！！！\n");
        return false;
    }
    else
    {
        *out_val = pQueue->pBase[pQueue->front];
        pQueue->front = (pQueue->front + 1) % len;
        return true;
    }
}

bool emput_queue(PQUEUE pQueue)
{
    if (pQueue->rear == pQueue->front)
        return true;
    else
        return false;
}

void traverse_queue(PQUEUE pQueue, int len)
{
    int count = pQueue->front;
    printf("队列里的数值依次为：");
    while (count != pQueue->rear)
    {
        printf("%d    ", pQueue->pBase[count]);
        count = (count + 1) % len;
    }
    printf("\n");
}