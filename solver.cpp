#include "solver.h"

Solver::Solver(Nonogram *nonogram, Raster *raster): m_Nonogram(nonogram), m_Raster(raster)
{
    
}

void Solver::solve()
{
    
}

bool Solver::analyzeLine(eLine type, unsigned int idx)
{
    bool changed = false;
    std::vector<char> line;
    std::vector<unsigned char> strips;
    unsigned int x, y;
    switch (type)
    {
    case eLine_Column:
        line = m_Raster->getCol(idx);
        strips = m_Nonogram->getColStrips(idx);
        x = idx;
        break;
    case eLine_Row:
        line = m_Raster->getRow(idx);
        strips = m_Nonogram->getRowStrips(idx);
        y = idx;
        break;
    }
    
    

    // TODO: Find and set persistant pixels
    // TODO: Find and mark unreacheable pixes
    // TODO: Find and mark bound pixels
    
    return changed;
}
