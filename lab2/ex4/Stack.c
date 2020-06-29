#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>
void Push(linkedList *head, int ele)
{

    Node *link = (Node *)malloc(sizeof(Node));
    link->ele = ele;
    link->next = head->first;
    head->first = link;
    head->count++;
}

Node *Pop(linkedList *head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = head->first;
    head->first = temp->next;
    return temp;
}

//display the list
void printList(linkedList *head)
{
    struct node *ptr = head->first;
    printf("\n[ ");
    //start from the beginning
    while (ptr != NULL)
    {
        printf("%d, ", ptr->ele);
        ptr = ptr->next;
    }

    printf(" ]");
}