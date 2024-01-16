#include <stdbool.h>
#include <stdio.h>
#include "algorithms.h"

void rr(int n_proc, struct Process* processes)
{
    int q = 8;
    int remaining_burst[n_proc];
    int turnaround_time[n_proc], waiting_time[n_proc], response_time[n_proc];

    for (int i = 0; i < n_proc; i++) {
        remaining_burst[i] = processes[i].burst_time;
    }

    int counter = n_proc, n = 0, total_time = 0, total_turnaround_time = 0, total_waiting_time = 0, total_response_time = 0;
    bool recently_done = false, time_changed;

    while (counter != 0) {
        time_changed = false;
        if (remaining_burst[n] > 0) {
            if (remaining_burst[n] <= q) {
                if (remaining_burst[n] == processes[n].burst_time) {
                    response_time[n] = total_time - processes[n].arrival_time;
                    total_response_time += response_time[n];
                }
                total_time += remaining_burst[n];
                remaining_burst[n] = 0;
                recently_done = true;
                time_changed = true;
            }
            else {
                if (remaining_burst[n] == processes[n].burst_time) {
                    response_time[n] = total_time - processes[n].arrival_time;
                    total_response_time += response_time[n];
                }
                total_time += q;
                remaining_burst[n] -= q;
                time_changed = true;
            }
        }

        if (remaining_burst[n] == 0 && recently_done) {
            counter--;

            // update Turnaround
            turnaround_time[n] = total_time - processes[n].arrival_time;
            total_turnaround_time += turnaround_time[n];

            // update Waiting
            waiting_time[n] = turnaround_time[n] - processes[n].burst_time;
            total_waiting_time += waiting_time[n];

            // done updating
            recently_done = false;
        }

        if (n != n_proc - 1) {
            if (processes[n + 1].arrival_time <= total_time) {
                n++;
            }
            else {
                n = 0;
            }
        }
        else {
            n = 0;
        }
    }
    int average_turnaround_time = total_turnaround_time/n_proc;
    int average_waiting_time = total_waiting_time/n_proc;
    int average_response_time = total_response_time/n_proc;
    printf("Average turnaround time: %d\n", average_turnaround_time);
    printf("Average waiting time: %d\n", average_waiting_time);
    printf("Average response time: %d\n", average_response_time);
}