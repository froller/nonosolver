#include "nonogram.h"

Nonogram::Nonogram()
    : m_Width(0), m_Height(0), m_Strips({})
{

}

Nonogram::Nonogram(const int &width, const int &height, const std::vector<std::vector<unsigned char>> &strips)
    : m_Width(width), m_Height(height), m_Strips(strips)
{
        
}

std::vector<unsigned char> Nonogram::getRowStrips(unsigned int row) const
{
    if (row < m_Height)
        return m_Strips[row];
    else
        return {};
}

std::vector<unsigned char> Nonogram::getColStrips(unsigned int col) const
{
    if (col < m_Width)
        return m_Strips[m_Height + col];
    else
        return {};
}

int Nonogram::getWidth() const
{
    return m_Width;
}

int Nonogram::getHeight() const
{
    return m_Height;
}

void Nonogram::zero()
{
    m_Height = 0;
    m_Width = 0;
    m_Strips.clear();
}
