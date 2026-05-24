#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


int shared = 0;
int flag[2] = {0,0};
int turn = 0;



void *peterson_fun(void* arg){
    int i = (int)(long)arg;
    int j = 1-i;

    for(int cnt = 0; cnt<3; cnt++){
        flag[i] = 1;
        turn = j;

        while(flag[j] && turn==j){}
        shared ++;
        printf("shared variable updated by %d to %d \n ", i, shared);

        sleep(1);
        flag[i] = 0;
        printf("thread %d left cs \n",i);
        sleep(1);
    }
}

int main(){
    pthread_t t1,t2;

    pthread_create(&t1, NULL, peterson_fun, (void *)0);
    pthread_create(&t2, NULL, peterson_fun, (void *)1);

    pthread_join(t1, NULL);
    pthread_join(t2,NULL);

    return 0;
}