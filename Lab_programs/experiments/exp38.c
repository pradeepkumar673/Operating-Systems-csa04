/* Design a C program to simulate SCAN disk scheduling algorithm. */
#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){
    int n,head;printf("Requests: ");scanf("%d",&n);int q[100];printf("Enter: ");for(int i=0;i<n;i++)scanf("%d",&q[i]);printf("Head: ");scanf("%d",&head);
    qsort(q,n,sizeof(int),cmp);int seek=0,cur=head;
    printf("Movement: %d",cur);
    for(int i=0;i<n;i++)if(q[i]>=cur){seek+=q[i]-cur;cur=q[i];printf("->%d",cur);}
    for(int i=n-1;i>=0;i--)if(q[i]<head){seek+=abs(cur-q[i]);cur=q[i];printf("->%d",cur);}
    printf("\nTotal Seek: %d\nAvg Seek: %.2f\n",seek,(float)seek/n);return 0;
}
