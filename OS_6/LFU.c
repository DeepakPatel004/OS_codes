#include<stdio.h>

int main(){
    int n;
    int pages[50];
    int frames[10];
    int freq[10];
    int f;
    int fault=0;

    printf("Enter number of frames : ");
    scanf("%d",&f);

    printf("\nenter number of pages : ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        scanf("%d",&pages[i]);
    }
    for(int i=0; i<n; i++){
        frames[i] = -1;
        freq[i] = 0;
    }

    for(int i=0; i<n; i++){
        int found = 0;
        for(int j=0; j<f; j++){
            if(pages[i]==frames[j]){
                found = 1;
                freq[j]++;
                break;
            }
        }
        if(!found){
            fault++;
            int min = freq[0], pos = 0;
            for(int j=1; j<f; j++){
                if(min>freq[j]){
                    pos = j;
                    min = freq[j];
                }
            }
            freq[pos] = 1;
            frames[pos] = pages[i];
        }
    }
    printf("\nNumber of faults : %d ",fault);
    printf("\nNumber of faults : %d ",n-fault);


}