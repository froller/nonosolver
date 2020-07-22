#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "nonogram.h"
#include "raster.h"

typedef enum {
    eLine_Row,
    eLine_Column,
} eLine;

class Solver
{
    Nonogram *m_Nonogram;
    Raster *m_Raster;
    bool analyzeLine(const eLine type, const unsigned short idx);
    //bool analyze(std::vector<unsigned char> strips, std::vector<char> line);
    bool findPersistantPixels(std::vector<char> &line, std::vector<unsigned short> &strips);
    bool copyLineToRaster(const eLine type, const unsigned short idx, std::vector<char> &line);
public:
    Solver(Nonogram *nonogram, Raster *raster);
    void solve();
};

#endif // __SOLVER_H__
