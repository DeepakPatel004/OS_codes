#include<stdio.h>

void calculateSJF(int n,int bt[]){

    int pid[n];
    for(int i=0; i<n; i++){
        pid[i] = i+1;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(bt[j]<bt[i]){
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;


                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    int wt[n];
    int tat[n];
    wt[0] = 0;
    tat[0] = bt[0];
    float avg_tat = 0;
    float avg_wt = 0;

    for(int i=1; i<n; i++){
        wt[i] = bt[i-1] + wt[i-1];
        tat[i] = wt[i] + bt[i];
    
    }
    for(int i=0; i<n; i++){
       avg_tat += tat[i];
       avg_wt += wt[i];
    
    }

    printf("\n avg tat : %f : ",avg_tat/n);
    printf("\n avg wt : %f : ",avg_wt/n);
}

int main(){
    int n = 4;
int bt[] = {6, 8, 7, 3};
calculateSJF(n, bt);
return 0;
}