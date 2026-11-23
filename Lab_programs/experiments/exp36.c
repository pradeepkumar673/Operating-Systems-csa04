/* Design a C program to simulate linked file allocation strategy. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Block{int no;char data[100];struct Block*next;};
int main(){
    struct Block*head=NULL,*last=NULL; int cnt=0; char d[100],ch;
    do{struct Block*b=malloc(sizeof(struct Block));b->no=++cnt;printf("Block %d data: ",cnt);scanf("%s",b->data);b->next=NULL;if(!head)head=last=b;else{last->next=b;last=b;}printf("More? (y/n): ");scanf(" %c",&ch);}while(ch=='y'||ch=='Y');
    printf("Linked file:\n");struct Block*c=head;while(c){printf("Block %d: %s\n",c->no,c->data);c=c->next;}
    int bn;printf("Block to access (0=quit): ");while(scanf("%d",&bn)==1&&bn){c=head;int f=0;while(c){if(c->no==bn){printf("%s\n",c->data);f=1;break;}c=c->next;}if(!f)printf("Not found\n");printf("Block (0=quit): ");}
    c=head;while(c){struct Block*nx=c->next;free(c);c=nx;}return 0;
}
