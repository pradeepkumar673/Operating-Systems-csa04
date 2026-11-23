/* Illustrate the deadlock avoidance concept by simulating Banker's algorithm with C. */
#include <stdio.h>
#define MP 10
#define MR 10
int main(){
    int n,m; printf("Processes: ");scanf("%d",&n);printf("Resources: ");scanf("%d",&m);
    int alloc[MP][MR],maxr[MP][MR],avail[MR],need[MP][MR],finish[MP],safe[MP];
    printf("Allocation matrix:\n");for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&alloc[i][j]);
    printf("Max matrix:\n");for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&maxr[i][j]);
    printf("Available: ");for(int j=0;j<m;j++)scanf("%d",&avail[j]);
    for(int i=0;i<n;i++){finish[i]=0;for(int j=0;j<m;j++)need[i][j]=maxr[i][j]-alloc[i][j];}
    int cnt=0;
    while(cnt<n){int found=0;for(int i=0;i<n;i++)if(!finish[i]){int ok=1;for(int j=0;j<m;j++)if(need[i][j]>avail[j]){ok=0;break;}if(ok){for(int j=0;j<m;j++)avail[j]+=alloc[i][j];safe[cnt++]=i;finish[i]=1;found=1;}}if(!found)break;}
    if(cnt==n){printf("SAFE state. Sequence: ");for(int i=0;i<n;i++)printf("P%d%s",safe[i],i<n-1?"->":"\n");}
    else printf("NOT safe (deadlock possible)\n");
    return 0;
}
