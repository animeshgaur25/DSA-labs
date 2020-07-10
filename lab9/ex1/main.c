#include <stdio.h>
#include <string.h>
#include "hash.h"

int main()
{

    /*  printf("%d\n", hashFunction("AB", 20, 5));
    const char *x[] = {
        "AB", "AB", "CD", "CD"};
    printf("%d\n", hashFunction("CD", 20, 5));
    printf("%d\n", collisionCount(x, 3, 20, 5));
*/
    int len;
    char **book = parser("aliceinwonderland1.txt", &len);
    int baseNumber = 71, tableSize = 50;
    // for(int i = 0; i < len; ++i) printf("%s\n", xx[i]);
    //printf("Number of valid strings are: %d\n", len);
    //best_hash_fn(book, len, &baseNumber, &tableSize);
    //printf("BN: %d, TS: %d\n", baseNumber, tableSize);
    //printf("%lld\n", collision(book, len, 5413, 5000));
    //for(int i = 0; i < len; ++i) printf(book[i]);
    //collision(book, len, 1, 1);
    struct HashTable *x = createHashTable(tableSize);
    insertHashTable(x, strdup("ehllo"), 1, baseNumber, tableSize);
    insertallHashTable(x, book, len, baseNumber, tableSize);
    //print_frequency(x, tableSize);
    lookUpAll(x, book, len, baseNumber, tableSize);
    lookUp(x, "sdlkafjl", baseNumber, tableSize);
    printf("Insertion cost: %d\n", x->insertionCost);
    printf("Querying cost: %d\n", x->queryingCost);
    return 0;
}