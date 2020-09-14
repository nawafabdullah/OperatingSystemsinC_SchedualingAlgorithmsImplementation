/* 
* Nawaf Alharbi
* Operating Systems
*/ 

/**
 * Scheduler.c
 *
 * Schedule the tasks in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "schedule.h"


#define line_length 30
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
	tokenize = strtok(NULL, delim);
	i++;
      }
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
    schedule();
    return 1;
}
