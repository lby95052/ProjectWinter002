#include <stdio.h>
#include <stdlib.h>
#include "head.h"
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

void PrintLIST(struct SListNode *head);
void FindNode(struct SListNode *head);
void ElePrint(char str[]);
int LinePrint(struct SListNode *ptr);
void DelNode(struct SListNode *head);
void DelNode(struct SListNode *head);
void AddNode(struct SListNode *head);
void FreeList(struct SListNode *head);

int SListSize(struct SListNode* s) {            //获取链表有效节点的个数
 assert(s);
 int count = 0;
 PNode pCur = s->_PNext;
 while (pCur) {
  count++;
  pCur = pCur->_PNext;
 }
 return count;
}


Node *CreatList(FILE *fp1, struct SListNode *head)
{

  int r_n = 0;
  char c;

  printf("OPEN This file is OK\n");
  printf("计算文件中数据的行数\n");
  //计算文件中数据的行数
  while (!feof(fp1))
  {
    c = fgetc(fp1);
    if (c == '\n')
      r_n++;
  }
  printf("r_n=%d\n", r_n);
  r_n += 1;

  rewind(fp1); //将指针重置到第一行

  int data_lenghth = r_n;

  //创建一个节点
  printf("已经跳转到list.c\n");

  struct User_login *line1 = NULL; //创建一个节点存放User数据

  char buf[LENGTH];

  int i = 1;

  line1 = (struct User_login *)malloc(sizeof(struct User_login) * (data_lenghth));
  //③利用malloc ( )函数向系统申请分配一个节点

  for (i = 1; i < data_lenghth; i++)
  {
    fgets(buf, LENGTH, fp1);              //一次读取一行数据到buf
    sscanf(buf, "%[^,]", &line1[i].name); //从buf中跳过","读取数据
    printf("save %s to buf\n", line1[i].name);
    line1[i].totalcount = 1;
  }
  printf("文件读取结束\n");

  struct SListNode *p1, *p2;

  // head = (struct Node *)malloc(sizeof(Node)); /*新节点*/

  p1 = p2 = (struct SListNode *)malloc(sizeof(struct SListNode));
  // p3 = p1;
  // while(scanf("%d",&p1->n)&&p1->n!=0)
  for (i = 1; i <= data_lenghth; i++)
  {

    if (head == NULL)
      head = p1;
    else
      p2->_PNext = p1;

    p2 = p1;
    p1 = (struct SListNode *)malloc(sizeof(struct SListNode));
    p1->_data = line1[i];
  }
  p1 = (struct SListNode *)malloc(sizeof(struct SListNode));
  // char c[LENGTH];
  // strcpy(c, "tail")
  // p1->_data.name = c;
  // p1->_data.totalcount = 0;

  p2->_PNext = p1;
  p1->_PNext = NULL;
  p1 = NULL;

  return head;
}

void menu(struct SListNode *head)
{
    fflush(stdin);
  int a;
  printf("                     MENU\n");
  printf("Enter the number before the option to continue\n");
  printf("             [1] 输出链表\n");
  printf("             [2] 查找链表\n");
  printf("             [3] 删除节点\n");
  printf("             [4] 增加节点\n");
  printf("             [5] 删除节点\n");
  printf("             [6] 销毁链表\n");
  printf("             [7] 合并节点\n");
  printf("             [8] 输出数据\n");
  a = getche();
  if (a == '1')
  {

    puts("");
    printf("输出链表\n");
    printf("\n");
    PrintLIST(head);
    printf("输出链表结束\n");
    printf("\n");
    menu(head);

  }
  else if (a == '2')
  {

    puts("");
    printf("查找链表\n");
    FindNode(head);
    printf("查找链表结束\n");
    menu(head);
    
  }
  else if (a == '3')
  {

    puts("");
    printf("删除节点\n");
    DelNode(head);
    printf("删除节点结束\n");
    printf("\n已经删除该记录的信息.");
    printf("\n遍历删除后新表.");
    PrintLIST(head);
    menu(head);
  }
  else if (a == '4')
  {

    puts("");
    printf("增加节点\n");
    AddNode(head);
    printf("增加节点结束\n");
    printf("\n插入队头完毕，遍历新表\n");
    PrintLIST(head);
    menu(head);
  }
  else if (a == '5')
  {

    puts("");
    printf("删除节点\n");
    DelNode(head);
    printf("删除节点结束\n");
    printf("\n已经删除该记录的信息.");
    printf("\n遍历删除后新表.");
    PrintLIST(head);
    menu(head);
  }
  else if (a == '6')
  {

    puts("");
    printf("销毁链表\n");
    FreeList(head);
    printf("销毁链表结束\n");
    menu(head);

  }
  else if (a == '7')
  {

    puts("");
    printf("合并节点\n");
    DeleteDuplication(head);
    printf("输出链表数据\n");
    printf("\n");
    PrintDATA(head);
    menu(head);

  }
  else if (a == '8')
  {

    printf("正在跳转到filewrite.c\n");

    return head;
  }
  else
  {
    printf("WRONG!\n");
    puts("");
    printf("合并节点\n");
    DeleteDuplication(head);
    printf("输出链表数据\n");
    printf("\n");
  }

}

Node *list(FILE *fp1, struct SListNode *head)
{

  head = CreatList(fp1, head);

  printf("链表建立结束\n");
  menu(head);

  // PrintLIST(head);
  // printf("输出链表结束\n");
  // printf("\n");

  //   printf("查找链表\n");

  //   FindNode(head);

  //   printf("查找链表结束\n");

  //   printf("删除节点\n");

  //   DelNode(head);

  //   printf("删除节点结束\n");

  //   	printf("\n已经删除该记录的信息.");
  //     printf("\n遍历删除后新表.");
  //     PrintLIST(head);

  // printf("增加节点\n");

  // AddNode(head);

  // printf("增加节点结束\n");
  //   printf("\n插入队头完毕，遍历新表\n");
  //     PrintLIST(head);

  //   printf("销毁链表\n");
  //   FreeList(head);
  //   printf("销毁链表结束\n");

  // printf("合并节点\n");
  // DeleteDuplication(head);

  // printf("输出链表数据\n");
  //   printf("\n");

  //    PrintDATA(head);

  printf("正在跳转到filewrite.c\n");

  return head;
}

void PrintLIST(struct SListNode *head)
{

  printf("\nQ指向传入head\n");
  struct SListNode *Q = head;
  int i = 0; //用来记录数据序号，并不存入链表中
  // printf("Q %s\n", Q->_data.name);

  Q = Q->_PNext;
  i++;
  //移动到下一个节点

  while (Q->_PNext != NULL)
  {

    printf("Q %s", Q->_data.name);
    Q = Q->_PNext;
    // for(unsigned int i=0;i<12-strlen(Q->_data.name)&&Q->_PNext != NULL;i++)
    // printf(" "); //为了对齐输出，需插入一些空格
    printf("          %d\n", i);
    i++;
  }
  printf("循环输出链表结束\n");
}

void PrintDATA(struct SListNode *head)
{

  printf("\nQ指向传入head\n");
  struct SListNode *Q = head;
  int i = 0; //用来记录数据序号，并不存入链表中
  // printf("Q %s\n", Q->_data.name);

  Q = Q->_PNext;
  i++;
  //移动到下一个节点

  while (Q->_PNext != NULL)
  {

    printf("%s", Q->_data.name);
    printf(",%d\n", Q->_data.totalcount);
    Q = Q->_PNext;
    // for(unsigned int i=0;i<12-strlen(Q->_data.name)&&Q->_PNext != NULL;i++)
    // printf(" "); //为了对齐输出，需插入一些空格
    // printf("           %d\n", i);
    // i++;
  }
  printf("循环输出链表数据结束\n");
}

void FindNode(struct SListNode *head)
{
  struct SListNode *temp = head;
  char name[30];
  scanf("%s", name);

  while (temp != NULL)
  {
    if (!strcmp(temp->_data.name, name))
    {
      printf("查到了 名字是 %s\n", temp->_data.name);
      return;
    }
    temp = temp->_PNext;
    if (temp == NULL)
    {
      printf("到达链表末尾,没有找到\n");
      return;
    }
  }
}

void ElePrint(char str[]) //输出单个元素
{
  if (str == NULL)
    exit(0);
  printf("%s", str);
  for (unsigned int i = 0; i < 12 - strlen(str); i++)
    printf(" "); //为了对齐输出，需插入一些空格
  return;
}

int LinePrint(struct SListNode *ptr) //输出一行
{
  if (ptr == NULL) //检查传进来的指针
    return 0;

  printf("\n");
  ElePrint(ptr->_data.name);
  return 1;
}

void DelNode(struct SListNode *head) // 删除某名称的信息
{
  struct SListNode *p = head, *temp = head, *s;
  char name1[LENGTH];
  printf("\n请输入要删除的节点的名称:");
  scanf("%s", name1);
  while (p) //查找该名称所在的结点
  {
    if (!strcmp(p->_data.name, name1))
      break;
    else
    {
      temp = p;
      p = p->_PNext;
    }

  } // end while
  if (!p)
  {
    printf("\n不存在此名称的记录.");
    return;
  }
  LinePrint(p); //输出该名称的信息
  printf("\n请问真的要删除该记录么?(Y/N)");
  char ch;
  fflush(stdin);
  scanf("%c", &ch);
  if (ch == 'Y' || ch == 'y')
  {
    s = p->_PNext;
    temp->_PNext = s;
    free(p);
    head = temp;
  }
}

void AddNode(struct SListNode *head)
{
  int i;
  char ch;
  struct SListNode *s, *ptr; //s用来建新结点，ptr用来暂存头结点

  struct SListNode *Q = head;

  do
  {
    s = (struct SListNode *)malloc(sizeof(struct SListNode)); // 新建一个名称结点

    printf("\n开始增加..."); //开始增加

    // printf("\n请输入该名称的姓名:");
    // scanf("%s",s->_data.name);
    // printf("\n输入完毕，新节点名称为 %s:", s->_data.name); \
    // s->_data.totalcount = 1;

    //rearPtr 用来指向头节点，沿链表行进，最后用来指向最后一个非空节点
    struct SListNode *rearPtr;
    //nodePtr 用来指向新节点
    struct SListNode *nodePtr;
    //将头节点付给rearPtr，也就是让rearPtr指向头节点
    rearPtr = head;
    //当rearPtr的next为空时，说明这已经是最后一个节点
    while (rearPtr->_PNext->_PNext != NULL)
    {
      //当rearPtr的next不为空时，rearPtr向后走
      rearPtr = rearPtr->_PNext;
    }
    //出循环时，rearPtr已经指向了最后一个非空节点，这个节点有值，但是该节点的next为空
    //给nodePtr分配空间
    nodePtr = (struct SListNode *)malloc(sizeof(struct SListNode));

    //把数据存储在nodePtr指向的节点中的age

    printf("\n请输入该名称的姓名:");
    scanf("%s", s->_data.name);
    printf("\n输入完毕，新节点名称为 %s:", s->_data.name);
    s->_data.totalcount = 1;

    nodePtr->_data = s->_data;

    //把nodePtr的next置为空值
    nodePtr->_PNext = rearPtr->_PNext;
    //让rearPtr的next指向nodePtr，也就是把nodePtr连接到链表尾部，完成插入
    rearPtr->_PNext = nodePtr;

    //   while (Q->_PNext != NULL)
    // {

    //   printf("Q %s", Q->_data.name);
    //   Q = Q->_PNext;
    //   printf("        %d\n", i);
    //   i++;
    // }

    // Q->_PNext = s;
    // s->_PNext = NULL;

    // ptr=head;
    // head=s;//将新结点插入队头
    // s->_PNext = ptr;

    // printf("\n插入队头完毕，遍历新表\n");
    // PrintLIST(head);

    fflush(stdin); //清空输入缓冲区，为了确保不影响后面的数据读取
    printf("\n请问是否继续增加?(Y/N)");
    scanf("%c", &ch);
  } while (ch == 'Y' || ch == 'y');

  printf("\n增加完毕，输出新表");
  PrintLIST(head);
  return head;
}

void FreeList(struct SListNode *head)
{
  //一个一个NULL
  struct SListNode *temp = head; //定义一个临时变量来指向头
  while (temp != NULL)
  {
    printf("销毁 %s\n", temp->_data.name);
    struct SListNode *pt = temp;
    temp = temp->_PNext; //temp指向下一个的地址 即实现++操作
    free(pt);            //释放当前
  }
  //头尾清空	不然下次的头就接着0x10
  head = NULL;

  // printf("销毁成功，输出链表\n");
  // PrintLIST(head);
}

void DestroyListNode(Node *pNode)
{
  int i = 0;
  if (pNode != NULL)
  {
    printf("-----delete list node [%s]-----\n", pNode->_data.name);
    printf("-----total count add 1 -----\n");
    free(pNode);
  }
}

void DeleteDuplication(struct SListNode *pHead)
{
  if (pHead == NULL)
    return;

  //指向当前正在处理的节点；
  struct SListNode *p = pHead;
  //用于遍历p之后的节点；
  struct SListNode *q = NULL;
  struct SListNode *r = NULL;

  while (p != NULL)
  {
    q = p;
    //若后面有节点与当前节点相同，将其统统删除
    while (q->_PNext != NULL)
    {
      if (!strcmp(q->_PNext->_data.name, p->_data.name))
      { //if(q->_PNext->_data.name == p->_data.name)!strcmp(p->_data.name,name1)
        //保存需要删掉的节点
        r = q->_PNext;
        //需要删掉的节点的前后节点相接
        q->_PNext = r->_PNext;
        DestroyListNode(r);
        p->_data.totalcount += 1;
      }
      else
      {
        q = q->_PNext;
      }
    }
    p = p->_PNext;
  }

  // return *pHead;
}

// int SListSize(struct SListNode *Head) {            //获取链表有效节点的个数
//  assert(Head);
//  int count = 0;
//  PNode pCur = Head->_PNext;
//  while (pCur) {
//   count++;
//   pCur = pCur->_PNext;
//  }
//  return count;
// }



// void outlink(struct SListNode *head)
// {
//    struct SListNode *p=head->_PNext;
//    FILE *w =fopen("output.txt","w");
//    if(w==NULL)
//    {
//        printf("打开文件失败!");
//        return;
//    }
//    while(p)
//    {
//        //输出链表节点数据到屏幕
//        printf("%s ",p->_data.name);
//        //输出链表节点数据到文件output.txt
//        fprintf(w,"%s ",p->_data.name);
//        p=p->_PNext;
//    }
//    printf("\n");
//    fprintf(w,"\n");
//    fclose(w);
//    return;
// }
