#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

//concurrent execution

void *thread_fn(void* arg){
    for(int j=0; j<20; j++){
        printf("%d \n ",j);
        sleep(1);
    }
}

int main(){
    pthread_t a_thread;

    pthread_create(&a_thread, NULL, thread_fn, NULL);

    for(int i=0; i<20; i++){
        printf("%d \n",i);
        sleep(1);
    }
    pthread_join(a_thread,NULL);
}

