/* Construct a C program to simulate the First Come First Served disk scheduling algorithm. */
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,head;printf("Requests: ");scanf("%d",&n);int q[100];printf("Enter: ");for(int i=0;i<n;i++)scanf("%d",&q[i]);printf("Head: ");scanf("%d",&head);
    int seek=0;printf("Movement: %d",head);
    for(int i=0;i<n;i++){seek+=abs(head-q[i]);head=q[i];printf("->%d",head);}
    printf("\nTotal Seek: %d\nAvg Seek: %.2f\n",seek,(float)seek/n);return 0;
}
