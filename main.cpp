#include <stdio.h>
#include <stdlib.h>
#include <iterator>

#include "nonofile.h"
#include "raster.h"
#include "solver.h"
#include "display.h"

void error(const char *);
void dump(Nonogram *);

int main(int argc, char *argv[])
{
    if (argc < 2)
        error("No filename specified");

    NonoFile nonogram(argv[1]);
    printf("Nonogram %dx%d loaded\n", nonogram.getWidth(), nonogram.getHeight());
    Raster raster(nonogram.getWidth(), nonogram.getHeight());
    Display display(&nonogram, &raster);
    Solver solver(&nonogram, &raster);
    
    bool solveColumns = true;
    bool changed;
    do {
        changed = false;
        if (solveColumns)
            changed |= solver.solveCols();
        else
            changed |= solver.solveRows();
        solveColumns = !solveColumns;
        display.show();
        getc(stdin);
    }
    while (changed);
#if defined(_WIN32)
    getc(stdin);
#endif
}

void error(const char *string)
{
    fprintf(stderr, "Error: %s\n", string);
    exit(1);
}

void dump(Nonogram *nonogram)
{
    std::vector<unsigned short>::iterator i;
    
    printf("Cols:\n");
    for (size_t x = 0; x < nonogram->getWidth(); x++)
    {
        printf("%2zu: ", nonogram->getColStrips(x).size());
        std::vector<unsigned short> strip = nonogram->getColStrips(x);
        for (i = strip.begin(); i != strip.end(); i++)
            printf("%2d ", *i);
        printf("\n");
    }
        
    printf("Rows:\n");
    for (size_t y = 0; y < nonogram->getHeight(); y++)
    {
        printf("%2zu: ", nonogram->getRowStrips(y).size());
        std::vector<unsigned short> strip = nonogram->getRowStrips(y);
        for (i = strip.begin(); i != strip.end(); i++)
            printf("%2d ", *i);
        printf("\n");
    }
}
