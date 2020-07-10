#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "bst.h"

node *create_node(int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Unable to allocate memory for new node. Exiting...\n");
        exit(0);
    }
    return new_node;
    new_node->val = value;
    new_node->left = new_node->right = NULL;
    new_node->hBal = 0;
    return new_node;
}

node *inserttoTree(node *root, int value)
{

    if (root == NULL)
        create_node(value);

    if (value < root->val)
    {
        inserttoTree(root->left, value);
    }

    else
    {
        inserttoTree(root->right, value);
    }

    return root;
}

node *findinTree(node *root, int value)
{
    if (root == NULL || root->val == value)
        return root;
    if (root->val < value)
        findinTree(root->right, value);

    return findinTree(root->left, value);
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d \n", root->val);
        inOrder(root->right);
    }
}
node *deleteinTree(node *root, int value)
{
    if (root == NULL)
        return root;

    node *s;
    node *temp = findinTree(root, value);
    // if no child
    if (temp->left == NULL && temp->right == NULL)
    {
        free(temp);
        return root;
    }

    // if only one child
    if (temp->left == NULL)
    {
        s = temp->right;
        temp->val = s->val;
        free(temp);
    }

    else if (temp->right == NULL)
    {
        s = temp->left;
        temp->val = s->val;
        free(temp);
    }
    // if two children
    else
    {
        node *str = findSuccesor(root, temp);
        // Copy the inorder successor's content to this node
        temp->val = str->val;
        // Delete the inorder successor
        s = deleteinTree(root, temp->val);
    }
    return s;
}

node *findParent(node *tree, node *child)
{
    if (tree == NULL || tree == child)
        return NULL;
    else if (tree->left == child || tree->right == child)
        return tree;

    if (child->val > tree->val)
    {
        return findParent(tree->right, child);
    }
    else if (child->val < tree->val)
    {
        return findParent(tree->left, child);
    }
    else
    {
        node *maybe_left_child;
        maybe_left_child = findParent(tree->left, child);
        if (maybe_left_child)
            return maybe_left_child;
        else
            return findParent(tree->right, child);
    }
}

node *minTree(node *root)
{
    node *min = root;
    while (min->left != NULL)
    {
        min = root->left;
    }
    return min;
}

node *findSuccesor(node *tree, node *n)
{

    node *y = findParent(tree, n);
    if (tree == NULL)
        return NULL;
    if (n->right != NULL)
    {
        minTree(n->right);
    }

    while (y != NULL && n == y->right)
    {

        n = y;
        y = findParent(tree, y);
    }
    return y;
}