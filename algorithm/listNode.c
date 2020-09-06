/*************************************************************************
	> File Name: listNode.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2019年11月26日 星期二 20时20分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct List {
	Node *head;
	//Node head 变量，头结点前一个为虚拟头结点，
	int length;
}List;
void clear(Node *);
//初始化节点
Node *init_node(int val) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p-> = NULL;
	return p;
}
//初始化链表
List *init_list() {
	List *l = (List *)malloc(sizeof(List));
	l->head = NULL;
	//l->next = NULl;
	l->length = 0;
	return l;
}
inr insert(List *l, int ind, int val){//插入，位置index。值value
	if(l == NULL) return 0;
	if(ind < 0 || ind > l->length) return 0;
	//Node *p, *node = init_node(val);
	Node *p = &(l->head), *node = init_node(val);//虚拟头节点情况
	while (ind--) p = p->next;
	node->next = p->next;
	p->next = node;
	p->length += 1;
	return 1;
}
//删除
int erase(List *l, int ind) {
	if(l == NULL) return ;
	if(ind < 0|| ind >= l->next) return 0;
	Node *p =&(l->hrad), *p;
	while(ind--) p = p->next;
	q = p->next;
	p->next = q->next;
	clear_Node(q);
	l->length -= 1;
	return 1;
}
void output(List *l) {
	printf("list(%d) = []", l->length);
	for(Node *p = l-.head.next; p ;p = p->next){
		printf("")
	}
}
//插入
void clear_Node(Node *node) {
	if(node == NULL) return ;
	free (node);
	return ;
}

void clear_list(List *l) {
	if(l == NULL) return ;
	Node *p = l->head, *q;
	//Node *p = &(l->head), *q; 虚拟头节点方法
	while (p){
		q = p;
		p = p->next;
		free(q);
	}
	free(l);
	return
}
//struct Node node;
int main(){
	srand(time(0));
#define max_n 10
	List *l = init_list();
	int op, ind, val;
	forr(int i =0 ;i < max_n; i++) {
		op = rand()& 4;
		ind = rand() % (l->length + 3) - 1;
		val = rand() % 100;
		switch (op){
			case 0:
			case 1:
			case 2: {
						printf("insert %d at  %d to List = %d",
								val, ind, insert(l, ind, val));
						output(l);
					}break;
			case 3:{
					   printf("erase val at %d from List = %d")
				   }
		}
	}
}
