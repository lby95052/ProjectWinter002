#include <stdio.h>
#include <stdlib.h>
#include "head.h"

// #define LENGTH 30

// typedef struct User_login{
// char name[LENGTH]; //用户名
// int totalcount; //登录次数
// }SDataType; //链表的节点

// typedef struct SListNode
// {
// SDataType _data;
// struct SListNode* _PNext;
// }Node,*PNode; //封装链表节点和 next 指针

void QuickSort1(struct SListNode *pBegin, struct SListNode *pEnd);

void QuickSort(struct SListNode *head)
{

	struct SListNode *Q = head;



	Q = Q->_PNext;

	//移动到下一个节点

	while (Q->_PNext != NULL)
	{
		Q = Q->_PNext;
	}

	

	struct SListNode *pBegin = head;

	struct SListNode *pEnd;

	pEnd = Q;

	QuickSort1(pBegin,pEnd);
	

}



void QuickSort1(struct SListNode *pBegin, struct SListNode *pEnd)
{

	

	if (NULL == pBegin || NULL == pEnd || pBegin == pEnd)
	{
		return;
	}

	struct SListNode *pFirst = pBegin;
	struct SListNode *pSecond = pFirst->_PNext;
	struct User_login t;

	int nMidValue = pBegin->_data.totalcount;

	//开始排序
	while (pSecond != pEnd->_PNext && pSecond != NULL)
	{
		if (pSecond->_data.totalcount > nMidValue)
		{
			pFirst = pFirst->_PNext;

			//swap(pFirst->data.uiLinkId, pSecond->data.uiLinkId);
			t = pFirst->_data;
			pFirst->_data = pSecond->_data;
			pSecond->_data = t;
		}

		pSecond = pSecond->_PNext;
	}

	//更换支点后完成1轮排序
	//swap(pBegin->data.uiLinkId, pFirst->data.uiLinkId);
	t = pBegin->_data;
	pBegin->_data = pFirst->_data;
	pFirst->_data = t;

	QuickSort1(pBegin, pFirst);
	QuickSort1(pFirst->_PNext, pEnd); //此处的next很重要,不然将导致死循环
}
