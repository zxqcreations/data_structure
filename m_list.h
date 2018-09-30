#include "m_struct.h"

int	findItem(Sqlist L, int x);
int	insertItem(Sqlist &L, int p, int e);
int	deleteItem(Sqlist &L, int p, int e);
int	initList(Sqlist &L);
int	getItem(Sqlist L, int p, int &e);

void	createListR(LNode *&c, int a[], int n);
void	createListL(LNode *&c, int a[], int n);
void	mergeList(LNode *a, LNode *b, LNode *&c);
void    mergeListRev(LNode *a, LNode *b, LNode *&c);
LNode*	findNode(LNode *c, int x);
int	findAndDelete(LNode *c, int x);

void    createDListR(DLNode *&c, int a[], int n);
void    createDListL(DLNode *&c, int a[], int n);
void    mergeDList(DLNode *a, DLNode *b, DLNode *&c);
void    mergeDListRev(DLNode *a, DLNode *b, DLNode *&c);
DLNode*  findDNode(DLNode *c, int x);
int     DfindAndDelete(DLNode *c, int x);
