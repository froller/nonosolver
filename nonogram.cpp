#include "nonogram.h"

Nonogram::Nonogram()
    : m_Width(0), m_Height(0), m_Strips({})
{

}

Nonogram::Nonogram(const unsigned char &width, const unsigned char &height, const std::vector<std::vector<unsigned char>> &strips)
    : m_Width(width), m_Height(height), m_Strips(strips)
{
        
}

std::vector<unsigned char> Nonogram::getRowStrips(unsigned char row)
{
    if (row < m_Height)
        return m_Strips[row];
    else
        return {};
}

std::vector<unsigned char> Nonogram::getColStrips(unsigned char col)
{
    if (col < m_Width)
        return m_Strips[m_Height + col];
    else
        return {};
}

unsigned char Nonogram::getWidth()
{
    return m_Width;
}

unsigned char Nonogram::getHeight()
{
    return m_Height;
}

void Nonogram::zero()
{
    m_Height = 0;
    m_Width = 0;
    m_Strips.clear();
}