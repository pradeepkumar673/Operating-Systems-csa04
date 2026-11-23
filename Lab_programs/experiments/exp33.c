/* Construct a C program to simulate the optimal paging technique of memory management. */
#include <stdio.h>
#define F 3
void printF(int f[]){for(int i=0;i<F;i++)if(f[i]!=-1)printf("%d ",f[i]);else printf("- ");printf("\n");}
int optimal(int f[],int ref[],int total,int from){int far=-1,rep=0;for(int i=0;i<F;i++){int j;for(j=from;j<total;j++)if(ref[j]==f[i])break;if(j>far){far=j;rep=i;}}return rep;}
int main(){
    int ref[]={7,0,1,2,0,3,0,4,2,3,0,3,2},n=sizeof(ref)/sizeof(ref[0]);
    int f[F],faults=0;for(int i=0;i<F;i++)f[i]=-1;
    printf("Page\tFrames\t\tFault?\n");
    for(int i=0;i<n;i++){int pg=ref[i],found=0,emp=-1;for(int j=0;j<F;j++)if(f[j]==pg){found=1;break;}
        printf("%d\t",pg);if(!found){for(int j=0;j<F;j++)if(f[j]==-1){emp=j;break;}
            int idx=(emp!=-1)?emp:optimal(f,ref,n,i+1);f[idx]=pg;faults++;printF(f);printf("FAULT");}else printF(f);printf("\n");}
    printf("Page Faults: %d\n",faults);return 0;
}
