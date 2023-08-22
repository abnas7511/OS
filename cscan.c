#include <stdio.h>
#include <stdlib.h>
void main()
{
    int queue[20], n, head, i, j, k, seek = 0, max, diff, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float avg;
    printf("Enter the max range of disk: ");
    scanf("%d", &max);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the size of the queue request: ");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp >= head)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }}
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }}}
    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }}}
    printf("Head Movement Sequence:\n");
    printf("%d", head);
        printf(" -> %d ", max);
    seek += abs(max - head);
    head = max;
    printf(" -> 0 ");
    seek += head; // Add the distance from max to 0
    head = 0;
    printf(" -> %d ", queue1[0]);
    seek += queue1[0];
    for (i = 0; i < temp1; i++)
    {
        printf(" -> %d ", queue1[i]);
        seek += abs(queue1[i] - head);
        head = queue1[i];
    }
    printf("\n");

    avg = (float)seek / n;
    printf("Total head movements = %d\n", seek);
    printf("Average seek time = %.2f\n", avg);
}