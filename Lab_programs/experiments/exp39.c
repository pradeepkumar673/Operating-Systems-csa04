/* Develop a C program to simulate C-SCAN disk scheduling algorithm. */
#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){
    int n,head;printf("Requests: ");scanf("%d",&n);int q[100];printf("Enter: ");for(int i=0;i<n;i++)scanf("%d",&q[i]);printf("Head: ");scanf("%d",&head);
    qsort(q,n,sizeof(int),cmp);int seek=0,cur=head;
    printf("Movement: %d",cur);
    for(int i=0;i<n;i++)if(q[i]>=cur){seek+=q[i]-cur;cur=q[i];printf("->%d",cur);}
    if(q[0]<head){seek+=cur;cur=0;for(int i=0;i<n;i++)if(q[i]<head){seek+=q[i]-cur;cur=q[i];printf("->%d",cur);}}
    printf("\nTotal Seek: %d\nAvg Seek: %.2f\n",seek,(float)seek/n);return 0;
}
