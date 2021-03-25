#define LENGTH 30

typedef struct User_login{
char name[LENGTH]; //用户名
int totalcount; //登录次数
}SDataType; //链表的节点

typedef struct SListNode
{
SDataType _data;
struct SListNode* _PNext;
}Node,*PNode; //封装链表节点和 next 指针


int SListSize(struct SListNode* s);

typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
	SDataType Data; /* 结点数据 */
	BinTree Left;     /* 指向左子树 */
	BinTree Right;    /* 指向右子树 */
};