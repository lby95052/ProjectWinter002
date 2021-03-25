#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <assert.h>
#include <stddef.h>
#include <string.h>
void Sort(struct SListNode *Head,struct SListNode *Tail);
void HeapSort(struct SListNode *Head);
void getend(struct SListNode *Head);

void HeapSort(struct SListNode *Head)
{
    getend(Head);
}


void getend(struct SListNode *Head)
{
    struct SListNode *end;
     struct SListNode *temp;
    temp = Head;

    while (temp->_PNext != NULL)
    {
        temp = temp->_PNext;
    }
    
    end = temp;

    Sort(Head,end);
}



void Sort(struct SListNode *Head,struct SListNode *Tail)
{
	if(Head->_PNext!=Tail&&Head->_PNext->_PNext!=Tail)
	{
		static int count;
		printf("QuickSort调用第%d次数\n",count++);

		struct SListNode *KeyP=Head->_PNext;      //指向存key值内存单元的指针

		struct SListNode *LP=Head;              //比key值小的游标指针,KeyP的左边
		struct SListNode *RP=KeyP;              //比key值大的游标指针,KeyP的右边
		struct SListNode *IncP=KeyP->_PNext;      //遍历单链表的游标指针,每次移动一位
		while(IncP!=Tail)
		{
			if(IncP->_data.totalcount > KeyP->_data.totalcount)
				LP=LP->_PNext=IncP;
			else
				RP=RP->_PNext=IncP;
			IncP=IncP->_PNext;
		}
		LP->_PNext=KeyP;    //将小于Key值的子链表衔接
		RP->_PNext=Tail;    //将大于Key值的子链表衔接

		//递归
		Sort(Head,KeyP); //比Key小的子链表排序
		Sort(KeyP,Tail); //比Key大的子链表排序
		//注Head和Tail是不参与排序的，只起表头和表尾标识作用,故原链表的Tail值为NULL
	}
}
