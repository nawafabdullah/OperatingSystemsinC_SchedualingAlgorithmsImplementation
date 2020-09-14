/**
 * list data structure containing the tasks in the system
 */

#include "task.h"
#include <stdlib.h>
#include <stdio.h>

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
  if (*head == NULL) // -empty list- check if head is empty. if it is, give it the data that was passed 
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
 if (*head == NULL) // -empty list- check if head is empty. if it is, give it the data that was passed
 {
   printf ("the list is empty"); //
   return; 
 } else
  {
    struct node* tmp = *head;
    //    struct node* tmp = head;

  if (tmp->task->tid == task->tid)
  {
	*head = tmp->next;
	tmp->next = NULL;
        free(tmp);	
	return;
  }
   
/* if(task->tid == 1) //check if we want to delete first task i.e, first element in the list 
    {
      *head = tmp ->next; // move the head to point to next element 
      tmp->next = NULL;
      free(tmp);
    } else
    {
      struct node* q; //point at element before the on to be deleted   
*/
      
    struct node* q; //point at element before the on to be deleted
    while (tmp->task->tid != task->tid) //loop until finding the element we want to delete
      {
	q = tmp;
	tmp = tmp ->next;
      }
      if (tmp == NULL)
      {
    	printf ("could not find task");
	return;
      }
      q->next = tmp-> next; //link element to the element after before deletion 
      tmp -> next = NULL; // unlink tmp
      free(tmp); 
  }
}


void traverse(struct node *head)
//traverse the linked list from head to tail
//print the details of each task in the list
{
  struct node* p = head;
  while (p!= NULL)
  {
    printf("[%s] [%d] [%d] \n", p->task->name, p->task->priority, p->task->burst);
    p = p->next;
  }
}
