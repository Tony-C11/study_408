/*
    模拟栈的前置知识是会建立链表结构，并理解用一个指针不断指向结点的思想
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct Node * pNext;
} NODE, *PNODE;

typedef struct Stuck_Ptr
{
    PNODE pTop;
    PNODE pBottom;
} STACK_PTR, *pSTUCK_PTR;

// 可以实现的功能：建立栈、入栈、出栈、遍历栈、清空栈
pSTACK_PTR initStack(void);
void push(pSTACK_PTR stack_pointer, int val);
bool traverse_exstack(pSTACK_PTR stack_pointer);
int pop(pSTACK_PTR stack_pointer);
bool clear_stack(pSTACK_PTR stack_pointer);

int main(void)
{
    pSTACK_PTR stack_pointer = initStack();
    push(stack_pointer, 1);
    push(stack_pointer, 2);
    push(stack_pointer, 3);
    push(stack_pointer, 4);        
    traverse_stack(stack_pointer);
    printf("出栈的值为：%d\n", pop(stack_pointer));
    traverse_stack(stack_pointer);
    printf("出栈的值为：%d\n", pop(stack_pointer));
    traverse_stack(stack_pointer);
    clear_stack(stack_pointer);

    return 0;
}

pSTACK_PTR initStack(void)
{
    pSTACK_PTR stack_pointer = (pSTUCK_PTR)malloc(sizeof(STUCK_PTR));
    
    // 建立一个栈底结点（不是有效结点），方便操作
    stack_pointer->pBottom = (PNODE)malloc(sizeof(NODE)); 
    // 建立空栈
    stack_pointer->pTop = stack_pointer->pBottom;
    stack_pointer->pBottom->pNext = NULL;

    return stack_pointer;
}

// 1. 让新入栈的结点指向上一个结点  2. 让pTop指向栈顶（新入栈的结点）
void push(pSTACK_PTR stack_pointer, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->val = val;
    pNew->pNext = stack_pointer->pTop;
    stack_pointer->pTop = pNew;

    return ;
}

bool traverse_stack(pSTACK_PTR stack_pointer)
{
    if (stack_pointer->pTop == stack_pointer->pBottom)
    {
        printf("栈为空，遍历失败！！！\n");
        return false;
    }
    printf("从栈顶到栈底，数据依次为：");
    PNODE pNode = stack_pointer->pTop;
    while (pNode != stack_pointer->pBottom)
    {
        printf("%d\t", pNode->val);
        pNode = pNode->pNext;
    }
    printf("\n");
    return true;
}

// 出栈不涉及改变栈中结点的指向问题（入栈涉及...），只涉及改变pTop的指向问题
int pop(pSTACK_PTR stack_pointer)
{
    int pop_val;
    if (stack_pointer->pTop == stack_pointer->pBottom)
    {
        printf("栈为空，内存非法访问！！！\n");
        exit(-1);
    }
    
    pop_val = stack_pointer->pTop->val;
    PNODE deleted_node = stack_pointer->pTop;
    stack_pointer->pTop = stack_pointer->pTop->pNext;
    free(deleted_node);
    deleted_node = NULL;

    return pop_val;
}

bool clear_stack(pSTACK_PTR stack_pointer)
{
    if (stack_pointer->pTop == stack_pointer->pBottom)
    {
        printf("栈为空，清空失败");
        return false;
    }
    
    PNODE pClearStack = stack_pointer->pTop;

    while (stack_pointer->pTop != stack_pointer->pBottom)
    {
        stack_pointer->pTop = stack_pointer->pTop->pNext;
        free(pClearStack);
        pClearStack = stack_pointer->pTop;
    }

    printf("清空完成！！！\n");
    traverse_stack(stack_pointer);
    return true;
}


/*
---------------入栈操作的错误写法---------------
// 没有改变真正pTop所指向的位置
void push(PNODE pTop, int val);
int main(void)
{
    ...
    pSTACK_PTR stack_pointer = initStack();
    push(stack_pointer->pTop, 1);
    ...
}
----------------------------------------------
*/
