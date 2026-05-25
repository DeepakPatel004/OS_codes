#include<stdio.h>

void calculateRR(int bt[],int n,int quantum){
    int rm_bt[n], tat[n],wt[n];
    int time = 0;
    for(int i=0; i<n; i++){
        rm_bt[i] = bt[i];
    }

    while(1){
        int found = 0;
        for(int i=0; i<n; i++){
            if(rm_bt[i]>0){
                found = 1;
            if(rm_bt[i]>quantum){
                rm_bt[i]-=quantum;
                time +=quantum;

            }
            else{
                time += rm_bt[i];
                rm_bt[i]=0;
                wt[i] = time-bt[i];
                tat[i] = time;

            }}
        }
        if(!found)break;
    }
    float avg_wt=0;
    float avg_tat = 0;
    for(int i=0; i<n; i++){
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\n avg wt : %f",avg_wt/n);
    printf("\n avg tat : %f",avg_tat/n);

}

int main(){
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];

    // Burst time of all processes
    int burst_time[] = {10, 5, 8};

    // Time quantum
    int quantum = 2;

    calculateRR(burst_time,n,quantum);
    
}