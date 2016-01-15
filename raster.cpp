#include "raster.h"
#include <stdlib.h>
#include <string.h>

Raster::Raster(): m_Width(0), m_Height(0), m_Raster(nullptr)
{
    
}

Raster::Raster(const size_t width, const size_t height): m_Width(width), m_Height(height)
{
    m_Raster = static_cast<char *>(malloc(m_Width * m_Height));
    clear();
}

Raster::~Raster()
{
    if (m_Raster)
        free(m_Raster);
}

char Raster::getPixel(const unsigned int x, const unsigned int y) const
{
    return m_Raster[pixelIndex(x, y)];
}

void Raster::setPixel(const unsigned int x, const unsigned int y, char p)
{
    m_Raster[pixelIndex(x, y)] = p;
}

unsigned int Raster::pixelIndex(const unsigned int x, const unsigned int y) const
{
    return y * m_Width + x;
}

std::vector<char> Raster::getCol(unsigned int x) const
{
    std::vector<char> column;
    for (unsigned int i = 0; i < m_Height; i++)
        column.push_back(getPixel(x, i));
    return column;
}

std::vector<char> Raster::getRow(unsigned int y) const
{
    std::vector<char> row;
    for (unsigned int i = 0; i < m_Width; i++)
        row.push_back(getPixel(i, y));
    return row;
}

void Raster::clear()
{
    memset(m_Raster, 0, m_Width * m_Height);
}
