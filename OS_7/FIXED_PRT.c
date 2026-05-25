 #include<stdio.h>

 int main(){
    int ms,nob,bs;
    int mp[10];
    int n;
    int iff=0;
    printf("Enter memory size : ");
    scanf("%d",&ms);

    printf("\nEnter the size of one block : ");
    scanf("%d",&bs);

    nob = ms/bs;
    int ef = ms - (nob*bs);

    printf("\nEnter the number of processer: ");
    scanf("%d",&n);
    int p = 0;
    int i=0;
    for(i=0; i<n && p<nob; i++){
        printf("\nEnter the size of %d process : ",i+1);
        scanf("%d",&mp[i]);

        if(mp[i]<=bs){
            p++;
            printf("\nsuccessfully memory allocated : ");
            iff += (bs-mp[i]);
        }
        else{
              printf("\nMemory size id big than block size: ");
        }

    }
    if(i<n-1){
        printf("\nMemory got full");
    }
    printf("\ntotal internal fragementation : %d ",iff);


 }