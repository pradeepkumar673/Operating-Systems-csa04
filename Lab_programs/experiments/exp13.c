/* Construct a C program for implementation of the various memory allocation strategies. */
#include <stdio.h>
#define MAX 10
int mem[MAX],alloc[MAX],m;
void init(){printf("Number of blocks: ");scanf("%d",&m);for(int i=0;i<m;i++){printf("Block %d size: ",i+1);scanf("%d",&mem[i]);alloc[i]=-1;}}
void display(){printf("Block\tSize\tStatus\n");for(int i=0;i<m;i++)printf("%d\t%d\t%s\n",i+1,mem[i],alloc[i]==-1?"Free":"Allocated");}
void firstFit(int sz,int pid){for(int i=0;i<m;i++)if(alloc[i]==-1&&mem[i]>=sz){alloc[i]=pid;printf("FirstFit: P%d->Block%d\n",pid,i+1);return;}printf("No block\n");}
void bestFit(int sz,int pid){int b=-1;for(int i=0;i<m;i++)if(alloc[i]==-1&&mem[i]>=sz&&(b==-1||mem[i]<mem[b]))b=i;if(b!=-1){alloc[b]=pid;printf("BestFit: P%d->Block%d\n",pid,b+1);}else printf("No block\n");}
void worstFit(int sz,int pid){int w=-1;for(int i=0;i<m;i++)if(alloc[i]==-1&&mem[i]>=sz&&(w==-1||mem[i]>mem[w]))w=i;if(w!=-1){alloc[w]=pid;printf("WorstFit: P%d->Block%d\n",pid,w+1);}else printf("No block\n");}
int main(){
    init();int ch,sz,pid;
    do{printf("\n1.FirstFit 2.BestFit 3.WorstFit 4.Display 5.Exit: ");scanf("%d",&ch);
       if(ch>=1&&ch<=3){printf("PID: ");scanf("%d",&pid);printf("Size: ");scanf("%d",&sz);if(ch==1)firstFit(sz,pid);else if(ch==2)bestFit(sz,pid);else worstFit(sz,pid);}
       else if(ch==4)display();}while(ch!=5);
    return 0;
}
