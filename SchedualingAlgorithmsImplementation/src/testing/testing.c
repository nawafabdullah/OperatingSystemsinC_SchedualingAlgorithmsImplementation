//#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MIN_PRIORITY 1
#define MAX_PRIORITY 10





#define line_length 30

int tid = 1; 
struct node* head = NULL;


// representation of a task
typedef struct task {
    char *name;
    int tid;
    int priority;
    int burst;
} Task;


struct node {
    Task *task;
    struct node *next;
};

void insert(struct node **head, Task *task)
//inserts a task at the end of a linked list
//should not change head of the linked list
{
  struct node* tmp = (struct node*)malloc(sizeof(struct node)); // create storage space to store task temproraly
  
  tmp->task = task; // assign task holder in struct to task that was passed  
  tmp->next = NULL;
  
  if (head == NULL) // -empty list- check if head is empty. if it is, give it the data that was passed 
  {
     *head = tmp; // 
  } else
  {
    struct node* p; //follow links to end of list -look for the end of the list - 
    p = *head;

    while (p->next != NULL)
    {
      p = p->next; 
    }
    p->next = tmp;
  }
}




void delete(struct node **head, Task *task)
//deletes the given task from the linked list if it exists in the list
{
 if (head == NULL) // -empty list- check if head is empty. if it is, give it the data that was passed
 {
   printf ("the list is empty"); //
   return; 
 } else
  {
    struct node* tmp = *head;
    //    struct node* tmp = head;
    if(task->tid == 1) //check if we want to delete first task i.e, first element in the list 
    {
      //  struct node* tmp = head;
      *head == tmp ->next; // move the head to point to next element 
      tmp->next = NULL;
      free(tmp);
    } else
    {
      struct node* q; //point at element before the on to be deleted 
      while (tmp->task->tid =! task->tid) //loop until finding the element we want to delete
      {
	q = tmp;
	tmp = tmp ->next;
      }
      if (tmp == NULL)
      {
	printf ("could not find task");
	return;
      }
      q->next = tmp-> next; //link element before deletion to element after
      tmp -> next = NULL; // unlink tmp
      free(tmp); 
    }
  }
}


void traverse(struct node *head)
//traverse the linked list from head to tail
//print the details of each task in the list
{
  struct node* p = head;
  while (p!= NULL)
  {
    printf("[%s] [%d] [%d] \n", p->task->name, p->task->priority, p->task);
    p = p->next;
  }
}



void run(Task *task, int slice)
 {
    printf("Running task = [%s] [%d] [%d] for %d units.\n",task->name, task->priority, task->burst, slice);
}



void add(char *name, int priority, int burst)
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






int main(int argc, char *argv[])
{   
	//open the task file
	//read each task line from the file
	//extract name, priority, and burst
	//add the task into the list calling add(name, priority, burst) function from schedule.h
	//repeat above 3 steps for each task in the file.
	//close the task file.
	//schedule all tasks in the list by calling schedule() function from schedule.h

  if (argc < 2)
  {
    perror(" not suffecient number of arguments \n exiting program.. ");
    return 0; 
  }	
  FILE *file;
  file = fopen(argv[1], "r");
  //int assign_tid = 0;
  char* name;
  //  int tid = 1;
  int priority, burst;
  // int line_length = 30; 
  char line[line_length+1];
  char delim [2] = ",";
  int i = 0; 
  if(file != NULL)
  {
    /* Task obj;
    while (!feof(file))
    { 
      fscanf(file, "%s%*c %i%*c %i ", &name, priority,burst );
      tid ++;
      printf ("entered name is: %s \n priority is: %i \n, burst is: %i \n tid is :%i \n ", name, priority, burst, tid);  

      }*/

    while (fgets (line, line_length, file) != NULL)
    {
      char* tokenize = strtok(line, delim);  

      while (tokenize != NULL)
      {
	if (i == 0)
	  name = tokenize;

	if (i == 1)
	  priority = atoi(tokenize);

	if (i == 2)
	  burst = atoi(tokenize);

	// printf ("entered name is: %s \n priority is: %i \n, burst is: %i \n tid is :%i \n ", name, priority, burst, tid);
	tokenize = strtok(NULL, delim);
	i++;
      }

      printf ("entered name is: %s \n priority is: %i \n, burst is: %i \n ", name, priority, burst);
    
      //  tid++; 
      i = 0;     
      add (name, priority, burst); 

    }

  }
  else
  {
    perror(" COULD NOT OPEN FILE \n exiting program.. ");
    return 0;
  }   
   	
    fclose(file);
    return 1;
}
