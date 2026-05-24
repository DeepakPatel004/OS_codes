#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){

    int fd = open("file.txt", O_RDONLY);  // open source file in read only mode
    
    char buff[10];

    int n = read(fd,buff,10);   // read 10 byte from source file

    int fd1 = open("file2.txt",O_CREAT | O_WRONLY, 0721); //open create destination file in read only mode

    write(fd1,buff,n); //write data into destination file

    close(fd1);
    close(fd); //close both files

}