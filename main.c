#include<stdio.h>
#include"head.h"
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

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

FILE* fileread();
Node* list(FILE *fp1, struct SListNode *head);
void filewrite(struct SListNode *head);
void filewriteA(struct SListNode *head);
void BubbleSort(struct SListNode *head);
void QuickSort(struct SListNode *head);
void HeapSort(struct SListNode *head);
int  main(void){

    struct SListNode *head = NULL;
    FILE *fp1;

    
    // struct User_login *line1 = NULL;

    printf("file open\n");
    //struct User_login Datanode;

    fp1 = fileread();
    printf("\n");

    head = list(fp1, head);

    filewrite(head);

    // BubbleSort(head);
    QuickSort(head);
    //HeapSort(head);

    filewriteA(head);


	//return 0;
    getchar();
    
}

// void MENU(void){
// 	fflush(stdin);
// 	int a;
// 	printf("                     MENU\n");
// 	printf("Enter the number before the option to continue\n");
// 	printf("             [1] Score Management\n");
// 	printf("             [2] Score Statistics\n");
// 	printf("             [3] Exit\n");
// 	a=getche();
// 	if(a=='1'){
// 		puts("");
// 		ScoreManagement();
// 	}else if(a=='2'){
// 		puts("");
// 		ScoreStatistics();
// 	}else if(a=='3'){
// 		exit(1);
// 	}else{
// 		printf("WRONG!\n");
// 		MENU();
// 	}
// }
