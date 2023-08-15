/* 5. Write a program which performs interprocess communication using the concept of message queue. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define  MAX_TEXT 512

// message structure
struct my_msg_st
{
   long int my_msg_type;
   char some_text[MAX_TEXT];
};

int main() 
{
    key_t key;
    int msgid;
    struct my_msg_st msg;
    int iRet1 = 0;
    int iRet2 = 0;
    int cpid1 = 0;
    int cpid2 = 0;
    int EXIT_STATUS1 = 0;
    int EXIT_STATUS2 = 0;

    // Create a key for the message queue
    key = ftok(".", 'm');
    if (key == -1) 
    {
        printf("ftok");
        exit(1);
    }

    // Create or get the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) 
    {
        printf("msgget");
        exit(1);
    }

    // Sender process
    iRet1 = fork(); 
    if (iRet1 == 0)
    {
        msg.my_msg_type = 1; // Message type
        strcpy(msg.some_text, "Hello from sender process");
        msgsnd(msgid, &msg, sizeof(msg.some_text), 0);
        printf("Sender: Message sent\n");
        exit(0);
    }

    // Receiver process
    iRet2 = fork(); 
    if (iRet2 == 0)
    {
        msgrcv(msgid, &msg, sizeof(msg.some_text), 1, 0);
        printf("Receiver: Received message: %s\n", msg.some_text);
        exit(0);
    }

    // Wait for both child processes to finish
    iRet1 = wait(&EXIT_STATUS1);
    iRet2 = wait(&EXIT_STATUS1);

    // Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}

