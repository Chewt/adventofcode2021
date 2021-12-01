#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readInput(char* filename, int** values)
{
    FILE* f = fopen(filename, "r");
    char* currline = NULL;
    size_t size;
    int n = 0;
    while (getline(&currline, &size, f) > 0)
        n++;
    free(currline);
    currline = NULL;
    rewind(f);
    *values = malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; ++i)
    {
        getline(&currline, &size, f);
        (*values)[i] = atoi(currline);
    }
    free(currline);
    fclose(f);
    return n;
}

int countIncreases(int* values, int n)
{
    int count = 0;
    int i;
    for (i = 0; i < n - 1; ++i)
    {
        if (values[i + 1] > values[i])
            count++;
    }
    return count;
}

int countSlidingIncreases(int* values, int n)
{
    int count = 0;

    int i;
    int prevSum = values[0] + values[1] + values[2];
    for (i = 1; i < n - 2; ++i)
    {
        int currSum = values[i] + values[i + 1] + values[i + 2];
        if (currSum > prevSum)
            count++;
        prevSum = currSum;
    }

    return count;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Invalid Arguments.\n");
        exit(-1);
    }

    int* vals = NULL;
    int numVals = readInput(argv[1], &vals);
    
    printf("There are %d increases\n", countIncreases(vals, numVals));
    printf("There are %d increases in the sliding window example\n", 
            countSlidingIncreases(vals, numVals));
    
    free(vals);
    return 1;
}
