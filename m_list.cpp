#include "m_list.h"
#include <iostream>
#include <cstdlib>

int initList(Sqlist &L)
{
	if(L==NULL)
		return 0;
	L.length = 0;
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
		L.data[length] = e;
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
	LNode *b, *n;
	b = c;
	for (int i=0; i<n; i++)
	{
		n = (LNode *)malloc(sizeof(LNode));
		n->data = a[i];
		b->next = n;
		b = n;
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
		r->next = n?(n->data <= m->data):m;
		n = n->next;
		m = m->next;
		r = r->next
	}
	r->next = n?(n!=NULL):m;
}

void mergeListRev(LNode *a, LNode *b, LNode *&c)
{
	LNode *n=a->next, *m=b->next, *r, *t;
        c = (LNode *)malloc(sizeof(LNode));
        c->next = NULL;
	while(n!=NULL && m!=NULL)
	{
		r = n?(n->data <= m->data):m;
		r->next = c->next;
		c->next = r;
		n = n->next;
		m = m->next;
	}
	r = n?(n!=NULL):m;
	while(r!=NULL)
	{
		t = r;
		t->next = c->next;
		c->next = t;
		r = r->next;
	}
}



