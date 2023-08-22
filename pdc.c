#include<stdio.h>
#include<stdlib.h>

int mutex=1,empty=5,x=0,full=0;

void producer()
{
 --mutex;
 ++full;
 --empty;
 x++;
 printf("\nProducer produces: item%d",x);
 ++mutex;  
 }

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\n Consumer consumes: item%d",x);
    x--;
    ++mutex;
}

void main()
{
    int n,i;
    printf("\n1.producer\n2.consumer\n3.exit\n");
    for ( i = 1; i >0; i++)
    {
        printf("\nenter your choice");
        scanf("%d",&n);
        switch (n)
        {
        case 1 :if ((mutex==1)&&(empty!=0))
        {
            producer();
        }
        else
           printf("Buffer is full");
         break;
        case 2: if((mutex==1)&&(full!=0))
        {
            consumer();
        }
        else
           printf("buffer is empty");
         break;
        
        case 3: exit(0);
            break;
        }
    }
    
}

