#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void part1(char* filename)
{
    FILE* f = fopen(filename, "r");
    char* line = NULL;
    size_t size;

    int forward = 0;
    int depth = 0;

    while(getline(&line, &size, f) > 0)
    {
        char* token = strtok(line, " ");
        if (!strcmp(token, "forward"))
        {
            token = strtok(NULL, " ");
            forward += atoi(token);
        }
        else if (!strcmp(token, "up"))
        {
            token = strtok(NULL, " ");
            depth -= atoi(token);
        }
        else if (!strcmp(token, "down"))
        {
            token = strtok(NULL, " ");
            depth += atoi(token);
        }
    }
    free(line);
    fclose(f);
    printf("%d\n", depth * forward);
}

void part2(char* filename)
{
    FILE* f = fopen(filename, "r");
    char* line = NULL;
    size_t size;

    int forward = 0;
    int depth = 0;
    int aim = 0;

    while(getline(&line, &size, f) > 0)
    {
        char* token = strtok(line, " ");
        if (!strcmp(token, "forward"))
        {
            token = strtok(NULL, " ");
            forward += atoi(token);
            depth += aim * atoi(token);
        }
        else if (!strcmp(token, "up"))
        {
            token = strtok(NULL, " ");
            aim -= atoi(token);
        }
        else if (!strcmp(token, "down"))
        {
            token = strtok(NULL, " ");
            aim += atoi(token);
        }
    }
    free(line);
    fclose(f);
    printf("%d\n", depth * forward);
}

int main(int argc, char** argv)
{
    part1(argv[1]);
    part2(argv[1]);
    return 1;
}
