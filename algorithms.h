#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "process.h"
void fcfs(int n_proc, struct Process* processes);
void rr(int n_proc, struct Process* processes);
void mlfq(int n_proc, struct Process* processes);
#endif