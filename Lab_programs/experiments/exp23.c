/* Construct a C program to implement the first fit algorithm of memory management. */
#include <stdio.h>
#define MAX 10
int main(){
    int nb,np,bs[MAX],ps[MAX],alloc[MAX],temp[MAX];
    printf("Blocks: ");scanf("%d",&nb);printf("Block sizes: ");for(int i=0;i<nb;i++){scanf("%d",&bs[i]);temp[i]=bs[i];}
    printf("Processes: ");scanf("%d",&np);printf("Process sizes: ");for(int i=0;i<np;i++){scanf("%d",&ps[i]);alloc[i]=-1;}
    for(int i=0;i<np;i++)for(int j=0;j<nb;j++)if(temp[j]>=ps[i]){alloc[i]=j;temp[j]-=ps[i];break;}
    printf("\nProcess\tSize\tBlock\t\tStatus\n");
    for(int i=0;i<np;i++){if(alloc[i]!=-1)printf("P%d\t%d\tBlock %d\tAllocated\n",i+1,ps[i],alloc[i]+1);else printf("P%d\t%d\t-\t\tNot Allocated\n",i+1,ps[i]);}
    return 0;
}
