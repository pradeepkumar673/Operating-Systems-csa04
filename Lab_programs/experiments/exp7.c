/* Construct a C program to implement a non-preemptive SJF algorithm. */
#include <stdio.h>
int main() {
    int n; printf("Enter number of processes: "); scanf("%d",&n);
    int at[20],bt[20],pr[20];
    for(int i=0;i<n;i++){printf("Arrival and Burst for P%d: ",i+1);scanf("%d %d",&at[i],&bt[i]);pr[i]=i+1;}
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(at[i]>at[j]){int t;t=at[i];at[i]=at[j];at[j]=t;t=bt[i];bt[i]=bt[j];bt[j]=t;t=pr[i];pr[i]=pr[j];pr[j]=t;}
    int time=0,over=0,sw=0,st=0;
    printf("\nProcess\tArrival\tBurst\tStart\tEnd\tWait\tTAT\n");
    while(over<n){
        int cnt=0;
        for(int i=over;i<n&&at[i]<=time;i++) cnt++;
        if(cnt>1) for(int i=over;i<over+cnt-1;i++) for(int j=i+1;j<over+cnt;j++) if(bt[i]>bt[j]){int t;t=at[i];at[i]=at[j];at[j]=t;t=bt[i];bt[i]=bt[j];bt[j]=t;t=pr[i];pr[i]=pr[j];pr[j]=t;}
        int s=time;time+=bt[over];
        int w=s-at[over],ta=time-at[over];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pr[over],at[over],bt[over],s,time,w,ta);
        sw+=w;st+=ta;over++;
    }
    printf("Avg WT: %.2f\nAvg TAT: %.2f\n",(float)sw/n,(float)st/n);
    return 0;
}
