#include<stdio.h> 

void main() {
    int i, j, k, f, pf=0, count=0, rs[25], m[10], n; 

    printf("\n Enter the length of the reference string -- "); 
    scanf("%d", &n); 

    printf("\n Enter the reference string -- "); 
    for(i = 0; i < n; i++)
        scanf("%d", &rs[i]); 

    printf("\n Enter no. of frames -- "); 
    scanf("%d", &f); 

    for(i = 0; i < f; i++) 
        m[i] = -1;

    printf("\n The Page Replacement Process is -- \n");

    for(i = 0; i < n; i++) 
    { 
        for(k = 0; k < f; k++) 
        { 
            if(m[k] == rs[i]) 
                break; 
        } 

        if(k == f) 
        { 
            m[count++] = rs[i];
            pf++; 
        } 

        for(j = 0; j < f; j++)
            printf("%d\t", m[j]); 

        if(k == f) 
            printf("\tPF No. %d", pf); 

        printf("\n"); 

        if(count == f) 
            count = 0; 
    } 

    printf("\n The number of Page Faults using FIFO are %d", pf);
}

/*Include Statements:
The code begins with an #include directive to include the standard input-output library (stdio.h), which is required for input and output operations.

main() Function:
The main() function is where the execution of the program starts.

Variable Declarations:

i, j, k are loop control variables.
f stores the number of frames available in memory.
pf stores the count of page faults.
count is used to keep track of the index of the frame being replaced.
rs is an array that stores the reference string (sequence of pages accessed).
m is an array that simulates the frames in memory.
n stores the length of the reference string.
Input Operations:
The program prompts the user to enter the length of the reference string (n), the reference string itself (rs), and the number of frames (f) available in memory.

Initializing Memory Frames:
The program initializes the memory frames by setting all entries in the array m to -1.

Page Replacement Process Loop:
This loop iterates through each element in the reference string:

It checks if the current page in the reference string (rs[i]) is already present in memory. If yes, it simply skips to the next iteration.
If the page is not present in memory, it replaces the oldest page in memory (determined by count) with the current page and increments the page fault count (pf).
Printing Memory Frames and Page Faults:

After processing each page in the reference string, the current state of memory frames is printed.
If a page fault occurred in this iteration, the page fault number (pf) is printed next to the memory frames.
Resetting Frame Replacement Counter:
If all frames are filled (count == f), the frame replacement counter (count) is reset to 0 to start replacing frames from the beginning.

Final Output:
The program prints the total number of page faults using the FIFO algorithm.*/