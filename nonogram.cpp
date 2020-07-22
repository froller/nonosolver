#include "nonogram.h"

Nonogram::Nonogram()
    : m_Width(0), m_Height(0), m_Strips({})
{

}

Nonogram::Nonogram(const unsigned short &width, const unsigned short &height, const std::vector<std::vector<unsigned short>> &strips)
    : m_Width(width), m_Height(height), m_Strips(strips)
{
        
}

std::vector<unsigned short> Nonogram::getRowStrips(unsigned short row) const
{
    if (row < m_Height)
        return m_Strips[row];
    else
        return {};
}

std::vector<unsigned short> Nonogram::getColStrips(unsigned short col) const
{
    if (col < m_Width)
        return m_Strips[m_Height + col];
    else
        return {};
}

unsigned short Nonogram::getWidth() const
{
    return m_Width;
}

unsigned short Nonogram::getHeight() const
{
    return m_Height;
}

void Nonogram::zero()
{
    m_Height = 0;
    m_Width = 0;
    m_Strips.clear();
}
