/* 
* Nawaf Alharbi
* Operating Systems
*/ 

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#include "list.h"
#include "task.h"
#include "cpu.h"
#include "task.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct node* head = NULL;
int tid = 1;



void add(char *name, int priority, int burst);
// adds a task at the end of the list maintained by this scheduler
// uses insert method from list.h to add a task at the end of the list 
{
  Task *obj = (Task*)malloc(sizeof(Task)); // create object pointer and use malloc to allocate memory for a new task   
  obj->name = name;
  obj-> priority = priority;
  obj-> burst = burst;  
  insert(&head, obj); 
}

void schedule();
// schedules the tasks in the list
// implements a single scheduling algorithm here
// The choices of the scheduling algorithms are
// 	first-come-first-serve
// 	shortest-job-first
// 	priority
// 	round-robin
// 	priority-round-robin

