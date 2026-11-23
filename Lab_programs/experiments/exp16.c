/* Develop a C program for implementing random access file for processing the employee details. */
#include <stdio.h>
struct Emp { int id; char name[30]; float sal; };
int main(){
    FILE *fp=fopen("emp.dat","wb+");
    if(!fp){perror("fopen");return 1;}
    struct Emp e; int ch,rec;
    do{printf("\n1.Add 2.View 3.Modify 4.Exit: ");scanf("%d",&ch);
       if(ch==1){printf("ID: ");scanf("%d",&e.id);printf("Name: ");scanf("%s",e.name);printf("Salary: ");scanf("%f",&e.sal);fseek(fp,(e.id-1)*sizeof(e),SEEK_SET);fwrite(&e,sizeof(e),1,fp);printf("Saved.\n");}
       else if(ch==2){printf("ID: ");scanf("%d",&rec);fseek(fp,(rec-1)*sizeof(e),SEEK_SET);if(fread(&e,sizeof(e),1,fp))printf("ID:%d Name:%s Sal:%.2f\n",e.id,e.name,e.sal);else printf("Not found\n");}
       else if(ch==3){printf("ID: ");scanf("%d",&rec);printf("New Name: ");scanf("%s",e.name);printf("New Salary: ");scanf("%f",&e.sal);e.id=rec;fseek(fp,(rec-1)*sizeof(e),SEEK_SET);fwrite(&e,sizeof(e),1,fp);printf("Updated.\n");}}while(ch!=4);
    fclose(fp); return 0;
}
