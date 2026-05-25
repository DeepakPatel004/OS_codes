#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    
    pid_t pid = fork();
    if(pid<0){
        printf("fork failed \n");
    }
    else if(pid==0){
        printf("This is child process PID: %d PPID: %d\n",getpid(),getppid());
    }
    else{
        printf("this is parent process PID: %d  PPID: %d",getpid(),getppid());
    }

}