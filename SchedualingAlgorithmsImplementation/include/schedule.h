#define MIN_PRIORITY 1
#define MAX_PRIORITY 10


void add(char *name, int priority, int burst);
// adds a task at the end of the list maintained by this scheduler
// uses insert method from list.h to add a task at the end of the list 

void schedule();
// schedules the tasks in the list
// implements a single scheduling algorithm here
// The choices of the scheduling algorithms are
// 	first-come-first-serve
// 	shortest-job-first
// 	priority
// 	round-robin
// 	priority-round-robin

