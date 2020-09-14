/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

void insert(struct node **head, Task *task);
//inserts a task at the end of a linked list
//should not change head of the linked list

void delete(struct node **head, Task *task);
//deletes the given task from the linked list if it exists in the list


void traverse(struct node *head);
//traverse the linked list from head to tail
//print the details of each task in the list
