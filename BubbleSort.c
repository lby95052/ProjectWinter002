#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void BubbleSort(struct SListNode *head)
{
    printf("\n已经跳转到BubbleSort.c!\n");
	struct SListNode *cur=NULL;
    struct SListNode *teil=NULL;
    cur=head->_PNext;
    while(cur!=teil){
        while(cur->_PNext!=teil){
            if(cur->_data.totalcount < cur->_PNext->_data.totalcount){
                int temp=cur->_data.totalcount;
                cur->_data.totalcount=cur->_PNext->_data.totalcount;
                cur->_PNext->_data.totalcount=temp;
            }
            cur=cur->_PNext;
        }
        teil=cur;
        cur=head->_PNext;
    }
}
