#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <assert.h>
#include <stddef.h>
#include <string.h>

// typedef struct TNode *Position;
// typedef Position BinTree; /* 二叉树类型 */
// struct TNode{ /* 树结点定义 */
// 	SDataType Data; /* 结点数据 */
// 	BinTree Left;     /* 指向左子树 */
// 	BinTree Right;    /* 指向右子树 */
// };


BinTree Insert( BinTree BST, SDataType X )
{
     printf("插入二叉树数据\n");
    if( !BST ){ /* 若原树为空，生成并返回一个结点的二叉搜索树 */
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* 开始找要插入元素的位置 */
        int tmp = strcmp(X.name, BST->Data.name);
        if( tmp < 0)
            BST->Left = Insert( BST->Left, X );   /*递归插入左子树*/
        else  if( tmp > 0 )
            BST->Right = Insert( BST->Right, X ); /*递归插入右子树*/
        else {
            printf("%s ", X.name);
        }
        /* else X已经存在，什么都不做 */
	}
    return BST;
}

BinTree createBST(struct SListNode *head, BinTree BST)
{

    //printf("创建二叉树\n");
    PNode pCur; 
    pCur = head->_PNext;
    int count = 0;
    while (pCur) {
        BST = Insert(BST, pCur->_data);
        pCur = pCur->_PNext; 
        count++;
    }
    printf("%d\n", count);
    InorderTraversal(BST,count);

    return BST;//结束bst。c
}


void InorderTraversal( BinTree BT, int *count)
{

    if( BT ) {
        InorderTraversal( BT->Left, count );
		/* 此处假设对BT结点的访问就是打印数据 */
        printf("BST:%s,%d \n", BT->Data.name,BT->Data.totalcount); /* 假设数据为整型 */
        //(*count)++;
        InorderTraversal( BT->Right, count );
    }
}
