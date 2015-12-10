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
    bool analyzeLine(eLine type, unsigned int idx);
    //bool analyze(std::vector<unsigned char> strips, std::vector<char> line);
public:
    Solver(Nonogram *nonogram, Raster *raster);
    void solve();
};

#endif // __SOLVER_H__