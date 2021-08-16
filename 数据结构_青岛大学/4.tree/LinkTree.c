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

void preTraverse(BiTree pTree);
void midTraverse(BiTree pTree);
void postTraverse(BiTree pTree);

int main(void)
{
    return 0;
}

void preTraverse(BiTree pTree)
{
    printf("%c\n", pTree->data);

    if (pTree->lChild)
        preTraverse(pTree->lChild);

    if (pTree->rChild)
        preTraverse(pTree->rChild);

    return ;
}

void midTraverse(BiTree pTree)
{
    if (pTree->lChild)
        midTraverse(pTree->lChild);
    
    printf("%c\n", pTree->data);

    if (pTree->rChild)
        midTraverse(pTree->rChild);

    return ;
}

void postTraverse(BiTree pTree)
{
    if (pTree->lChild)
        preTraverse(pTree->lChild);

    if (pTree->rChild)
        preTraverse(pTree->rChild);

    printf("%c\n", pTree->data);

    return ;
}
