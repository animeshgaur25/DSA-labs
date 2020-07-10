#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct T_node
{
    int val;
    struct T_node *left;
    struct T_node *right;
    int hBal : 2;
} node;

#endif