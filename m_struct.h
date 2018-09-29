#define maxSize 100
typedef struct
{
	int data[maxSize];
	int length;
}Sqlist;

typedef struct TypeA
{
	int a;
	char b;
	float c;
}TypeA;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

typedef struct DLNode
{
	int data;
	struct DLNode *prior;
	struct DLNode *next;
}DLNode;

typedef struct BTNode
{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;
