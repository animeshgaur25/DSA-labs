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
void insertFirst(linkedList *head, int ele);
/* inserts a given element at the beginning of the list */

Node *deleteFirst(linkedList *head);
/* deletes the first element of the list and returns pointer to the deleted node. */

void printList(linkedList *head);
/* prints all the elements in the list */

int search(linkedList *head, int ele);
/* searches for a given element in the linked list. Returns 1 if found, 0 otherwise. */

struct node *delete (linkedList *head, int ele);
/* deletes the first node in the list that contains the element = ele and retuns it. If the element is not found it returns an error message saying element not found. */
