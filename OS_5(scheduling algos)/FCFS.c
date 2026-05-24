#include<stdio.h>


void calculateFCFS(int n, int bt[]){

    int wt[30];

    for(int i=0; i<n; i++){
        wt[i] = 0;
        for(int j=0; j<i; j++){
            wt[i] += bt[j];
        }
    }
    float avg_tat = 0;
    float avg_wt = 0;

    for(int i=0; i<n; i++){
        avg_tat += wt[i]+bt[i];
        avg_wt += wt[i];      
    }

    avg_tat = avg_tat/n;
    avg_wt = avg_wt/n;

    printf(" \n average tat is %f : ", avg_tat);
    printf(" \n average wt is %f : ", avg_wt);


}

int main(){
int n = 3;
int bt[] = {10, 5, 8};
calculateFCFS(n, bt);
    return 0;
}