#include<stdio.h>
#include<stdlib.h>

int main(){
    int req[20];
    int head;
    int n;
    int seek=0;
    printf("Enter the number of req : ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("\nEnter the ith req : ");
        scanf("%d",&req[i+1]);
    }
    printf("\nEnter the head position : ");
    scanf("%d",&head);
    req[0]=head;

    for(int i=1; i<=n; i++){
        seek += abs(req[i]-req[i-1]);

    }
    printf("\nThe total seek time is : %d",seek);
    

}