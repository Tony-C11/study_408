#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct biNode 
{
    ElemType data;
    struct biNode * lChild, * rChild;
} BiNode, *BiTree;

void preOrderTraverse(BiTree pTree, int i);
void midOrderTraverse(BiTree pTree);
void postOrderTraverse(BiTree pTree);

int main(void)
{
    return 0;
}

void preOrderTraverse(BiTree pTree, int i)
{
    int a = 10;
    i = i + 2;
    if (pTree) 
    {
        printf("%c\n", pTree->data);
        preOrderTraverse(pTree->lChild, i-1);
        preOrderTraverse(pTree->rChild, i+1);
    }
    a--;

    return ;
}

void midOrderTraverse(BiTree pTree)
{
    if (pTree)
    {
        midOrderTraverse(pTree->lChild);
        printf("%c\n", pTree->data);
        midOrderTraverse(pTree->rChild);
    }

    return ;
}

void postOrderTraverse(BiTree pTree)
{
    if (pTree)
    {
        postOrderTraverse(pTree->lChild);
        postOrderTraverse(pTree->rChild);
        printf("%c\n", pTree->data);
    }

    return ;
}
