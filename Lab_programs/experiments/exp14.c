/* Construct a C program to organise the file using a single level directory. */
#include <stdio.h>
#include <string.h>
#define MAX 20
char dir[MAX][50]; int fc=0;
void create(char*n){if(fc>=MAX){printf("Full\n");return;}strcpy(dir[fc++],n);printf("Created: %s\n",n);}
void del(char*n){for(int i=0;i<fc;i++)if(!strcmp(dir[i],n)){for(int j=i;j<fc-1;j++)strcpy(dir[j],dir[j+1]);fc--;printf("Deleted: %s\n",n);return;}printf("Not found\n");}
void list(){printf("Files:\n");for(int i=0;i<fc;i++)printf("  %s\n",dir[i]);}
int main(){
    int ch; char n[50];
    do{printf("\n1.Create 2.Delete 3.List 4.Exit: ");scanf("%d",&ch);
       if(ch==1){printf("Name: ");scanf("%s",n);create(n);}
       else if(ch==2){printf("Name: ");scanf("%s",n);del(n);}
       else if(ch==3)list();}while(ch!=4);
    return 0;
}
