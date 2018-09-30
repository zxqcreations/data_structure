#include "m_list.h"
#include <iostream>
#include <cstdlib>

int initList(Sqlist &L)
{
	L.length = 0;
	return 1;
}

int getItem(Sqlist L, int p, int &e)
{
	if(p<0||p>L.length-1||L.length==0)
		return 0;
	e = L.data[p];
	return 1;
}

int deleteItem(Sqlist &L, int p, int &e)
{
	if (p<0||p>L.length-1||L.length==0)
		return 0;
	e = L.data[p];
	for (int i=p; i<=L.length-1; i++)
		L.data[i]=L.data[i+1];
	L.length--;
	return 1;
}

int insertItem(Sqlist &L, int p, int e)
{
	if (p<0||p>L.length||L.length==0||L.length==maxSize)
                return 0;
	if (p==L.length)
	{
		L.data[p] = e;
		return 1;
	}
	for (int i=L.length-1; i>=p; i--)
		L.data[i+1]=L.data[i];
	L.data[p] = e;
	L.length++;
	return 1;
}

int findItem(Sqlist L, int x)
{
	if (L.length==0)
		return 0;
	for(int i=0; i<L.length; i++)
		if (L.data[i] == x)
			return i;
	return 0;
}

void createListR(LNode *&c, int a[], int n)
{
	c = (LNode *)malloc(sizeof(LNode));
	c->next = NULL;
	LNode *b, *q;
	b = c;
	for (int i=0; i<n; i++)
	{
		q = (LNode *)malloc(sizeof(LNode));
		q->data = a[i];
		b->next = q;
		b = b->next;
	}
	b->next = NULL;
}

void createListL(LNode *&c, int a[], int n)
{
	c = (LNode *)malloc(sizeof(LNode));
	c->next=NULL;
	LNode *r;
	for (int i=n-1; i>=0; i--)
	{
		r = (LNode *)malloc(sizeof(LNode));
		r->data = a[i];
		r->next = c->next;
		c->next = r;
	}
}

void mergeList(LNode *a, LNode *b, LNode *&c)
{
	LNode *n=a->next, *m=b->next, *r;
	c = (LNode *)malloc(sizeof(LNode));
	c->next = NULL;
	r = c;
	free(a);
	free(b);
	while(n!=NULL && m!=NULL)
	{
		r->next = (n->data <= m->data)?n:m;
		n = n->next;
		m = m->next;
		r = r->next;
	}
	r->next = (n!=NULL)?n:m;
}

void mergeListRev(LNode *a, LNode *b, LNode *&c)
{
	LNode *n=a->next, *m=b->next, *r, *t;
        c = (LNode *)malloc(sizeof(LNode));
        c->next = NULL;
	while(n!=NULL && m!=NULL)
	{
		r = (n->data <= m->data)?n:m;
		r->next = c->next;
		c->next = r;
		n = n->next;
		m = m->next;
	}
	r = (n!=NULL)?n:m;
	while(r!=NULL)
	{
		t = r;
		t->next = c->next;
		c->next = t;
		r = r->next;
	}
}



