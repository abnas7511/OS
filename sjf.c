#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    int i, j, temp, cmpt, min;
    float twt = 0;
    float ttat = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    int a[n][5];

    printf("\nEnter the Arrival Time & Burst Time of each process: ");
    for (i = 0; i < n; i++) {
        printf("\nProcess ID: ");
        scanf("%d", &a[i][0]);
        printf("\nEnter the Arrival time of %dth Process: ", a[i][0]);
        scanf("%d", &a[i][1]);
        printf("\nEnter the Burst time of %dth Process: ", a[i][0]);
        scanf("%d", &a[i][2]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j][1] > a[j + 1][1]) {
                swap(&a[j][0], &a[j + 1][0]);
                swap(&a[j][1], &a[j + 1][1]);
                swap(&a[j][2], &a[j + 1][2]);
            }
            if (a[j][1] == a[j + 1][1] && a[j][2] > a[j + 1][2]) {
                swap(&a[j][0], &a[j + 1][0]);
                swap(&a[j][1], &a[j + 1][1]);
                swap(&a[j][2], &a[j + 1][2]);
            }
        }
    }
    cmpt = a[0][1]+a[0][2];
    a[0][4] = cmpt - a[0][1];
    a[0][3] = a[0][4] - a[0][2];
    twt = twt + a[0][3];
    ttat = ttat + a[0][4];

    for (i = 1; i < n; i++) {
        min = a[i][2];
        for (j = i + 1; j < n; j++) {
            if (min > a[j][2] && a[j][1] <= cmpt) {
                min = a[j][2];
                swap(&a[i][0], &a[j][0]);
                swap(&a[i][1], &a[j][1]);
                swap(&a[i][2], &a[j][2]);
            }
        }
        if(a[i][1]>cmpt)
          cmpt=a[i][1]+a[i][2];
        else
          cmpt = cmpt+a[i][2];
        a[i][4]=cmpt-a[i][1];
        a[i][3]=a[i][4]-a[i][2];
        twt += a[i][3];
        ttat += a[i][4];
    }

    printf("\nP.No.\tAT\tBT\tTAT\tWT");
    for (i = 0; i < n; i++) {
        printf("\n%d\t%d\t%d\t%d\t%d", a[i][0], a[i][1], a[i][2], a[i][4], a[i][3]);
    }

    printf("\nAverage Turnaround time = %f", ttat / n);
    printf("\nAverage Waiting time = %f", twt / n);

    return 0;
}