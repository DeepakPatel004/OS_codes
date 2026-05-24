#include<stdio.h>

int main(){
    int n;
    int pages[50];
    int frames[10];
    int time[10];
    int counter = 0;
    int fault = 0;
    int f;

    printf("Enter the number of pages : ");
    scanf("%d",&n);
    printf("\nEnter pages : ");
    for(int i=0; i<n; i++){
        scanf("%d",&pages[i]);
    }
    printf("\nEnter the number of frames : ");
    scanf("%d",&f);
    for(int i=0; i<f; i++){
    frames[i] = -1;
    time[i] = 0;
}

    for(int i=0; i<n; i++){
        int found = 0;
        for(int j=0; j<f; j++){
            if(frames[j]==pages[i]){
                found=1;
                counter++;
                time[j] = counter;
                break;
            }
        }
        if(!found){
            fault++;
            int min = time[0],pos=0;
            for(int j=1; j<f; j++){
                if(min>time[j]){
                    pos=j;
                    min= time[j];
                }
            }
            counter++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

    }
    printf("\n Number of faults : %d", fault);
    printf("\n Number of hits : %d",n-fault);

}