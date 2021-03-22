#include <stdio.h>
#include <stdlib.h>
#include "head.h"
// #define LENGTH 30

// typedef struct User_login{
// char name[LENGTH]; //用户名
// int totalcount; //登录次数
// }SDataType; //链表的节点
void list();
void filewrite();
FILE* fileread()
{
	 FILE *fp;

	printf("try fileread\n");

	// char line[1024] = {0}; //save file data

	// SDataType data01;

	int  r_n = 0;
	// char buf[LENGTH];
	char c;

	// printf("%s is file path\n", filename);

	if ((fp = fopen("C:\\Users\\Administrator\\Desktop\\new2\\ProjectWinter002\\user_login.txt", "r+")) == NULL)
	{
		printf("Cannot open this file\n");
	}
	
		printf("正在跳转到list.c\n");
       
		// if (fclose(fp))
		// 	printf("file close error!\n");

		 return fp;
	
}