#include<stdio.h>

int swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=*a;
}
 
void main()
{
    int n , i,j,cmpt,min;
    float twt=0,ttat=0;
    printf("enter the number of procesess");
    scanf("%d",&n);
    int a[n][5];
    printf("enter the process id, arrival and burst time for each process\n");
    for(i=0;i<n;i++)
    {
      printf("process id:");
      scanf("%d",a[i][0]);
      printf("\n arrival time for process %d: ",a[i][0]);
      scanf("%d",a[i][1]);
      printf("\nburst time for process %d:",a[i][0]);
      scanf("%d",a[i][2]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j][1]>a[j+1][1])
            {
                swap(a[j][0],a[j+1][0]);
                swap(a[j][1],a[j+1][1]);
                swap(a[j][2],a[j+1][2]);
            }
            if(a[j][1]==a[j+1][1] && a[j][2]>a[j+1][2])
            {
                swap(a[j][0],a[j+1][0]);
                swap(a[j][1],a[j+1][1]);
                swap(a[j][2],a[j+1][2]);
            }
        }
    }
    cmpt= a[0][1]+a[0][2];
    a[0][3]=cmpt-a[0][1];
    a[0][4]=a[0][3]-a[0][2];
    twt+=a[0][4];
    ttat+=a[0][3];

    for(i=1;i<n;i++)
    {
      min=a[i][2];
      for(j=i+1;j<n;j++)
      {
        if(min >a[j][2] && a[j][1]<=cmpt)
        {
            min=a[j][2];
            swap(a[i][0],a[j][0]);
            swap(a[i][1],a[j][1]);
            swap(a[i][2],a[j][2]);
        }
      }
      if(a[j][1]>cmpt)
      {
        cmpt = a[i][1]+a[i][2];
      }else{
        cmpt+=a[i][2];
      }
      a[i][3]=cmpt-a[i][1];
      a[i][4]=a[i][3]-a[i][2];
      twt+=a[i][3];
      ttat+=a[i][4];
    }
}