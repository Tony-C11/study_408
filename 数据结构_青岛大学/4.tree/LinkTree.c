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

void preOrderTraverse(BiTree pTree);
void midOrderTraverse(BiTree pTree);
void postOrderTraverse(BiTree pTree);

int main(void)
{
    return 0;
}

void preOrderTraverse(BiTree pTree)
{
    if (pTree) 
    {
        printf("%c\n", pTree->data);
        preOrderTraverse(pTree->lChild);
        preOrderTraverse(pTree->rChild);
    }

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
