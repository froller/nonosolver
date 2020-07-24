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
    bool findUnreachablePixels(std::vector<char> &line, std::vector<unsigned short> &strips);
    bool saveLineToRaster(const eLine type, const unsigned short idx, std::vector<char> &line);
    std::vector<char> loadLineFromRaster(const eLine type, const unsigned short idx);
public:
    Solver(Nonogram *nonogram, Raster *raster);
    bool solve();
    bool solveRows();
    bool solveCols();
};

#endif // __SOLVER_H__
