#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

    for (int i = 0; i < 3; i++)
    {
        printf("\n%d", atoi(argv[i]));
    }
}