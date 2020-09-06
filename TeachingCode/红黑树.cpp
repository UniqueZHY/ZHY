/*************************************************************************
	> File Name: 红黑树.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 23时27分15秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define BLACK 1
#define DBLACK 2

typedef struct Node {
    int key;//数据字段
    int color;//0 red 1 black 2 double black
    struct Node *lchild, *rchild;//指针字段
} Node;

Node __NIL;
#define NIL (&__NIL)//可想象成指针

__attribute__((constructor))//执行在main函数之前
void init_NIL() {//NIL 的初始化
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
    NIL->color = BLACK;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;//NIL 的孩子结点也都为NIL
    p->color = RED;//默认插入红色
    return p;
}

bool has_red_child(Node *root) {
    //看当前节点的孩子节点中是否有红色的
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {//左旋
    Node *temp = root->rchild;
//让原根节点的右子树作为左旋后的结点,即temp指向右孩子
    root->rchild = temp->lchild;
//把temp的左孩子放到根节点的右孩子的位置
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {//右旋
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

//root为祖父结点
Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
//将黑红红变为红黑黑,
//因为插入的第一种情况即uncle节点为红调整方法就是将三元组变为红黑黑,
//而第二种情况即uncle节点为黑的调整方法一种是变为红黑黑或黑红红
        root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    //uncle节点为黑色
    if (root->lchild->color == RED) {
        if (!has_red_child(root->lchild)) return root;//没冲突
        if (root->lchild->rchild->color == RED) {//LR
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);//LL
    } else {
        if (!has_red_child(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {//RL
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);//RR
    }
    root->color = RED;
    //调整颜色
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *predeccessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *eraser_maintian(Node *root) {
    if (root->lchild->color != DBLACK && 
        root->rchild->color != DBLACK) return root;
    //第一个if如果根节点下没有双重黑句不用调整
    if (has_red_child(root)) {//兄弟节点为红
        //有双重黑且根节点有红孩子
        root->color = RED;
        if (root->lchild->color == RED) {//uncle为红在左,就应该进行右旋,右旋后左子树黑色结点少一个所以需要调整颜色,最后右子树中就会出现兄弟节点为黑色的情况所以erasr_maintain(root->rchild)
            root = right_rotate(root);
            root->rchild = eraser_maintian(root->rchild);
        } else {
//uncle为红在右,应先左旋后,向下走变为uncle节点为黑的情况
            root = left_rotate(root);
            root->lchild = eraser_maintian(root->lchild);
    //左旋后右子树黑色结点数量需要调整
        }
        root->color = BLACK;
        //调节方法为原根节点变红,旋转后根节点变黑,所以也可以分开写成105行和115行
        return root;
    } 
    //兄弟节点为黑且无红孩子
    if ((root->lchild->color == DBLACK && !has_red_child(root->rchild)) || 
        (root->rchild->color == DBLACK && !has_red_child(root->lchild))) {
        root->color += 1;//情况一黑黑,三元组变一下即可目的是让双重黑向上走
        root->lchild->color -= 1;//所以根节点加1 左右子树减1
        root->rchild->color -= 1;
        return root;
    }
    //兄弟节点为黑且有红孩子
    if (root->rchild->color == BLACK) {//兄弟节点在右
        if (root->rchild->rchild->color != RED) {//RL,不能用root->rchild->lchild == RED来判断,因为只要右子树为红就是RR 
            root->rchild->color = RED;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
            //右旋后应该一个旋转后跟变黑,旋转前跟变红分开写成130行 132行
        }
//RR 调整方法为左旋后的根节点变为原来根节点的颜色,左右孩子变黑色
        root->rchild->color = root->color;//变为原来根的颜色
        root->color = BLACK;//左旋后的左子树即使原根节点变黑
        root->lchild->color -= 1;
        root = left_rotate(root);
        root->rchild->color = BLACK;//旋转后右子树也变黑
    } else {//兄弟节点在左
        if (root->lchild->lchild->color != RED) {//LR
            root->lchild->color = RED;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
        }
        root->lchild->color = root->color;
        root->color = BLACK;
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = BLACK;       
    }
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return eraser_maintian(root);
}

Node *erase(Node *root, int key) {//包装,确保删除后跟结点为黑色
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}

//包装一层，防止根节点为红色,保证根节点一定是黑色
Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d | %d, %d, %d)\n", 
        root->color, 
        root->key,
        root->lchild->key,
        root->rchild->key
    );
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: root = insert(root, val);break;
            case 1: root = erase(root, val); break;
        }
        output(root);
    }
    return 0;
}
