/* Develop a C program for simulating the function of ls UNIX Command. */
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
int main(int argc,char*argv[]){
    const char*path=(argc>1)?argv[1]:".";
    DIR*dir=opendir(path);if(!dir){perror("opendir");return 1;}
    struct dirent*e; struct stat st; char full[512];
    while((e=readdir(dir))!=NULL){if(e->d_name[0]=='.')continue;snprintf(full,512,"%s/%s",path,e->d_name);stat(full,&st);printf("%-30s %lld bytes\n",e->d_name,(long long)st.st_size);}
    closedir(dir);return 0;
}
