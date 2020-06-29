#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void main(int argc, char *argv[])
{
    // Create a file pointer and open the file read as command line argument.
    FILE *fileptr = fopen(argv[1], "r");
    // Declare a pointer to a linked list (head) and allocate memory to it.
    struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList));
    // In a loop read the file and insert elements into the linkedList.
    while (!feof(fileptr))
    {
        // read the next element and store into the temp variable.
        int temp;
        fscanf(fileptr, "%d", &temp);
        // insert temp into the linked list.
        Push(head, temp);
    }
    // close the file pointer
    fclose(fileptr);
    printList(head);
    Pop(head);
    printList(head);
}