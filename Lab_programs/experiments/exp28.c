/* Write a C program for simulation of GREP UNIX command. */
#include <stdio.h>
#include <string.h>
void search(const char*pat,const char*file){
    FILE*fp=fopen(file,"r");if(!fp){perror("fopen");return;}
    char line[500];int ln=0;
    while(fgets(line,500,fp)){ln++;if(strstr(line,pat))printf("%s:%d: %s",file,ln,line);}
    fclose(fp);
}
int main(int argc,char*argv[]){
    if(argc<3){printf("Usage: %s <pattern> <file>\n",argv[0]);return 1;}
    search(argv[1],argv[2]);return 0;
}
