#include<stdio.h>
#include<stdlib.h>
void main() 
{
 int i,n,req[100],initial,thm=0;
 printf("enter the number of request");
 scanf("%d",&n);
 
 printf("\nenter the requests\n");
 for(i=0;i<n;i++) 
 {
  scanf("%d",&req[i]);
  }
  
  printf("\nenter the initial head position "); 
  scanf("%d",&initial);
  
 for(i=0;i<n;i++) 
 {
  thm = thm + abs(req[i] - initial);
  initial = req[i];
 }
 
  printf("\ntotal head movements: %d",thm);
 
  printf("seek sequence is\n");
  for(i=0;i<n;i++) {
   printf("%d\t",req[i]);
 }
 }

 #include<stdio.h>
 #include<stdlib.h>

 void main()
 {
  int n,initial,i,req[10],thm;
  printf("enter the number of sequence");
  scanf("%d",&n);

  printf("enter the requests");
  for(i=0;i<n;i++);
   scanf("%d",&req[i]);
  printf("enter the initial pos");
  scanf("%d",&initial);
  for(i=0;i<n;i++)
  {
    thm=thm+abs(req[i]-initial);
    initial=req[i];
  }
  printf("total head movements %d",thm);
  printf("seek sequence is\n");
  for(i=0;i<n;i++)
   printf("%d\t",req[i]);
  
 }  