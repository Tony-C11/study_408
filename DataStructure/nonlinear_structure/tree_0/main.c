#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef char DATA;

typedef struct BinaryTreeNode
{
    DATA nodeData;
    struct BinaryTreeNode * pLeftChild;
    struct BinaryTreeNode * pRightChild;
} BT_NODE, *Ptr_BT_NODE;

Ptr_BT_NODE CreatBinaryTree(void);
void PreTraverse(Ptr_BT_NODE pBiTree);
void MidTraverse(Ptr_BT_NODE pBiTree);
void PostTraverse(Ptr_BT_NODE pBiTree);

int main(void)
{
    Ptr_BT_NODE pRootNode = CreatBinaryTree();
    PreTraverse(pRootNode);
    printf("\n");
    MidTraverse(pRootNode);
    printf("\n");
    PostTraverse(pRootNode);
    return 0;
}

Ptr_BT_NODE CreatBinaryTree(void)
{
    Ptr_BT_NODE pRootNode = (Ptr_BT_NODE)malloc(sizeof(BT_NODE));
    pRootNode->nodeData = 'A';
    Ptr_BT_NODE p1 = (Ptr_BT_NODE)malloc(sizeof(BT_NODE));
    p1->nodeData = 'B';
    Ptr_BT_NODE p2 = (Ptr_BT_NODE)malloc(sizeof(BT_NODE));
    p2->nodeData = 'C';
    Ptr_BT_NODE p3 = (Ptr_BT_NODE)malloc(sizeof(BT_NODE));
    p3->nodeData = 'D';
    Ptr_BT_NODE p4 = (Ptr_BT_NODE)malloc(sizeof(BT_NODE));
    p4->nodeData = 'E';
    Ptr_BT_NODE p5 = (Ptr_BT_NODE)malloc(sizeof(BT_NODE));
    p5->nodeData = 'F';
    Ptr_BT_NODE p6 = (Ptr_BT_NODE)malloc(sizeof(BT_NODE));
    p6->nodeData = 'G';
    Ptr_BT_NODE p7 = (Ptr_BT_NODE)malloc(sizeof(BT_NODE));
    p7->nodeData = 'H';
    Ptr_BT_NODE p8 = (Ptr_BT_NODE)malloc(sizeof(BT_NODE));
    p8->nodeData = 'I';

    pRootNode->pLeftChild = p1;
    p1->pLeftChild = p2;
    p2->pLeftChild = NULL;
    p2->pRightChild = NULL;
    p1->pRightChild = p3;
    p3->pLeftChild = p4;
    p3->pRightChild = NULL;
    p4->pLeftChild = NULL;
    p4->pRightChild = p5;
    p5->pLeftChild = NULL;
    p5->pRightChild = NULL;
//---------------------------------------
    pRootNode->pRightChild = p6;
    p6->pLeftChild = NULL;
    p6->pRightChild = p7;
    p7->pLeftChild = p8;
    p8->pLeftChild = NULL;
    p8->pRightChild = NULL;
    p7->pRightChild = NULL;

    return pRootNode;
}

void PreTraverse(Ptr_BT_NODE pBiTree)
{
    if (pBiTree)
    {
        printf("%c\n", pBiTree->nodeData);
        if (NULL != pBiTree->pLeftChild)
            PreTraverse(pBiTree->pLeftChild);
        if (NULL != pBiTree->pRightChild)
            PreTraverse(pBiTree->pRightChild);
    }
}

void MidTraverse(Ptr_BT_NODE pBiTree)
{
    if (pBiTree)
    {
        if (NULL != pBiTree->pLeftChild)
            MidTraverse(pBiTree->pLeftChild);
        printf("%c\n", pBiTree->nodeData);
        if (NULL != pBiTree->pRightChild)
            MidTraverse(pBiTree->pRightChild);
    }
}

void PostTraverse(Ptr_BT_NODE pBiTree)
{
    if (pBiTree)
    {
        if (NULL != pBiTree->pLeftChild)
            PostTraverse(pBiTree->pLeftChild);
        if (NULL != pBiTree->pRightChild)
            PostTraverse(pBiTree->pRightChild);
        printf("%c\n", pBiTree->nodeData);
    }
    
}
