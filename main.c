#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "unistd.h"
#include "algorithms.h"

int main( )
{
    int n_proc = 4;
//    int n_proc = 390;
    struct Process processes[n_proc];
    processes[0].arrival_time = 0;
    processes[0].burst_time = 7;
    processes[1].arrival_time = 1;
    processes[1].burst_time = 60;
    processes[2].arrival_time = 2;
    processes[2].burst_time = 20;
    processes[3].arrival_time = 3;
    processes[3].burst_time = 40;


//    int q = 8;
    srand(time(NULL));

//    printf("Testing First-Come, First-Serve scheduler...\n");
//    sleep(1);
//    fcfs(n_proc, processes);
//    sleep(1);
//    printf("First-Come, First-Serve scheduling algorithm test complete\n");
//
//
//    printf("Testing Round Robin scheduling algorithm...\n");
//    sleep(1);
//    rr(n_proc, processes);
//    sleep(1);
//    printf("Round Robin scheduling algorithm test complete\n");
//    for(int i = 0; i < 10; i++){
//        for (int j = 0; j < n_proc; j++) {
//
//            if (j == 0) {
//                processes[j].arrival_time = 0;
//            } else {
//                processes[j].arrival_time = processes[j-1].arrival_time + (rand() % 8);
//            }
//            processes[j].burst_time = (rand() % n_proc) + 1;
//        }
//
//    }
    printf("Testing Multilevel Feedback Queue scheduling algorithm...\n");
    sleep(1);
    mlfq(n_proc, processes);
    sleep(1);
    printf("Multilevel Feedback Queue scheduling algorithm test complete...\n");
//    printf("Testing Multilevel Feedback Queue scheduling algorithm...\n");
//    sleep(1);
//    mlfq(n_proc, processes);
//    sleep(1);
//    printf("Multilevel Feedback Queue scheduling algorithm test complete...\n");
    return 0;
}