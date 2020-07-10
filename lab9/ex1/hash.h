#ifndef _HASH_H
#define _HASH_H
#include "structures.h"

int hashFunction(char *, int, int);
int collisionCount(char **, int, int, int);
char **parser(const char *, int *);
int profiling(int len, char **, int *, int *);
struct HashTable *createHashTable(int);
struct HashTable *insertHashTable(struct HashTable *, char *, int, int, int);
struct HashTable *insertallHashTable(struct HashTable *, char **, int, int, int);
struct node *lookUp(struct HashTable *, char *, int, int);
void lookUpAll(struct HashTable *, char **, int, int, int);
#endif