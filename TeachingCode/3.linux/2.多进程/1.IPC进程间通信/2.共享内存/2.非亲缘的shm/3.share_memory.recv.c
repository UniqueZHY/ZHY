/*************************************************************************
	> File Name: 16.server.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 19时10分21秒
 ************************************************************************/
//用gcc编译
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>

/*struct Msg {
    pid_t pid;
    char msg[50];
};*/

struct Shm {
    pthread_mutex_t mutex;
    char buff[1024];
    pthread_cond_t cond;
};

struct Msg *share_msg = NULL;

/*void print(int sig) {
    printf("recv: %s\n", share_msg->msg);
    return ;
}*/

int main() {
    int shmid;

    key_t key = ftok(".", 2020);

    if ((shmid = shmget(key, sizeof(struct Shm), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return 1;
    }
    if ((share_msg = (struct Shm *)shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        return 1;
    }

    //share_msg->pid = getpid();

    /*while (1) {
        signal(SIGUSR2, print);
    }*/

    memset(share_msg, 0m sizeof(struct Shm));

    pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;

    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);

    pthread_mutexattr_setpshared(&m_attr, PTHREAD_PROGRESS_SHARED);
    pthread_condattr_setpshared(&c_attr, PTHREAD_PROGRESS_SHARED);

    pthread_mutex_init(&share_msg->mutex, &m_attr);
    pthread_cond_init(share_msg->cond, &c_attr);

    while (1) {
        pthread_mutex_lock(&share_msg->mutex);
        printf();

    }

    return 0;
}
