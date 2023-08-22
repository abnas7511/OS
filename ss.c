#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
   void*shared_memory;
   char buffer[100];
   int shmid;
   shmid=shmget((key_t)1222,1024,1666|IPC_CREAT);
   printf("key of the process attached is %d\n",shmid);
   shared_memory = shmat(shmid,NULL,0);
   printf("process attached at %p\n",shared_memory);
   printf("enter the data to write at memory");
   read(0,buffer,100);
   strcpy(shared_memory,buffer);
   printf("you wrote %s",(char*)shared_memory);
   return 0;
}

/*int main()
{
   void*shared_memory;
   char buffer[100];
   int shmid;
   shmid=shmget((key_t)1222,1024,1666|IPC_CREAT);
   printf("key of the process attached is %d\n",shmid);
   shared_memory = shmat(shmid,NULL,0);
   printf("process attached at %p\n",shared_memory);
   printf("the data read from the memory is %s\n",(char*)shared_memory);
   */