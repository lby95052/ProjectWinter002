#include <stdio.h>
#include <stdlib.h>
#include "head.h"
// #define LENGTH 30

// typedef struct User_login{
// char name[LENGTH]; //用户名
// int totalcount; //登录次数
// }SDataType; //链表的节点

void filewrite(struct SListNode *head)
{

   printf("\n已经跳转到filewrite.c!\n");
   struct SListNode *p=head->_PNext;
   FILE *w =fopen("C:\\Users\\Administrator\\Desktop\\new2\\ProjectWinter002\\result.txt","w");
   if(w==NULL)
   {
       printf("打开文件失败!");
       return; 
   }
   while(p->_PNext != NULL)
   {
       //输出链表节点数据到屏幕 
       printf("%s,%d\n",p->_data.name,p->_data.totalcount);
       //输出链表节点数据到文件result.txt
       fprintf(w,"%s,%d\n",p->_data.name,p->_data.totalcount);
       p=p->_PNext;        
   }     
   printf("\n");
   fprintf(w,"\n");
   fclose(w);
   printf("写入文件完毕!\n");
   

   return;
}