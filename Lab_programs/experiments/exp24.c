/* Design a C program to demonstrate UNIX system calls for file management. */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(){
    const char *f="testfile.txt"; char buf[100]; int fd,n;
    fd=open(f,O_CREAT|O_WRONLY|O_TRUNC,0644);
    const char *msg="Hello UNIX file management!\n";
    write(fd,msg,strlen(msg));close(fd);printf("Written.\n");
    fd=open(f,O_RDONLY);n=read(fd,buf,sizeof(buf)-1);buf[n]=0;printf("Read: %s",buf);close(fd);
    fd=open(f,O_RDONLY);lseek(fd,6,SEEK_SET);n=read(fd,buf,4);buf[n]=0;printf("After lseek(6): %s\n",buf);close(fd);
    rename(f,"testfile2.txt");printf("Renamed.\n");
    unlink("testfile2.txt");printf("Deleted.\n");
    return 0;
}
