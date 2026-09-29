/* Construct a scheduling program with C that selects the waiting process with the smallest execution time to execute next. */
#include <stdio.h>

int main(void)
{
    int burst_time[100];
    int process[100];
    int waiting_time[100];
    int turnaround_time[100];
    int count;
    long total_waiting = 0;
    long total_turnaround = 0;

    printf("Enter number of processes: ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 100) {
        fprintf(stderr, "Process count must be between 1 and 100.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        process[i] = i + 1;
        printf("P%d burst time: ", process[i]);
        if (scanf("%d", &burst_time[i]) != 1 || burst_time[i] < 0) {
            fprintf(stderr, "Burst time must be a non-negative integer.\n");
            return 1;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        int shortest = i;
        for (int j = i + 1; j < count; j++)
            if (burst_time[j] < burst_time[shortest])
                shortest = j;
        int temp = burst_time[i];
        burst_time[i] = burst_time[shortest];
        burst_time[shortest] = temp;
        temp = process[i];
        process[i] = process[shortest];
        process[shortest] = temp;
    }

    waiting_time[0] = 0;
    for (int i = 1; i < count; i++)
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < count; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", process[i], burst_time[i],
               waiting_time[i], turnaround_time[i]);
    }

    printf("Average waiting time: %.2f\n", (double)total_waiting / count);
    printf("Average turnaround time: %.2f\n", (double)total_turnaround / count);
    return 0;
}
