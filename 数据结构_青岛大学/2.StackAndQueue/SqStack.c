#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define OVERFLOW    -2
#define OK          true
#define ERROR       false
#define STAUS       bool

typedef int ElemType;

typedef struct SqStack
{
    ElemType * pTop;    // pTop 指向栈顶位置+1
    ElemType * pBase;   // pBase 指向栈底->指向下标为0的栈数据元素
    ElemType StackSize;   // 栈的最大元素承载个数 
} Stack, * pStack;

Stack initStack(int size);
void clearStack(pStack p);
void deleteStack(pStack p);
STAUS push(pStack p, ElemType data);
STAUS pop(pStack p, ElemType * popData);
void traversePrintStack(pStack p);

int main(void)
{
    Stack stack = initStack(5);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    traversePrintStack(&stack);
    ElemType popData = 0;
    pop(&stack, &popData);
    traversePrintStack(&stack);
    pop(&stack, &popData);
    traversePrintStack(&stack);
    pop(&stack, &popData);
    traversePrintStack(&stack);
    pop(&stack, &popData);
    traversePrintStack(&stack);
    pop(&stack, &popData);
    traversePrintStack(&stack);
    pop(&stack, &popData);
    traversePrintStack(&stack);
    return 0;
} 

Stack initStack(int size)
{
    Stack stack;
    stack.pBase = (ElemType *)malloc(sizeof(ElemType) * size);
    if (!stack.pBase)
        exit(OVERFLOW);
    stack.pTop = stack.pBase;   // 设置空栈
    stack.StackSize = size;     // 设置栈的最大长度

    return stack;
}

void clearStack(pStack p)
{
    if (p->pBase) // 如果栈存在
        p->pTop = p->pBase;
    return ;    
}

void deleteStack(pStack p)
{
    if (p->pBase)
    {
        free(p->pBase);
        p->pTop = p->pBase = NULL;
        p->StackSize = 0;
    }
    return ;
}

STAUS push(pStack p, ElemType data)
{
    // 查看栈是否满
    if (p->pTop - p->pBase == p->StackSize)
    {
        printf("栈已满，无法入栈\n");
        return ERROR;
    }
    
    *(p->pTop) = data;  // 让数据入栈->放到此时p->pTop指向的位置
    p->pTop++;          // p->pTop 指向栈顶+1的位置
    // 上面两步可以写成 *p->pTop++ = data;
    return OK;
}

STAUS pop(pStack p, ElemType * popData)
{
    if (p->pTop == p->pBase)
    {
        printf("栈为空！无法出栈\n");
        return ERROR;
    }
    p->pTop--;          // 栈（顶）指针 - 1，等于数据出栈
    *popData = *(p->pTop);
    return OK;
}

void traversePrintStack(pStack p)
{
    ElemType * pLocate;
    pLocate = p->pBase;
    printf("当前栈中元素如下：\n");
    while (pLocate != p->pTop)
    {
        printf("%d\n", *pLocate);
        pLocate++;
    }
    // 从栈底元素遍历到栈顶元素

    return ;
}
