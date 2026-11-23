/* Construct a C program to implement preemptive priority scheduling algorithm. */
#include <stdio.h>
#include <limits.h>
#define MAX 10
struct Process { int pid, bt, priority, rem, done; };
int main() {
    int n; printf("Enter number of processes: "); scanf("%d",&n);
    struct Process p[MAX];
    for(int i=0;i<n;i++){p[i].pid=i+1;printf("BT and Priority for P%d: ",i+1);scanf("%d %d",&p[i].bt,&p[i].priority);p[i].rem=p[i].bt;p[i].done=0;}
    int time=0,completed=0,wt[MAX]={0},tat[MAX]={0};
    long tw=0,tt=0;
    while(completed<n){
        int hi=-1,mp=INT_MAX;
        for(int i=0;i<n;i++) if(!p[i].done&&p[i].rem>0&&p[i].priority<mp){mp=p[i].priority;hi=i;}
        if(hi==-1){time++;continue;}
        p[hi].rem--;time++;
        if(p[hi].rem==0){p[hi].done=1;completed++;tat[hi]=time;wt[hi]=tat[hi]-p[hi].bt;}
    }
    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for(int i=0;i<n;i++){tw+=wt[i];tt+=tat[i];printf("P%d\t%d\t%d\t\t%d\t%d\n",p[i].pid,p[i].bt,p[i].priority,wt[i],tat[i]);}
    printf("Avg WT: %.2f\nAvg TAT: %.2f\n",(double)tw/n,(double)tt/n);
    return 0;
}
