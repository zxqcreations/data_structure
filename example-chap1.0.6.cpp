/*
Writen by Xueqian Zhang (zxqsoftware@foxmail.com).

有一个递增非空单链表， 设计一个算法删除值域重复的节点， 例如：
[In]
	{1,1,2,3,3,3,4,4,7,7,7,9,9,9};
[Out]	
	{1,2,3,4,7,9};
本例使用了两种删除算法del1和del2.
*/
#include "m_list.h"
#include <iostream>
#include <cstdlib>

int a[] = {1,1,2,3,3,3,4,4,7,7,7,9,9,9};

void del1(LNode *L){
	LNode *p;
	p = L->next;
	while(p->next!=NULL){
		if(p->data==p->next->data){
			p->next=p->next->next;
			//p = p->next;
		}
		else
			p = p->next;
	}
}

void del2(LNode *L){
	LNode *p, *q;
	p = L->next;
	q = p;
	while(q->next!=NULL){
		if(q->data == q->next->data)
			q = q->next;
		else{
			p->next=q->next;
			q = q->next;
			p = p->next;
		}
	}
	p->next=NULL;
}

int main(){
	LNode *L;
	LNode *K;
	LNode *J;
	std::cout<<"original:"<<std::endl;
	createListR(L, a, 14);
	LNode *p = L->next;
	while(p!=NULL){
		std::cout<<p->data<<" ";
		p = p->next;
	}
	std::cout<<std::endl;
	std::cout<<"del1:"<<std::endl;
        createListR(L, a, 14);
	del1(L);
        p = L->next;
        while(p!=NULL){
                std::cout<<p->data<<" ";
                p = p->next;
        }
        std::cout<<std::endl;
	std::cout<<"del2:"<<std::endl;
        createListR(L, a, 14);
	del2(L);
        p = L->next;
        while(p!=NULL){
                std::cout<<p->data<<" ";
                p = p->next;
        }
        std::cout<<std::endl;
}
