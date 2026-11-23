/* Design a C program to simulate sequential file allocation strategy. */
#include <stdio.h>
#include <string.h>
struct Rec{int no;char data[50];};
int main(){
    FILE*fp=fopen("seq.dat","wb+");if(!fp){perror("fopen");return 1;}
    int no; char d[50];
    printf("Enter records (no=0 to stop):\n");
    while(1){printf("No: ");scanf("%d",&no);if(!no)break;printf("Data: ");scanf("%s",d);struct Rec r={no,""}; strcpy(r.data,d);fwrite(&r,sizeof(r),1,fp);}
    printf("Sequential read:\n");rewind(fp);struct Rec r;while(fread(&r,sizeof(r),1,fp))printf("Rec %d: %s\n",r.no,r.data);
    printf("Enter no to access (0=quit): ");while(scanf("%d",&no)==1&&no){rewind(fp);int f=0;while(fread(&r,sizeof(r),1,fp))if(r.no==no){printf("%s\n",r.data);f=1;break;}if(!f)printf("Not found\n");printf("No (0=quit): ");}
    fclose(fp);remove("seq.dat");return 0;
}
