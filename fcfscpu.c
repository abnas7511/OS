#include <stdio.h>

int main() {
    int i, n;
    float tatsum = 0, wtsum = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int a[n][5];

    printf("Enter B.T of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Burst Time of process %d: ", (i + 1));
        scanf("%d", &a[i][1]);
    }
    a[0][4] = 0;
    for (i = 1; i < n; i++) {
        a[i][4] = a[i-1][1]+a[i-1][4];
    }
    
    for (i = 0; i < n; i++) {
        a[i][3] = a[i][1] + a[i][4];
    }
    
    printf("Process\t B.T\t T.A\t W.T\n");
    for (i = 0; i < n; i++) {
        printf("%d\t %d\t %d\t %d\n", i, a[i][1], a[i][3], a[i][4]);
        tatsum += a[i][3];
        wtsum += a[i][4];
    }
    
    printf("Average turnaround time = %f\n", (tatsum / n));
    printf("Average waiting time = %f\n", (wtsum / n));

    return 0;
}
