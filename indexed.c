#include <stdio.h>
#include <string.h>
struct file {
    char fname[10];
    int start, size, block[10];
} f[10];
void main() {
    int n, m[20], i, j, sb[20], s[20], b[20][20], x = -1;
    char nme[30];
    printf("Enter no. of files: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", f[i].fname);
        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter no. of blocks: ");
        scanf("%d", &f[i].size);
        printf("Enter block numbers:\n");
        for (j = 1; j <= f[i].size; j++)
            scanf("%d", &f[i].block[j]);
    }
    printf("\nFile\tIndex\tLength\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, f[i].start, f[i].size);
    printf("\nEnter file name: ");
    scanf("%s", nme);
    printf("File name: %s\n", nme);
    for (i = 0; i < n; i++) {
        if (strcmp(nme, f[i].fname) == 0) {
            x = i;
            break;
        }
    }
    if (x != -1) {
        printf("Index: %d\n", f[x].start);
        printf("Blocks occupied are:");
        for (j = 0; j < f[x].size; j++)
            printf(" %d", f[x].block[j]);
        printf("\n");
    } else {
        printf("File not found!\n");
    }}
