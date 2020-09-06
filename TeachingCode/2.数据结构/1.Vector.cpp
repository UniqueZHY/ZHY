/*************************************************************************
	> File Name: 1.Vector.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月11日 星期二 14时51分47秒
 ************************************************************************/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>//顺序表 
//定义一种数据类型struct Vector重新ming名为Vector
typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *init(int n)/*初始化*/{
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

int expand(Vector *vec) {
    int extr_size = vec->size;
    int *p;
    while (extr_size) {
        //                开辟位置   开辟大小
        p = (int *)realloc(vec->data, sizeof(int) * (vec->size + extr_size));
        //为了防止扩容失败导致的内存泄漏，当扩容失败时返回值为NULL 所以用p
        if (p) break;//如果p不等于NULL，表示扩容成功
        extr_size /= 2;//若p为空，就将开辟空间减少一半，继续扩充
    }
    if (p == NULL) return 0;
    vec->data = p;//data开辟好的空间
    vec->size += extr_size;//更新size
    return 1;
}

//插入
int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind > vec->length) return 0;
    if (vec->length == vec->size) {
        //扩容操作
        if (!expand(vec)) return 0;
        printf("expand successfully ! size = %d\n", vec->size);
    }
    for (int i = vec->length; i > ind; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}


//删除
int erase (Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind >= vec->length) return 0;
    for (int i = ind + 1; i < vec->length; i++) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->length -= 1;
    return 1;
}

void output(Vector *vec) {
    printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        i && printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return ;
}

//清空回收
void clear(Vector *vec) {
    if (vec == NULL) return;
    free(vec->data);
    free(vec);
    return ;
}
int main() {
    srand(time(0));
    #define max_op 20
    Vector *vec = init(max_op);
    int op, ind, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        //ind = rand() % (vec->length + 1);取值范围[0, vec->length]
        ind = rand() % (vec->length + 3) - 1;//添加失败案例
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2:{
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
            case 3: {
                printf("erase item at %d from Vector = %d\n", ind, erase(vec, ind));
            }break;
        }
        output(vec);
        printf("\n");
    }
    return 0;
}
