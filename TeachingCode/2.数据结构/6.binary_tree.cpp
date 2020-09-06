/*************************************************************************
	> File Name: 6.binary_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 16时00分06秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//二叉树结点的结构定义
typedef struct Node {
    int data;
    struct Node *lchild, *rchild;//两个指针域指向
} Node ;

typedef struct Tree {
    Node *root ;
    int n; 
} Tree ;
//初始化结点
Node *getNewNode(int val) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}
//初始化树
Tree *getNewTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0 ;
    return tree;
}
//插入结点 
Node *insert_Node(Node *root , int val , int *ret) {
    //ret代表创建结点是否成功
    if (root == NULL) {
        *ret = 1 ;
        return getNewNode(val);
    }
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insert_Node(root->lchild , val , ret);//递归插入小放左子树
    else root->rchild = insert_Node(root->rchild , val , ret);//大于val放右子树
    return root ;
}

void insert(Tree *tree , int val) {
    int flag = 0;
    tree->root = insert_Node(tree->root , val , &flag);
    tree->n += flag;
    return ;
}
void outputNode (Node *root) {
    if (root == NULL) return ;
    printf("%d " , root->data);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return ;
}
void output(Tree *tree) {
    printf("tree(%d) = [" , tree->n);
    outputNode (tree->root);
    printf("]\n");
    return ;
}

void pre_orderNode (Node *root) {//打印前序遍历
    if (root == NULL) return ;
    printf("%d " , root->data);
    pre_orderNode(root->lchild);
    pre_orderNode(root->rchild);
    return ;
}
void pre_order(Tree *tree) {//前序遍历
    printf("pre_order : ");
    pre_orderNode(tree->root);
    printf("\n");
}
void in_orderNode (Node *root) {//打印中序遍历
    if (root == NULL) return ;
    in_orderNode(root->lchild);
    printf("%d " , root->data);
    in_orderNode(root->rchild);
    return ;
}
void in_order(Tree *tree) {//中序遍历
    printf("in_order : ");
    in_orderNode(tree->root);
    printf("\n");
}
void post_orderNode (Node *root) {//打印后序遍历
    if (root == NULL) return ;
    post_orderNode(root->lchild);
    post_orderNode(root->rchild);
    printf("%d " , root->data);
    return ;
}
void post_order(Tree *tree) {//后序遍历
    printf("post_order : ");
    post_orderNode(tree->root);
    printf("\n");
}
void clear_Node (Node *node) {
    if (node == NULL) return ;
    clear_Node(node->lchild);
    clear_Node(node->rchild);
    free(node);
    return ;
}

void clear_Tree(Tree *tree) {
    if (tree == NULL) return ;
    clear_Node(tree->root);
    free(tree);
    return ;
}

int main() {
    #define max_op 10
    srand(time(0));
    Tree *tree = getNewTree();
    for (int  i = 0 ;i < max_op ;i++) {
        int val = rand() % 100;
        insert(tree , val);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_Tree(tree);
    return 0 ;
}
