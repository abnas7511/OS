#include <stdio.h>

void main() {
    int n, i, j, b[20], sb[20], t[20], x, c[20][20];
    char nme[30];

    printf("Enter no.of files:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter no. of blocks occupied by file%d : ", i + 1);
        scanf("%d", &b[i]);

        printf("Enter the starting block of file%d : ", i + 1);
        scanf("%d", &sb[i]);

        t[i] = sb[i];
        for (j = 0; j < b[i]; j++)
            c[i][j] = sb[i]++;
    }

    printf("Filename\tStart block\tlength\n");
    for (i = 0; i < n; i++)
        printf("%d\t\t %d \t\t%d\n", i + 1, t[i], b[i]);

    printf("Enter file number (1 to %d): ", n);
    scanf("%d", &x);

    if (x >= 1 && x <= n) {
        printf("File name: file%d\n", x);
        printf("Length: %d\n", b[x - 1]);
        printf("Blocks occupied:");
        for (i = 0; i < b[x - 1]; i++)
            printf("%4d", c[x - 1][i]);
        printf("\n");
    } else {
        printf("Invalid file number. Please enter a valid file number (1 to %d).\n", n);
    }
}
