#include<stdio.h>

int main(){
    int n;
    int f;
    int pages[50];
    int frames[10];
    int fault = 0;
    int index = 0;

    printf("enter number of pages : ");
    scanf("%d",&n);

    printf("Enter pages : ");
    for(int i=0; i<n; i++){
        scanf("%d",&pages[i]);
    }
    printf("Enter number of frames : ");
    scanf("%d",&f);

    for(int i=0; i<f; i++){
        frames[i] = -1;
    }

    for(int i=0; i<n; i++){
        int found = 0;
        for(int j=0; j<f; j++){
            if(frames[j]==pages[i]){
                found = 1;
                break;
                
            }
        }
        if(!found){
            fault++;
            frames[index] = pages[i];
            index = (index+1)%f;
        }
    }
    printf("total number of fault : %d", fault);
    printf("total number of hits : %d",n-fault);
    return 0;
}