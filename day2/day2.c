#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    FILE* f = fopen(argv[1], "r");
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
    return 1;
}
