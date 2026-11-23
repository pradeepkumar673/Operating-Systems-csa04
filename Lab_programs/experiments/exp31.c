/* Construct a C program to simulate the First in First Out paging technique of memory management. */
#include <stdio.h>
#define F 3
void printF(int f[]){for(int i=0;i<F;i++)if(f[i]!=-1)printf("%d ",f[i]);else printf("- ");printf("\n");}
int main(){
    int ref[]={7,0,1,2,0,3,0,4,2,3,0,3,2},n=sizeof(ref)/sizeof(ref[0]);
    int f[F],ptr=0,faults=0;for(int i=0;i<F;i++)f[i]=-1;
    printf("Page\tFrames\t\tFault?\n");
    for(int i=0;i<n;i++){int pg=ref[i],found=0;for(int j=0;j<F;j++)if(f[j]==pg){found=1;break;}
        printf("%d\t",pg);if(!found){f[ptr]=pg;ptr=(ptr+1)%F;faults++;printF(f);printf("FAULT");}else printF(f);printf("\n");}
    printf("Page Faults: %d\n",faults);return 0;
}
