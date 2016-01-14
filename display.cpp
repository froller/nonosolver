#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Display::Display()
{

};

void Display::show(Nonogram &nonogram, Raster& raster) const
{
    size_t leftField = 0, topField = 0;
    for (size_t y = 0; y < nonogram.getHeight(); y++)
        leftField = std::max(leftField, nonogram.getRowStrips()[y].size());
    for (size_t x = 0; x < nonogram.getWidth(); x++)
        topField = std::max(topField, nonogram.getColStrips()[x].size());

    char *leftSpacer = static_cast<char *>(malloc(leftField * 2 + 1));
    memset(leftSpacer, ' ', leftField * 2);
    leftSpacer[leftField] = 0;
    
    for (size_t y = topField; y >= 0; y--)
    {
        printf(leftSpacer);
        for (size_t x = 0; x < nonogram.getWidth(); x++)
        {
            if (nonogram.getColStrips()[x].size() > 0)
                1;
        }
    }
        
    for (size_t y = 0; y < nonogram.getHeight(); y++)
    {
        for (size_t x = 0; x < nonogram.getWidth(); x++)
        {
            char block = ' ';
            switch (raster.getPixel(x, y)) {
                case  1:
                    printf("\033[1;48m  \033[0m");
                    break;
                case  0:
                    printf("\033[0;40m  \033[0m");
                    break;
                case -1:
                    printf("\033[1;30m><\033[0m");
                    break;
            }
        }
        printf("\n");
    }
};
