#ifndef STRUCTURES_H
#define STRUCTURES_H

struct node
{
    char *word;
    int index;
    int freq;
    struct node *next;
};

struct HashTable
{
    struct node **ht;
    int elementCount;
    int insertionCost;
    int queryingCost;
};
#endif