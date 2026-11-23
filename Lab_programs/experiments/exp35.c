/* Design a C program to simulate indexed file allocation strategy. */
#include <stdio.h>
#define MB 10
int idx[MB]; char blk[MB][100]; int bc=0;
int main(){
    int n;printf("Number of blocks: ");scanf("%d",&n);if(n>MB)n=MB;
    for(int i=0;i<n;i++){printf("Block %d data: ",i+1);scanf("%s",blk[i]);idx[i]=i;bc++;}
    printf("Index: ");for(int i=0;i<bc;i++)printf("[%d]->B%d ",i,idx[i]+1);printf("\n");
    int bn;printf("Block to read (0=quit): ");
    while(scanf("%d",&bn)==1&&bn){if(bn<1||bn>bc)printf("Invalid\n");else printf("Block %d: %s\n",bn,blk[idx[bn-1]]);printf("Block (0=quit): ");}
    return 0;
}
