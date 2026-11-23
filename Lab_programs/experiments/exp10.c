/* Illustrate the concept of inter-process communication using message queue with a C program. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct Msg { long type; char text[100]; };
int main() {
    key_t key = ftok("msgqfile",65);
    int msgid = msgget(key,IPC_CREAT|0666);
    if(msgid==-1){perror("msgget");exit(1);}
    struct Msg m; m.type=1;
    strcpy(m.text,"Hello, message queue!");
    msgsnd(msgid,&m,sizeof(m.text),IPC_NOWAIT);
    printf("Sent:     %s\n",m.text);
    msgrcv(msgid,&m,sizeof(m.text),1,0);
    printf("Received: %s\n",m.text);
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}
