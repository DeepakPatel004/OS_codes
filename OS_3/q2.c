#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

//sequantial execution

void *thread_fn(void* arg){
    int *x = (void *)arg;

    printf(" %d \n", x[0]+x[1]);
    
    return "hello";   //it will return a void pointer where hello written

    // pthread_exist("HELLO 2"); do same thing as return "HELLO";
}

int main(){
    pthread_t a_thread;
    void * result;
    int num[] = {1,2};

    pthread_create(&a_thread, NULL, thread_fn, (void*)num); // send num as void pointer

    pthread_join(a_thread,&result); //take return void pointer in our void pointer

    printf("%s",(char *)result); // convert our void pointer to char now
    
}

