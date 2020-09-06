/*************************************************************************
	> File Name: 9.priority_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月18日 星期二 16时31分17秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->cnt += 1;
    q->data[q->cnt] = val;//将val插在最后的位置
    int ind = q->cnt;
    while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {//>>右移判断是否有父结点，并段大小
        swap(q->data[ind], q->data[ind >> 1]);//与交换父节点
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];//最后一个元素的值给第一个，然后cnt--;
    int ind = 1;
    while ((ind << 1) <= q->cnt) {//<<左移将Ind扩大2倍看看是否有子节点
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[l] > q->data[temp]) temp = l;//找到子节点中较大的一个并把较大的位置给temp
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);//交换根节点于较大的子结点
        ind = temp;
    }
    return 1;
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    priority_queue *q = init(max_op);
    for (int i = 0; i <max_op; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("insert %d to queue\n", val);
    }
    for (int i = 0; i < max_op; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    clear(q);
    return 0;
}
