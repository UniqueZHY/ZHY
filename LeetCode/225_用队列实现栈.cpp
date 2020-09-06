/*************************************************************************
	> File Name: 225_用队列实现栈.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 20时15分04秒
 ************************************************************************/
typedef struct MyQueue {
    int *data;
    int head, tail;
    int size, cnt;
}MyQueue;

MyQueue *MyQueueCreate(int size) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = q->tail = 0;
    q->cnt = 0;
    q->size = size;
    return q;
}

void MyQueuePush(MyQueue *obj, int x) {
    if (obj == NULL) return ;
    if (obj->cnt == obj->size) return ;
    obj->data[(obj->tail)++] = x;
    if (obj->tail == obj->size) obj->tail -= obj->size;
    obj->cnt += 1;
    return ;
}

int MyQueueFront(MyQueue *obj) {
    return obj->data[obj->head];    
}

int MyQueuePop(MyQueue *obj) {
    if (obj == NULL) return 0;
    if (obj->cnt == 0) return 0;
    obj->head += 1;
    if (obj->head == obj->size) obj->head -= obj->size;
    obj->cnt -= 1;
    return 1;
}

int MyQueueEmpty(MyQueue *obj) {
    return obj->cnt == 0;
}

void MyQueueFree(MyQueue *obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

typedef struct {
    MyQueue *q1, *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
   int size = 1024;
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->q1 = MyQueueCreate(size);
    obj->q2 = MyQueueCreate(size);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (!MyQueueEmpty(obj->q1)) {
        MyQueuePush(obj->q1, x);
    } else {
        MyQueuePush(obj->q2, x);
    }
    return ;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyQueue *p = MyQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = MyQueueEmpty(obj->q1) ? obj->q1 : obj->q2;//空
    int element = MyQueueFront(p);
    MyQueuePop(p);
    while (!MyQueueEmpty(p)) {//已经提前删除了一个所以当p为空时最后一个元素没有进q达到pop操作
        MyQueuePush(q, element);
        element = MyQueueFront(p);
        MyQueuePop(p);
    }
    return element;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    MyQueue *p = MyQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = MyQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element;
    while (!MyQueueEmpty(p)) {
        element = MyQueueFront(p);
        MyQueuePop(p);
        MyQueuePush(q, element);
    }
    return element;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return MyQueueEmpty(obj->q1) && MyQueueEmpty(obj->q2);
}

void myStackFree(MyStack* obj) {
    MyQueueFree(obj->q1);
    MyQueueFree(obj->q2);
    free(obj);
}
