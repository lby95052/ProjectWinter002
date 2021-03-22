#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <assert.h>
#include <stddef.h>
#include <string.h>



// typedef struct User_login{
// char name[LENGTH]; //用户名
// int totalcount; //登录次数
// }SDataType; //链表的节点

// typedef struct SListNode
// {
// SDataType _data;
// struct SListNode* _PNext;
// }Node,*PNode; //封装链表节点和 next 指针
void build_heap(SDataType array[],int n );
void heapify(SDataType array[],int n, int i);

int SListSize(struct SListNode *Head) 
{            //获取链表有效节点的个数
 assert(Head);
 int count = 0;
 PNode pCur = Head->_PNext;
 while (pCur) {
  count++;
  pCur = pCur->_PNext;
 }
 return count;
}

void HeapSort(struct SListNode *head )
{//slist

	printf("\n已经跳转到HeapSort.c!\n");
    int listsize=SListSize(head);					//获取链表长度

    SDataType *array=(SDataType *)malloc(sizeof(SDataType)*listsize); //创建长度为链表长度的空间
	struct SListNode *pCur=NULL;
    pCur = head->_PNext;
    int i;

    for(i=0;i<listsize;i++){
        strcpy(array[i].name,pCur->_data.name);
        array[i].totalcount=pCur->_data.totalcount;
        pCur = pCur->_PNext;        
    }//复制数组数据到链表内部

	build_heap(array,listsize);
	for(i=listsize-1; i>=0; i--)
	{
		SDataType temp;   
		temp.totalcount = array[0].totalcount;          
        strcpy(temp.name,array[0].name);

		array[0].totalcount = array[i].totalcount;          
        strcpy(array[0].name,array[i].name);

		array[i].totalcount = temp.totalcount;          
        strcpy(array[i].name,temp.name);

		//heapify(array,i,0);
	}

	pCur = head->_PNext; //指向头节点

    i=0;

    while (pCur) {
        strcpy(pCur->_data.name,array[i].name);
        pCur->_data.totalcount = array[i].totalcount;
        pCur = pCur->_PNext; 
        i++;
    }
	//复制数组数据到链表内部
    //free(array);
}

void build_heap(SDataType array[],int n )
{
	int last_node =n-1;  		//最后一个节点
	int parent=(last_node-1)/2;
	int i;
	for(i=parent;i>=0;i--){		
		heapify(array,n,i);
	}
}

void heapify(SDataType array[],int n, int i)
{
	if(i >= n)
		return;
	int c1=2 * i + 1;
	int c2=2 * i + 2;
	int max = i;
	if(c1 < n && array[c1].totalcount<array[max].totalcount)
		max=c1;
	if(c2 < n && array[c2].totalcount<array[max].totalcount)
		max=c2;
		//取最大值
	if(max != i){
		SDataType temp ;   
		temp.totalcount = array[i].totalcount;          
        strcpy(temp.name,array[i].name);

		array[i].totalcount = array[max].totalcount;          
        strcpy(array[i].name,array[max].name);

		array[max].totalcount = temp.totalcount;          
        strcpy(array[max].name,temp.name);

		heapify(array, n, max);
	}
}
