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


void add(char *name, int priority, int burst)
// adds a task at the end of the list maintained by this scheduler
// uses insert method from list.h to add a task at the end of the list 
{
  Task *obj = (Task*)malloc(sizeof(Task)); // create object pointer and use malloc to allocate memory for a new task   
  obj -> name = malloc(sizeof(char));
  strcpy(obj->name, name);
  obj-> priority = priority;
  obj-> burst = burst;
  obj -> tid = tid;
  insert(&head, obj);
  tid++;
}

void schedule()
// schedules the tasks in the list
// implements a single scheduling algorithm here
// The choices of the scheduling algorithms are
// 	first-come-first-serve
// 	shortest-job-first
// 	priority
// 	round-robin
// 	priority-round-robin
{
 // keep track of list progress and shortest burst
  struct node* ptr_to_element = head; // point at first position in the struct
  struct node* ptr_to_next_element; //get next element to compare
  struct node* shortest_burst; //store the shortest brust you find here

  while (ptr_to_element != NULL) //loop until the end of the list
  {
    shortest_burst = head; //initialaize shortest burst to head's burst 
    ptr_to_next_element = head -> next;

    while (ptr_to_next_element != NULL) // loop comparing bursts 
    {
      if (ptr_to_next_element -> task -> burst <= shortest_burst -> task -> burst)
      {
	shortest_burst = ptr_to_next_element; 
      }
      ptr_to_next_element = ptr_to_next_element -> next; 
    }  
    run(shortest_burst->task, shortest_burst-> task->burst); //call run function in cpu.c
    delete(&head,shortest_burst->task); //call delete function in list.c
    ptr_to_element = head; //point back to the head 
  }
}
