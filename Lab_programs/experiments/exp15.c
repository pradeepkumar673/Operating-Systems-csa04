/* Design a C program to organise the file using a two level directory structure. */
#include <stdio.h>
#include <string.h>
#define MU 5
#define MF 10
char users[MU][20],files[MU][MF][30]; int fc[MU],uc=0;
int findU(char*u){for(int i=0;i<uc;i++)if(!strcmp(users[i],u))return i;return -1;}
void addUser(char*u){if(uc>=MU||findU(u)>=0){printf("Error\n");return;}strcpy(users[uc],u);fc[uc]=0;uc++;printf("User %s created\n",u);}
void addFile(char*u,char*f){int i=findU(u);if(i<0){printf("User not found\n");return;}if(fc[i]>=MF){printf("Full\n");return;}strcpy(files[i][fc[i]++],f);printf("File %s created under %s\n",f,u);}
void listFiles(char*u){int i=findU(u);if(i<0){printf("User not found\n");return;}for(int j=0;j<fc[i];j++)printf("  %s\n",files[i][j]);}
int main(){
    int ch; char u[20],f[30];
    do{printf("\n1.AddUser 2.AddFile 3.List 4.Exit: ");scanf("%d",&ch);
       if(ch==1){printf("User: ");scanf("%s",u);addUser(u);}
       else if(ch==2){printf("User: ");scanf("%s",u);printf("File: ");scanf("%s",f);addFile(u,f);}
       else if(ch==3){printf("User: ");scanf("%s",u);listFiles(u);}}while(ch!=4);
    return 0;
}
