/*************************************************************************
	> File Name: 7.thread_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 19时12分55秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
    int ltag, rtag;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    p->ltag = NORMAL;
    p->rtag = NORMAL;
    return p;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insert(root->lchild, val);
    else root->rchild = insert(root->rchild, val);
    return root;
}

void build_thread(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    build_thread(root->lchild);//遍历左子树
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;//建立前驱
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;//根节点的前驱为pre ,那么pre的后继为该根节点
    build_thread(root->rchild);//遍历后继
    return ;
}

Node *most_left(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild != NULL) p = p->lchild;//不为空并且不是线索。并且左孩子也不为空
    return p;
}

void output(Node *root) {//用线索进行中序遍历
    Node *p = most_left(root);
    while (p) {
        printf("%d ", p->data);
        if (p->rtag == THREAD) {//判断是右孩子还是线索
            p = p->rchild;//是线索就往下走
        } else {
            p = most_left(p->rchild);//否则就找最左边的子树
        }
    }
    return ;
}

void in_order(Node *root) {//中序遍历
    if (root == NULL) return ;
    if (root->ltag == NORMAL) in_order(root->lchild);
    printf("%d ", root->data);
    if (root->rtag == NORMAL) in_order(root->rchild);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Node *root = NULL;
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    output(root), printf("\n");
    in_order(root), printf("\n");
    clear(root);
    return 0;
}
