#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define STAUS       bool
#define OK          true
#define ERROR       false
#define OVERFLOW    -2

typedef int ElemType;

typedef struct stackElem
{
    ElemType data;
    struct stackElem * pNext;    
} StackElem, * pStackElem;  // 注意*

pStackElem initStack(void);
STAUS push(pStackElem * pStack, ElemType pushData);
STAUS pop(pStackElem * pStack, ElemType * popData);
void traversePrintStack(pStackElem * pStack);

int main(void)
{
    pStackElem pStack = initStack();
    push(&pStack, 20);
    push(&pStack, 10);
    push(&pStack, 30);
    traversePrintStack(&pStack);

    ElemType elemPop;
    pop(&pStack, &elemPop);
    traversePrintStack(&pStack);
    pop(&pStack, &elemPop);
    traversePrintStack(&pStack);
    pop(&pStack, &elemPop);
    traversePrintStack(&pStack);
    pop(&pStack, &elemPop);
    traversePrintStack(&pStack);

    return 0;
}

pStackElem initStack(void)
{
    pStackElem pStack = NULL;
    return pStack;
}

STAUS push(pStackElem * pStack, ElemType pushData)
{
    pStackElem pPush = (pStackElem)malloc(sizeof(StackElem));
    if (!pPush)
    {
        printf("入栈失败！\n");
        exit(OVERFLOW);
    }
    pPush->pNext = *pStack; // 和普通单链表相反，栈的结点是通过
    pPush->data = pushData;
    *pStack = pPush;

    return OK;
}

STAUS pop(pStackElem * pStack, ElemType * popData)
{
    if (!*pStack)
    {
        printf("栈为空，出栈失败！\n");
        return false;
    }

    pStackElem pPop = *pStack;
    *popData = (*pStack)->data;
    *pStack = (*pStack)->pNext;
    free(pPop);
}

void traversePrintStack(pStackElem * pStack)
{
    pStackElem p = *pStack;
    printf("栈内元素如下：\n");
    while (p)
    {
        printf("%d\n", p->data);
        p = p->pNext;
    }
    return ;
}
