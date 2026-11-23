/* Illustrate the various File Access Permission and different types of users in Linux. */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
void printPerm(struct stat*s){
    printf("Permissions: ");
    printf((S_ISDIR(s->st_mode))?"d":"-");
    printf((s->st_mode&S_IRUSR)?"r":"-");printf((s->st_mode&S_IWUSR)?"w":"-");printf((s->st_mode&S_IXUSR)?"x":"-");
    printf((s->st_mode&S_IRGRP)?"r":"-");printf((s->st_mode&S_IWGRP)?"w":"-");printf((s->st_mode&S_IXGRP)?"x":"-");
    printf((s->st_mode&S_IROTH)?"r":"-");printf((s->st_mode&S_IWOTH)?"w":"-");printf((s->st_mode&S_IXOTH)?"x":"-");
    printf(" UID:%d GID:%d\n",s->st_uid,s->st_gid);
}
int main(){
    const char*f="perm_test.txt";FILE*fp=fopen(f,"w");if(!fp){perror("fopen");return 1;}fprintf(fp,"demo\n");fclose(fp);
    struct stat s;stat(f,&s);printf("Initial ");printPerm(&s);
    chmod(f,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);stat(f,&s);printf("chmod 644 ");printPerm(&s);
    chmod(f,S_IRWXU|S_IRGRP|S_IXGRP);stat(f,&s);printf("chmod 750 ");printPerm(&s);
    unlink(f);printf("File deleted.\n");
    printf("User types: Owner, Group, Others, Root(superuser)\n");
    return 0;
}
