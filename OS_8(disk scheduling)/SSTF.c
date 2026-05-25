#include<stdio.h>
#include<stdlib.h>

int main(){
    int req[50];
    int visited[50];
    int n;
    int seek=0;
    int head;

    printf("Enter the number of req : ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("\nEnter the ith req : ");
        scanf("%d",&req[i]);
        visited[i]=0;
    }
    printf("\nEnter the head position : ");
    scanf("%d",&head);

    for(int i=0; i<n; i++){
        int min =INT_MAX;
        int pos=-1;
        for(int j=0; j<n;j++ ){
            if(!visited[j]&& abs(req[j]-head)<min){
                pos = j;
                min = abs(req[j]-head);
            }
        }
        visited[pos]=1;
        seek += min;
        head = req[pos];
    }

    printf("\nThe total seek time is : %d",seek);





    
}