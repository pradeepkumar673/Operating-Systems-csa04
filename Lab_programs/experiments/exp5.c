/* Construct a scheduling program with C that selects the waiting process with the highest priority to execute next. */
#include <stdio.h>

int main(void)
{
    int burst_time[100];
    int priority[100];
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

    printf("Enter burst time and priority for each process (lower number means higher priority):\n");
    for (int i = 0; i < count; i++) {
        process[i] = i + 1;
        printf("P%d burst time: ", process[i]);
        if (scanf("%d", &burst_time[i]) != 1 || burst_time[i] < 0) {
            fprintf(stderr, "Burst time must be a non-negative integer.\n");
            return 1;
        }
        printf("P%d priority: ", process[i]);
        if (scanf("%d", &priority[i]) != 1) {
            fprintf(stderr, "Priority must be an integer.\n");
            return 1;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        int highest = i;
        for (int j = i + 1; j < count; j++)
            if (priority[j] < priority[highest])
                highest = j;
        int temp = priority[i];
        priority[i] = priority[highest];
        priority[highest] = temp;
        temp = burst_time[i];
        burst_time[i] = burst_time[highest];
        burst_time[highest] = temp;
        temp = process[i];
        process[i] = process[highest];
        process[highest] = temp;
    }

    waiting_time[0] = 0;
    for (int i = 1; i < count; i++)
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < count; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", process[i], priority[i],
               burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average waiting time: %.2f\n", (double)total_waiting / count);
    printf("Average turnaround time: %.2f\n", (double)total_turnaround / count);
    return 0;
}
