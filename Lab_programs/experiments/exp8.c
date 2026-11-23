/* Construct a C program to simulate Round Robin scheduling algorithm with C. */
#include <stdio.h>
int main() {
    int n,quant; printf("Enter number of processes: "); scanf("%d",&n);
    int at[20],bt[20],temp[20];
    for(int i=0;i<n;i++){printf("Arrival and Burst for P%d: ",i+1);scanf("%d %d",&at[i],&bt[i]);temp[i]=bt[i];}
    printf("Time Quantum: "); scanf("%d",&quant);
    int wt=0,tat=0,sum=0,count=0,y=n,i=0;
    printf("\nProcess\tBurst\tTAT\tWaiting\n");
    for(sum=0,i=0;y!=0;){
        if(temp[i]<=quant&&temp[i]>0){sum+=temp[i];temp[i]=0;count=1;}
        else if(temp[i]>0){temp[i]-=quant;sum+=quant;}
        if(temp[i]==0&&count==1){y--;printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);wt+=sum-at[i]-bt[i];tat+=sum-at[i];count=0;}
        if(i==n-1) i=0;
        else if(at[i+1]<=sum) i++;
        else i=0;
    }
    printf("Avg TAT: %.2f\nAvg WT: %.2f\n",(float)tat/n,(float)wt/n);
    return 0;
}
