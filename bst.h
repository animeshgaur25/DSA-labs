#ifndef _BST_H
#define _BST_H

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
node *create_node(int);
node *inserttoTree(node *, int);
node *findinTree(node *, int);
void inOrder(node *);
node *deleteinTree(node *, int);
node *findParent(node *, node *);
node *minTree(node *);
node *findSuccesor(node *, node *);

#endif