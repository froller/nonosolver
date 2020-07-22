#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#if defined(_WIN32)
#   define NOMINMAX
#   include <windows.h>
#endif

Display::Display(Nonogram *nonogram, Raster *raster): m_Nonogram(nonogram), m_Raster(raster)
{
    clearScreen();
}

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
        puts(leftSpacer);
        for (unsigned int x = 0; x < m_Nonogram->getWidth(); x++)
        {
            if (m_Nonogram->getColStrips(x).size() >= static_cast<unsigned short>(y))
                printf("%2u", m_Nonogram->getColStrips(x)[m_Nonogram->getColStrips(x).size() - y]);
            else
                puts("  ");
        }
        puts("\n");
    }
    
    for (unsigned int y = 0; y < m_Nonogram->getHeight(); y++)
    {
        for (unsigned int x = leftField; x > 0; --x)
        {
            if (m_Nonogram->getRowStrips(y).size() >= x)
                printf("%2u", m_Nonogram->getRowStrips(y)[m_Nonogram->getRowStrips(y).size() - x]);
            else
                puts("  ");
                
        }
        for (int x = 0; x < m_Nonogram->getWidth(); x++)
        {
            switch (m_Raster->getPixel(x, y)) {
                case  0:
#if defined(_WIN32)
                    puts(" +");
#else
                    puts("\033[0;30;47m +\033[0m");
#endif
                    break;
                case -1:
#if defined(_WIN32)
                    puts("><");
#else
                    puts("\033[0;30;47m><\033[0m");
#endif
                    break;
                default:
#if defined(_WIN32)
                    printf("%2i", m_Raster->getPixel(x, y));
#else
                    printf("\033[1;37;40m%2i\033[0m", m_Raster->getPixel(x, y));
#endif
            }
        }
        puts("\n");
    }
}

void Display::clearScreen()
{
#if defined(_WIN32)
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, ' ', cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
#else
    puts("\033[2J");
#endif
}

void Display::setCursor(unsigned int x, unsigned int y)
{
#if defined(_WIN32)
    COORD tl = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, tl);
#else
    printf("\033[%u;%uH", y + 1, x + 1);
#endif
}

