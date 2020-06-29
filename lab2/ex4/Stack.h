#include <stdio.h>

// linked list structure definitions

typedef struct node
{
    int ele;
    struct node *next;
} Node;

typedef struct linkedList
{
    int count;
    struct node *first;
} linkedList;

//function definition
void Push(linkedList *head, int ele);
/* inserts a given element at the beginning of the list */

Node *Pop(linkedList *head);
/* deletes the first element of the list and returns pointer to the deleted node. */

void printList(linkedList *head);