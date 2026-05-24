#include<stdio.h>

void calculatePriority(int n, int bt[], int pt[]){

    int PID[n];

    for(int i=0; i<n; i++){
        PID[i] = i+1;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(pt[j]<pt[i]){
                int temp = pt[i];
                pt[i] = pt[j];
                pt[j] = temp;

                temp = PID[i];
                PID[i] = PID[j];
                PID[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;


            }
        }
    }

    int wt[n];
    int tat[n];
    wt[0] = 0;
    tat[0] = bt[0];

    for(int i=1; i<n; i++){
        wt[i] = bt[i-1] + wt[i-1];
        tat[i] = bt[i] + wt[i];

    }
    float avg_tat = 0;
    float avg_wt = 0;

    for(int i=0; i<n; i++){
        avg_wt+= wt[i];
        avg_tat += tat[i];
        }
    printf("\n AVG tat %f : ", avg_wt/n);
    printf("\n AVG wt %f : ", avg_tat/n);
    

}

int main(){
    int n = 3;
int bt[] = {10, 5, 8};
int pr[] = {2, 1, 3};
calculatePriority(n, bt, pr);
return 0;

}