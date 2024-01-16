#include "algorithms.h"
#include <stdio.h>
void fcfs(int n_proc, struct Process* processes) {
    int remaining_burst[n_proc];
    int response_time[n_proc];
    int total_waiting_time = 0;
    int total_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    int turnaround_time[n_proc];
    int waiting_time[n_proc];
    for (int i = 0; i < n_proc; i++) {
        remaining_burst[i] = processes[i].burst_time;
    }
    for(int i = 0; i < n_proc; i++) {
        total_time += remaining_burst[i];
        remaining_burst[i] = 0;
        turnaround_time[i] = total_time - processes[i].arrival_time;
        total_turnaround_time += turnaround_time[i];
        waiting_time[i] = turnaround_time[i] - processes[i].burst_time;
        total_waiting_time += waiting_time[i];
        response_time[i] = waiting_time[i];
        total_response_time += response_time[i];
    }
    int average_turnaround_time = total_turnaround_time/n_proc;
    int average_waiting_time = total_waiting_time/n_proc;
    int average_response_time = total_response_time/n_proc;
    printf("Average turnaround time: %d\n", average_turnaround_time);
    printf("Average waiting time: %d\n", average_waiting_time);
    printf("Average response time: %d\n", average_response_time);
}