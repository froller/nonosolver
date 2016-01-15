#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Display::Display(Nonogram *nonogram, Raster *raster): m_Nonogram(nonogram), m_Raster(raster)
{
    clearScreen();
};

void Display::show() const
{
    setCursor(0, 0);
    
    size_t leftField = 0, topField = 0;
    for (int y = 0; y < m_Nonogram->getHeight(); y++)
        leftField = std::max(leftField, m_Nonogram->getRowStrips(y).size());
    for (int x = 0; x < m_Nonogram->getWidth(); x++)
        topField = std::max(topField, m_Nonogram->getColStrips(x).size());

    char *leftSpacer = static_cast<char *>(malloc(leftField * 2 + 1));
    memset(leftSpacer, ' ', leftField * 2);
    leftSpacer[leftField * 2] = 0;
    
    for (int y = topField; y > 0; --y)
    {
        printf(leftSpacer);
        for (int x = 0; x < m_Nonogram->getWidth(); x++)
        {
            if (m_Nonogram->getColStrips(x).size() >= y)
                printf("%2u", m_Nonogram->getColStrips(x)[m_Nonogram->getColStrips(x).size() - y]);
            else
                printf("  ");
        }
        printf("\n");
    }
    
    for (int y = 0; y < m_Nonogram->getHeight(); y++)
    {
        for (int x = leftField; x > 0; --x)
        {
            if (m_Nonogram->getRowStrips(y).size() >= x)
                printf("%2u", m_Nonogram->getRowStrips(y)[m_Nonogram->getRowStrips(y).size() - x]);
            else
                printf("  ");
                
        }
        for (int x = 0; x < m_Nonogram->getWidth(); x++)
        {
            switch (m_Raster->getPixel(x, y)) {
                case  1:
                    printf("\033[1;48m  \033[0m");
                    break;
                case  0:
                    printf("\033[0;47m  \033[0m");
                    break;
                case -1:
                    printf("\033[1;30m><\033[0m");
                    break;
            }
        }
        printf("\n");
    }
};

void Display::clearScreen()
{
    printf("\033[2J");
}

void Display::setCursor(unsigned int x, unsigned int y)
{
    printf("\033[%u;%uH", y + 1, x + 1);
}

