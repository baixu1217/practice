#ifndef _COMM_H_
#define _COMM_H_

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

#define PATHNAME "."
#define PROJ_ID 0x6666
#define SERVER_TYPE 1
#define CLIENT_TYPE 2

struct msgbuf {
        long mtype;
        char mtext[1024];
};

int createMsgqueue();
int getMsg();
int destroyMsg(int msgid);
int recvMsg(int msgid,long recvtype,char out[]);
