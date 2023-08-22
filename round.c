#include<stdio.h>

int q[100];
int f =-1;
int r=-1;

void insert(int n)
{
        if(f==-1)
         f=0;
        else{
                r=r+1;
                q[r]=n;
        }
}

int delete()
{
        int n;
        n=q[f];
        f=f+1;
        return n;
}

void main()
{
        int n,i,tq,t=0,p;
        float twt,ttat;
        printf("enter no of processe");
        scanf("%d",&n);
        int a[n][5],b[10],exist[10]={0};
        printf("Enter arrival and burst for each process:\n");
        for (i = 0; i < n; i++) {
           printf("\nProcess ID: ");
           scanf("%d", &a[i][0]);
           printf("Enter arrival time of %dth process: ", a[i][0]);
           scanf("%d", &a[i][1]);
           printf("Enter the burst time of %dth process: ", a[i][0]);
           scanf("%d", &a[i][2]);
            b[i] = a[i][2]; 
        }
        printf("enter the time quantum");
        scanf("%d",&tq);

        insert(0);
        exist[0]=1;

        while(f<=r)
        {
                p= delete();
                if(a[p][2]>=tq)
                {
                        a[p][2]-=tq;
                        t+=tq;
                }else{
                        t+=a[p][2];
                        a[p][2]=0;
                }
                for(i=0;i<n;i++)
                {
                        if(exist[i]==0 && a[i][1]<=t)
                        {
                                insert(i);
                                exist[i]=1;
                        }
                }
                if(a[p][2]==0)
                {
                        a[i][3]=t -a[p][1];
                        a[i][4]=a[i][3]-b[p];
                        twt+=a[i][4];
                        ttat+=a[i][3];
                }else{
                        insert(p);
                }

                //whilw printing check for b[i]
        }
}