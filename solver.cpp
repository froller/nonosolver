#include "solver.h"
#include <stdio.h>

Solver::Solver(Nonogram *nonogram, Raster *raster): m_Nonogram(nonogram), m_Raster(raster)
{
    
}

void Solver::solve()
{
    bool changed = false;
    for (int x = 0; x < m_Nonogram->getWidth(); x++)
        changed |= analyzeLine(eLine_Column, x);

    for (int y = 0; y < m_Nonogram->getHeight(); y++)
        changed |= analyzeLine(eLine_Row, y);

}

bool Solver::analyzeLine(const eLine type, const unsigned short idx)
{
    bool changed = false;
    std::vector<char> line;
    std::vector<unsigned short> strips;
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
    
    changed |= findPersistantPixels(line, strips);
    copyLineToRaster(type, idx, line);
    
    // TODO: Find and set persistant pixels
    // TODO: Find and mark unreacheable pixes
    // TODO: Find and mark bound pixels
    
    return changed;
}

bool Solver::findPersistantPixels(std::vector<char>& line, std::vector<unsigned short>& strips)
{
    std::vector<char> leftmost(line.size());
    std::vector<char> rightmost(line.size());

    int pos;
   
    pos = 0;
    for (unsigned int i = 0; i < strips.size(); i++)
    {
        for (int j = 0; j < strips[i]; j++)
        {
            leftmost[pos++] = i + 1;
        }
        pos++;
    }
    
    pos = line.size() - 1;
    for (int i = strips.size(); i > 0; i--)
    {
        for (int j = 0; j < strips[i - 1]; j++)
            rightmost[pos--] = i;
        pos--;
    }

    bool changed = false;
    for (unsigned int i = 0; i < line.size(); i++)
        if (leftmost[i] && leftmost[i] == rightmost[i])
        {
            line[i] = leftmost[i];
            changed = true;
        }
    return changed;
}

bool Solver::copyLineToRaster(const eLine type, const unsigned short idx, std::vector<char> &line)
{
    bool changed = false;
    for (unsigned int i = 0; i < line.size(); i++)
        if (line[i])
        {
            if (type == eLine_Column)
                m_Raster->setPixel(idx, i, line[i]);
            else
                m_Raster->setPixel(i, idx, line[i]);
            changed = true;
        }
    return changed;
}
