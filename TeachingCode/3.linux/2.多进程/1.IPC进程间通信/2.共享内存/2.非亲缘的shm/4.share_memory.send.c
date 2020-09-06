/*************************************************************************
	> File Name: 17.clint.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 19时10分21秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>

struct Msg {
    pid_t pid;
    char msg[50];
};

struct Shm {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    char buff[1024];
};

struct Shm *share_msg = NULL;

int main() {
    int shmid;

    key_t key = ftok(".", 2020);

    if ((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0666)) < 0) {
        //0666是权限
        perror("shmget");
        return 1;
    }
    if ((share_msg = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        return 1;
    }

    while (1) {
        printf("send: ");
        pthread_mutex_lock(&share_msg->mutex);
        scanf("%[^\n]s", share_msg->buff);
        getchar();
        pthread_mutex_unlock(&share_msg->cond);
        pthread_cond_signal(&share_msg->cond);
    }
    
    return 0;
}
