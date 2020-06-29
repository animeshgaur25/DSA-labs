#include <stdio.h>
int main(int argc, char *argv[])
{
    int num;
    FILE *fptr1, *fptr2;
    fptr1 = fopen(argv[1], "r");
    fptr2 = fopen(argv[2], "w");
    if (fptr1 == NULL || fptr2 == NULL)
    {
        printf("Error!");
    }

    fscanf(fptr1, "%d", &num);
    fprintf(fptr2, "%d", num);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}