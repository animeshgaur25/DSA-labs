#include <stdio.h>
int main()
{
    int num;
    FILE *fptr;
    fptr = fopen("program.txt", "r");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fscanf(fptr, "%d", &num);
    printf("value of num = %d", num);
    fclose(fptr);
    return 0;
}