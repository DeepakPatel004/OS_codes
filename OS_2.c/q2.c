#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    
    int fd = open("file.txt",O_RDONLY);
    if(fd<0){
        printf("file did not open \n");
        return 0;
    }

    char buff[10];
    
    int n = read(fd,buff,10 );

    write(1,buff,n);

    close(fd);
    return 0;
}

