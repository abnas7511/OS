#include <stdio.h>

int main() {
    int n, i;
    float ttat = 0, twt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int a[n][5]; // Array to store process information

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &a[i][2]); // Corrected the input reading
    }

    a[0][4] = 0;
    for (i = 1; i < n; i++) {
        a[i][4] = a[i - 1][2] + a[i - 1][4];
    }
    
    for (i = 0; i < n; i++) {
        a[i][3] = a[i][2] + a[i][4]; // Turnaround time = Burst time + Waiting time
        twt += a[i][4]; // Update total waiting time
        ttat += a[i][3]; // Update total turnaround time
    }

    printf("Process\t B.T\t T.A\t W.T\n");
    for (i = 0; i < n; i++) {
        printf("%d\t %d\t %d\t %d\n", i + 1, a[i][2], a[i][3], a[i][4]);
    }
    
    printf("Average turnaround time = %f\n", (ttat / n));
    printf("Average waiting time = %f\n", (twt / n));

    return 0;
}
