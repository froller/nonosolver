#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "nonogram.h"
#include "raster.h"

class Display {
    Nonogram *m_Nonogram;
    Raster *m_Raster;
public:
    Display(Nonogram *nonogram, Raster *raster);
    void show() const;
private:
    static void clearScreen();
    static void setCursor(unsigned int x, unsigned int y);
};

#endif // __DISPLAY_H__