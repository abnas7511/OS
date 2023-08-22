#include<stdio.h>
 void main() 
 {
    int nb,np,bs[10],ps[10],i,j,allocation[10];
    for(i=0;i<10;i++)
    {
      allocation[i]=-1;
    }
    printf("enter the no of blocks");
    scanf("%d",&nb);
    printf("enter the no of process");
    scanf("%d",&np);
 
    printf("enter the block size");
    for(i=1;i<=nb;i++)
    {
      printf("block %d:",i);
       scanf("%d",&bs[i]);
    }
    printf("enter the process size");
    for(i=1;i<=np;i++)
    {
      printf("process %d:",i); 
      scanf("%d",&ps[i]);
    }
    for(i=1;i<=np;i++) 
    {
     for(j=1;j<=nb;j++) 
     {
       if(bs[j]>=ps[i]) 
       {
        allocation[i]=j;
        bs[j]-=ps[i];
        break;
       }
     }
    }
    printf("\nProcess no.\tProcess size\tblock no.\n");
    for(i=1;i<=np;i++) 
    {
     if(allocation[i]!=-1) 
     {
       printf("%d\t%d\t%d",i,ps[i],allocation[i]);
       printf("\n");
     }
     else 
     {
       printf("%d\t%d\tnot allocated",i,ps[i]);
       printf("\n");
      }
    }
}