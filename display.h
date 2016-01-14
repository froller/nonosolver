#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "nonogram.h"
#include "raster.h"

class Display {
public:
    Display();
    void show(Nonogram &nonogram, Raster &raster) const;
};

#endif // __DISPLAY_H__