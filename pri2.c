#include<stdio.h>
#include<stdlib.h>

int mutex = 1, empty=5,full=0,x=0;


void producer(){
    --mutex;
    ++full;
    --empty;
    x++;
    printf("producer produces: item%d",x);
    mutex++;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("consumer consumes : item%d",x);
    --x;
    ++mutex;
}

void main()
{
  int n,i;
  printf("\n1.Producer\n2.Consumer\n3.Exit");
  for(i=1;i<n;i++)
  {
    printf("entre yoyr choice");
    scanf("%d",&n);
    switch (n)
    {
    case 1: if((mutex == 1)&&(empty!=0))
             producer();
            else {
              printf("buffer full");
              break;
            }
             
    case 2: if(mutex==1 && full!=0)
             consumer();
            else{
                printf("buffer enmpty");
                break;
            }
    
    case 3: exit(0);
        break;
    }
  }
}