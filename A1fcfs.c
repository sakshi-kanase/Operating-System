#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define IO_TIME 2

typedef struct {
    int pid;
    int arrival_time;
    int cpu1;
    int cpu2;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int start_time;
    int io_start;
    int io_end;
    int second_start;
} Process;

void sort_by_arrival(Process p[], int n) {
    Process temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(p[j].arrival_time > p[j+1].arrival_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main() {
    Process p[MAX];
    int n;
    int current_time = 0;
    float total_tat = 0, total_wt = 0;

    srand(time(0)); // Seed for random number

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival time and first CPU burst
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time for Process %d: ", i+1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter First CPU Burst for Process %d: ", i+1);
        scanf("%d", &p[i].cpu1);
        p[i].cpu2 = (rand() % 10) + 1; // Random burst between 1 and 10
    }

    // Sort by arrival time
    sort_by_arrival(p, n);

    printf("\nGantt Chart:\n");

    for(int i = 0; i < n; i++) {
        // Wait for process to arrive
        if(current_time < p[i].arrival_time)
            current_time = p[i].arrival_time;

        // Start first CPU burst
        p[i].start_time = current_time;
        printf("| P%d(%d-%d) ", p[i].pid, current_time, current_time + p[i].cpu1);
        current_time += p[i].cpu1;

        // I/O Time
        p[i].io_start = current_time;
        p[i].io_end = current_time + IO_TIME;
        current_time += IO_TIME;

        // Start second CPU burst
        p[i].second_start = current_time;
        printf("P%d_IO(%d-%d) P%d(%d-%d) | ", p[i].pid, p[i].io_start, p[i].io_end, p[i].pid, current_time, current_time + p[i].cpu2);
        current_time += p[i].cpu2;

        // Completion time and metrics
        p[i].completion_time = current_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - (p[i].cpu1 + p[i].cpu2 + IO_TIME);

        total_tat += p[i].turnaround_time;
        total_wt += p[i].waiting_time;
    }

    // Output Metrics
    printf("\n\nProcess\tAT\tCPU1\tCPU2\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].cpu1,
               p[i].cpu2,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time);
    }

    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);

    return 0;
}

