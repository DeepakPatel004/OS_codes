#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>


int shared = 1;
sem_t s;

void *fun1(void * arg){
    int x;

    sem_wait(&s);

    x = shared;
    printf(" thread 1 local variable read shared varaible as %d \n",x);

    sleep(1);
    x++;
    printf("thread 1 local variable updated to %d \n",x);

    shared = x;

    printf(" thread 1 shared variable updated to %d \n",shared);

    sem_post(&s);

}
void *fun2(void * arg){
    int x;

    sem_wait(&s);

    x = shared;
    printf("thread 2 local variable read shared varaible as %d \n",x);

    sleep(1);
    x--;
    printf("thread 2 local variable updated to %d \n",x);

    shared = x;

    printf("thread 2 shared variable updated to %d \n",shared);

    sem_post(&s);

}

int main(){
    sem_init(&s, 0,1);

    pthread_t athread;
    pthread_t bthread;

    pthread_create(&athread, NULL, fun1, NULL);
    pthread_create(&bthread, NULL, fun2, NULL);

    pthread_join(athread,NULL);
    pthread_join(bthread,NULL);

    printf("final value of shared varaible is %d",shared);

    sem_destroy(&s);

}