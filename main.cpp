#include <stdio.h>
#include <stdlib.h>

#include "nonofile.h"

void error(const char *);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        error("No filename specified");
    }
    NonoFile nonogram(argv[1]);
    printf("Nonogram %dx%d loaded\n", nonogram.getWidth(), nonogram.getHeight());
}

void error(const char *string)
{
    fprintf(stderr, "Error: %s\n");
    exit(1);
}
