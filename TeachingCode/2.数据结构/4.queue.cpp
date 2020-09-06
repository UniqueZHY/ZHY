/*************************************************************************
	> File Name: 4.queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 19时11分27秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//cnt 代表队列当中元素的个数
typedef struct Queue {
    int *data;
    int head, tail, size, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = q->cnt = 0;
    q->size = n;
    return q;
}

int empty(Queue *q) {
    return q->cnt == 0;
}

int front(Queue *q) {
    return q->data[q->head];
}
//realloc 1.先扩容 2.将之前的拷贝到扩容空间 3.再释放原来的空间 
int expand(Queue *q) {
    int extr_size = q->size;
    int *p ;
    while (extr_size) {
        p = (int *) malloc(sizeof(int) * (q->size + extr_size));//扩出来一块空间
        if (p) break; //如果没有开辟成功
        extr_size /= 2;//缩小空间
    }
    if (q == NULL) return 0;
 //将原来的数据给新开出的内存
    for (int i = q->head, j = 0; j < q->cnt ;j++) {
        p[j] = q->data[(i + j) % q->size];
    }
    //空间扩好了之后将原本传进来q的size和tail head等字段改一下，然后直接将数据给p(新开出来的空间),然后p->data指针指向新开出来的q
    q->size += extr_size;
    q->head = 0;
    q->tail = q->cnt;
    free(q->data);//free释放的是掉q指向由的malloc所分配的内存单元，实际上q还存在，所以可以继续将q->data=p
    q->data = p;
    return 1;
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
 //满了,tail指向尾指针的下一
    if (q->cnt == q->size) {
        if (!expand(q)) return 0;
        printf("expand successfully size = %d\n" , q->size);
    }
    q->data[q->tail++] = val;//先用后加q->data[q->tail] = val;q->tail++;
    if (q->tail == q->size) q->tail -= q->size;
    q->cnt += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head += 1;
    if (q->head == q->size) q->head -= q->size;
    q->cnt -= 1;
    return 1;
}

void output(Queue *q) {
    printf("Queue(%d) = [", q->cnt);
//因为指向下一个所以可以表示个数
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        j && printf(", ");
        printf("%d", q->data[(i + j) % (q->size)]);
    }
    printf("]\n");
    return ;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Queue *q = init(1);
    int op, val;
    for (int i = 0; i < 2 * max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to Queue = %d\n", val, push(q, val));
            } break;
            case 3: {
                printf("pop %d from Queue = %d\n", front(q), pop(q));
            } break;
        }
        output(q);
        printf("\n");
    }
    clear(q);
    return 0;
}
