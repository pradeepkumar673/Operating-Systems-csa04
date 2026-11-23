/* Construct a C program to simulate the Least Recently Used paging technique of memory management. */
#include <stdio.h>
#define F 3
void printF(int f[]){for(int i=0;i<F;i++)if(f[i]!=-1)printf("%d ",f[i]);else printf("- ");printf("\n");}
int main(){
    int ref[]={7,0,1,2,0,3,0,4,2,3,0,3,2},n=sizeof(ref)/sizeof(ref[0]);
    int f[F],lu[F],faults=0;for(int i=0;i<F;i++){f[i]=-1;lu[i]=-1;}
    printf("Page\tFrames\t\tFault?\n");
    for(int i=0;i<n;i++){int pg=ref[i],found=0,lru=0,emp=-1;
        for(int j=0;j<F;j++)if(f[j]==pg){found=1;lu[j]=i;break;}
        printf("%d\t",pg);
        if(!found){for(int j=0;j<F;j++)if(f[j]==-1){emp=j;break;}
            if(emp!=-1){f[emp]=pg;lu[emp]=i;}else{for(int j=1;j<F;j++)if(lu[j]<lu[lru])lru=j;f[lru]=pg;lu[lru]=i;}
            faults++;printF(f);printf("FAULT");}else printF(f);printf("\n");}
    printf("Page Faults: %d\n",faults);return 0;
}
