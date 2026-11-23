/* Construct a C program to implement the file management operations. */
#include <stdio.h>
#include <string.h>
int main(){
    char s[50],d[50],line[200]; int ch;
    do{printf("\n1.Create 2.Read 3.Copy 4.Delete 5.Exit: ");scanf("%d",&ch);getchar();
       if(ch==1){printf("Filename: ");fgets(s,50,stdin);s[strcspn(s,"\n")]=0;FILE*f=fopen(s,"w");if(!f){perror("fopen");continue;}printf("Content (end with '.'): ");while(fgets(line,200,stdin)&&line[0]!='.')fputs(line,f);fclose(f);}
       else if(ch==2){printf("Filename: ");fgets(s,50,stdin);s[strcspn(s,"\n")]=0;FILE*f=fopen(s,"r");if(!f){perror("fopen");continue;}while(fgets(line,200,f))printf("%s",line);fclose(f);}
       else if(ch==3){printf("Src: ");fgets(s,50,stdin);s[strcspn(s,"\n")]=0;printf("Dst: ");fgets(d,50,stdin);d[strcspn(d,"\n")]=0;FILE*f1=fopen(s,"r"),*f2=fopen(d,"w");if(!f1||!f2){perror("fopen");continue;}char c;while((c=fgetc(f1))!=EOF)fputc(c,f2);fclose(f1);fclose(f2);printf("Copied.\n");}
       else if(ch==4){printf("Filename: ");fgets(s,50,stdin);s[strcspn(s,"\n")]=0;if(remove(s)==0)printf("Deleted.\n");else perror("remove");}}while(ch!=5);
    return 0;
}
