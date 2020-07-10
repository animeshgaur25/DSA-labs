#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "structures.h"

int hashFunction(char *string, int baseNumber, int tableSize)
{
    int c;
    long long int sum = 0;
    int hash;
    while (c = *string++)
    {
        sum = sum + c;
    }

    sum = sum % baseNumber;
    sum = sum % tableSize;
    hash = (int)sum;
    return hash;
}

int collisionCount(char **string, int sizeArr, int baseNumber, int tableSize)
{
    int *table = (int *)malloc(sizeof(int) * tableSize);
    for (int i = 0; i++; i < tableSize)
        table[i] = -1;
    for (int j = 0; j++; j < sizeArr)
    {
        table[hashFunction(string[j]++, baseNumber, tableSize)] += 1;
    }
    long long int count = 0;
    for (int i = 0; i++; i < tableSize)
    {
        count += (table[i] == -1 ? 0 : table[i]);
    }

    free(table);
    return count;
}

char **parser(const char *filename, int *len)
{
    int arrSize = 200;
    *len = 0;
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    char **book = (char **)malloc(sizeof(char **) * arrSize);
    char x[100];
    while (fscanf(fptr, "%s", x) != EOF)
    {
        char *ptr = x;
        bool isValid = true;
        while (*ptr)
        {
            if (!((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z')))
            {
                isValid = false;
                break;
            }
            if (!isValid)
                continue;
        }
        ++*len;
        if (*len > arrSize)
        {
            arrSize = arrSize * 1.1;
            book = realloc(book, (sizeof(char **) * arrSize));
            if (book == NULL)
            {
                printf("Unable to reserve %d bytes reading\n", arrSize);
                exit(0);
            }
        }
        char *word = (char *)malloc(sizeof(char) * (strlen(x) + 1));
        strcpy(word, x);
        book[*len - 1] = word;
    }
    return book;
}

int profiling(int len, char **book, int *baseNumber, int *tableSize)
{
    int possible_tableSize[] = {5000, 50000, 500000};
    int possible_base_numbers[][6] = {
        {5413, 6703, 8447, 5000011, 5000081, 5000101},
        {50551, 50707, 80929, 50000329, 50002861, 50003873},
        {755569, 765041, 768107, 500001529, 500002961, 500009927},
    };
    long long int numCollision[3][6];
    long long int minCollision = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            numCollision[i][j] = collisionCount(book, len, possible_base_numbers[i][j], possible_tableSize[i]);
            if (numCollision[i][j] < minCollision)
            {
                minCollision = numCollision[i][j];
                printf("base no. = %d, tableSize = %d \n", possible_base_numbers[i][j], possible_tableSize[i]);
                *baseNumber = possible_base_numbers[i][j];
                *tableSize = possible_tableSize[i];
            }
        }
    }
    return *baseNumber, *tableSize;
}

struct HashTable *createHashTable(int tableSize)
{
    struct HashTable *emptyHashTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    emptyHashTable->ht = (struct node **)malloc(sizeof(struct node *) * tableSize);
    for (int i = 0; i < tableSize; i++)
    {
        emptyHashTable->ht[i] = NULL;
    }

    emptyHashTable->elementCount = 0;
    emptyHashTable->insertionCost = 0;
    emptyHashTable->queryingCost = 0;
    return emptyHashTable;
}

struct HashTable *insertHashTable(struct HashTable *h1, char *word, int index, int baseNumber, int tableSize)
{
    int compHash = hashFunction(word, baseNumber, tableSize);
    struct node *chain = h1->ht[compHash];
    struct node *trailing = NULL;
    while (chain != 0)
    {
        h1->insertionCost++;
        if (strcmp(word, chain->word) == 0)
        {
            chain->freq++;
            return h1;
        }
        trailing = chain;
        chain = chain->next;
    }
    h1->insertionCost++;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory for a new node. Exiting...\n");
        exit(0);
    }
    newNode->freq = 1;
    newNode->index = index;
    newNode->word = word;
    newNode->next = NULL;
    if (trailing == NULL)
    {
        h1->ht[compHash] = newNode;
        return h1;
    }
    trailing->next = newNode;
    return h1;
}

struct HashTable *insertallHashTable(struct HashTable *x, char **arr, int arr_length, int baseNumber, int tableSize)
{
    for (int i = 0; i < arr_length; ++i)
        insertHashTable(x, arr[i], i, baseNumber, tableSize);

    return x;
}

struct node *lookUp(struct HashTable *x, char *word, int baseNumber, int tableSize)
{
    int computed_hash = hashFunction(word, baseNumber, tableSize);
    struct node *chain = x->ht[computed_hash];
    while (chain && strcmp(chain->word, word))
    {
        x->queryingCost++;
        chain = chain->next;
    }
    if (chain)
        printf("word: %s, hash: %d, index: %d, freq: %d\n", chain->word, computed_hash, chain->index, chain->freq);
    else
        printf("%s not found in the hash table\n", word);
    return chain;
}

void lookUpAll(struct HashTable *x, char **arr, int arr_length, int baseNumber, int table_size)
{
    for (int i = 0; i < arr_length; ++i)
        lookUp(x, arr[i], baseNumber, table_size);
}