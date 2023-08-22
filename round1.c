#include <stdio.h>
int q[100];
int f = -1;
int r = -1;

// Function to insert a process into the queue
void insert(int n) {
    if (f == -1)
        f = 0;
    else {
        r = r + 1;
        q[r] = n;
    }
}

// Function to delete a process from the queue
int delete() {
    int n;
    n = q[f];
    f = f + 1;
    return n;
}

int main() {
    int p, tq, n, i, t = 0;
    float twt = 0, ttat = 0;
    
    // Taking input for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Declaring arrays to store process information
    int a[n][5], b[10], exist[10] = {0};
    
    // Taking input for arrival and burst time of each process
    printf("Enter arrival and burst for each process:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess ID: ");
        scanf("%d", &a[i][0]);
        printf("Enter arrival time of %dth process: ", a[i][0]);
        scanf("%d", &a[i][1]);
        printf("Enter the burst time of %dth process: ", a[i][0]);
        scanf("%d", &a[i][2]);
        b[i] = a[i][2]; // Copying burst time for later reference
    }
    
    // Taking input for time quantum
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    
    insert(0);
    exist[0] = 1;
    
    // Scheduling using Round Robin with time quantum
    while (f <= r) {
        p = delete(); // Get process from the front of the queue
        
        if (a[p][2] >= tq) {
            a[p][2] -= tq; // Decrement burst time by time quantum
            t += tq;       // Increment total time by time quantum
        } else {
            t += a[p][2];   // Increment total time by remaining burst time
            a[p][2] = 0;    // Process completes its execution
        }
        
        // Checking and inserting processes that arrived while executing
        for (i = 0; i < n; i++) {
            if (exist[i] == 0 && a[i][1] <= t) {
                insert(i); // Insert into queue if arrival time is reached
                exist[i] = 1; // Mark the process as existing in the queue
            }
        }
        
        // Calculating turnaround time and waiting time for the process
        if (a[p][2] == 0) {
            a[p][4] = t - a[p][1]; // Turnaround time
            a[p][3] = a[p][4] - b[p]; // Waiting time
            twt += a[p][3]; // Update total waiting time
            ttat += a[p][4]; // Update total turnaround time
        } else {
            insert(p); // Insert back into queue for the next round
        }
    }
    
    // Display process information and calculated times
    printf("\nP.No.\tAT\tBT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", a[i][0], a[i][1], b[i], a[i][4], a[i][3]);
    }
    
    // Display average turnaround and waiting times
    printf("Average Turnaround time = %f\n", ttat / n);
    printf("Average Waiting time = %f\n", twt / n);
    
    return 0;
}

