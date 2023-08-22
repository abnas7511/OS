#include<stdio.h>
void main()
{ int ninst, np, i, j, c;
  printf("Enter the number of processes: ");
  scanf("%d", &np);
  printf("Enter the number of resource instances: ");
  scanf("%d", &ninst);
  // Inputting Allocation & Max Matrix
  int allocmat[np][ninst], max[np][ninst], Available[ninst];
  printf("Input the Allocation Matrix:\n");
  for(i = 0; i < np; i++)
  {
   for(j = 0; j < ninst; j++)
   {
     scanf("%d", &allocmat[i][j]);
    }
  }
   printf("Input the Max Matrix:\n");
   for(i = 0; i < np; i++)
   {
     for(j = 0; j < ninst; j++)
      scanf("%d", &max[i][j]); 
    }
    printf("\nInput the Available Matrix:\n");
    for(i = 0; i < ninst; i++)
      scanf("%d", &Available[i]); 
    // Calculate need matrix
    int need[np][ninst];
    for(i = 0; i < np; i++)
     { 
       for(j = 0; j < ninst; j++)
       {
         need[i][j] = max[i][j] - allocmat[i][j];
        } 
      }
      printf("\nNeed Matrix:\n");
      for(i = 0; i < np; i++)
      {
         printf("\t\n");
        for(j = 0; j < ninst; j++)
        {
          printf("%d\t", need[i][j]); 
        } 
      }
      int flag, y, completed[np], safeseq[np], index = 0;

      for(i = 0; i < np; i++)
      {
        completed[i] = 0;
      }
      for(c = 0; c < np; c++)
      {
        for(i = 0; i < np; i++)
        {
          if(completed[i] == 0)
          {
            flag = 0;
            for(j = 0; j < ninst; j++)
            {
              if(need[i][j] > Available[j])
               {
                 flag = 1;
                 break;
                }
            }
            if(flag == 0)
            { 
              safeseq[index++] = i;
              for(y = 0; y < ninst; y++)
              {
               Available[y] += allocmat[i][y];
              }
              completed[i] = 1;
            }
          }
        }
      }
      printf("\n\nSafe Sequence is:\n\t");
      for(i = 0; i < np - 1; i++)
      {
        printf("P%d -> ", safeseq[i]);
      }
      printf("P%d\n", safeseq[np - 1]);
}

/*
Initialize completed[i] flags to 0 for all processes, indicating that no process has completed initially.
Loop through each process in c to find a process that can be executed safely.
For each process i, check if it's not already completed.
Inside the inner loop, check if the resources required by process i (as indicated by its need array) can be fulfilled with the Available resources.
If resources are available for process i, it can be executed safely. Add it to the safeseq array and mark it as completed.
Update the Available resources by adding the allocated resources of process i.
Repeat this process until all processes have been considered.
*/
