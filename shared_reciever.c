#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    void*shared_memory;
    int shmid;
    char buffer[100];
    shmid=shmget((key_t)1222,1024,1666);
    printf("key of the shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("process is attached at %p\n",shared_memory);
    printf("data read from shared memory is : %s\n",(char*)shared_memory);
    return 0;
}