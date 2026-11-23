/* Construct a C program to implement the I/O system calls of UNIX (fcntl, seek, stat, opendir, readdir). */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
int main(){
    const char *f="sample.txt"; char buf[20]; int fd,n;
    fd=open(f,O_CREAT|O_WRONLY|O_TRUNC,0644);write(fd,"Hello World\n",12);close(fd);
    fd=open(f,O_RDONLY);
    int flags=fcntl(fd,F_GETFL);printf("fcntl flags: %d\n",flags);
    lseek(fd,6,SEEK_SET);n=read(fd,buf,5);buf[n]=0;printf("lseek(6): %s\n",buf);close(fd);
    struct stat st;stat(f,&st);printf("Size: %lld bytes\n",(long long)st.st_size);
    DIR *dir=opendir("."); struct dirent *e;
    printf("Directory:\n");while((e=readdir(dir)))printf("  %s\n",e->d_name);closedir(dir);
    unlink(f);return 0;
}
