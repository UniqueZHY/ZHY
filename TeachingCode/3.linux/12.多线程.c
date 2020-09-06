/*************************************************************************
	> File Name: 12.多线程.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 19时50分18秒
 ************************************************************************/

//线程主要解觉 高并发问题, 提高CPU利用率 

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

struct Msg {
    int age;
    char name[20];
};

void *status;
int retval;

//子线程做的事
void *print(void *arg) {
    //printf("%s\n", arg);
    struct Msg* tmp;
    tmp = (struct Msg *)arg;
    printf("name = %s, age = %d\n", tmp->name, tmp->age);
    //return NULL;
    retval = 3;
    pthread_exit((void *)&retval);
}

int main() {
    pthread_t tid;
    struct Msg msg;
    msg.age = 18;
    //char msg[1024] = {0};
    //scanf("%s", msg);
    strcpy(msg.name, "xiaxue");
    pthread_create(&tid, NULL, print, (void *)&msg);
    pthread_join(tid, &status);//相当于wait
    //sleep(1);//为了等子线程结束，要不主线程就先返回0了
    printf("%d\n", *(int *)status);
    return 0;
}
