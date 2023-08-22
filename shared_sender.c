#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
    void*shared_memory;
    char buffer[100];
    int shmid;
    shmid=shmget((key_t)1222,1024,1666|IPC_CREAT);
    printf("key of the shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("process attached at %p\n",shared_memory);
    printf("enter some data to write in shared memory");
    read(0,buffer,100);
    strcpy(shared_memory,buffer);
    printf("you wrote: %s",(char*)shared_memory);
    return 0;
}