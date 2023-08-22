#include<stdio.h>
void swap(int *a,int *b)
{
 int temp;
 temp = *a;
 *a=*b;
 *b=temp;
}

int main()
{
 int i,j,n,cmpt;
 float twt=0,ttat=0;
 printf("enter the number of processes");
 scanf("%d",&n);
 
 int a[n][6];
 
 printf("enter the A.T and B.T for each process");
 for(i=0;i<n;i++)
 {
  printf("Process ID");
  scanf("%d",&a[i][0]);
 
  printf("enter the arrival time:- ");
  scanf("%d",&a[i][1]);
 
  printf("enter the burst time:- ");
  scanf("%d",&a[i][2]);
 
  printf("enter the priority:- ");
  scanf("%d",&a[i][5]);
 }
 
 for(i=0;i<n;i++)
 { for(j=0;j<n-i-1;j++)
   {
    if(a[j][1]>a[j+1][1])
    {
     swap(&a[j][0],&a[j+1][0]);
     swap(&a[j][1],&a[j+1][1]);
     swap(&a[j][2],&a[j+1][2]);
     swap(&a[j][5],&a[j+1][5]);
    }
   }
  }
 
 a[0][3]=a[0][1];
 a[0][4]=a[0][2]-a[0][1];
 cmpt=a[0][4];
 twt=twt+a[0][3];
 ttat=ttat+a[0][4];
 
 for(i=1;i<n;i++)
 { int min=a[i][5];
   for(j=i+1;j<n;j++)
   { if(min>a[j][5] && a[j][1]<=cmpt)
     {
      min = a[j][5];
      swap(&a[i][0],&a[j][0]);
      swap(&a[i][1],&a[j][1]);
      swap(&a[i][2],&a[j][2]);
      swap(&a[j][5],&a[j][5]);
     }
    }
   a[i][3]=cmpt-a[i][1];
   twt=twt+a[i][3];
   cmpt=cmpt+a[i][2];
   a[i][4]=cmpt-a[i][1];
   ttat=ttat+a[i][4];
 }
 
 printf("Process\t A.T\t B.T\t Priority\t T.T\t W.T\n");
 for(i=0;i<n;i++)
 {
  printf("%d\t %d\t %d\t %d\t %d\t %d\n",a[i][0],a[i][1],a[i][2],a[i][5],a[i][4],a[i][3]);
 }
 printf("Average waiting time = %f\n",twt/n);
 printf("\nAverage turn around time = %f",ttat/n);
 }
